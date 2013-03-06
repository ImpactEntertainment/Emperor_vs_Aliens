#include <iostream>

#include "game.h"
#include "windowfactory.h"
#include "point.h"

using namespace std;

namespace edge
{
    Game::Game()
    {
        video = NULL;
        window = NULL;
    }

    void
    Game::init(GameConfig& config) throw (Exception)
    {
        initVideo();
        initWindow();
        
        gameConfig = &config;
        eva.init(config.level);
        
        WAVES_LEFT      = eva.board->getWavesLeft();
		QUIT            = false;
        toggledFastForward  = false;
        toggledPause        = false;
        selected        = 0;
		allFrameCount   = -1;
        menu = 0;
        Timer::start();

        timeForNextWave = Timer::get_ticks() + WAVE_COOLDOWN;

    }

    void
    Game::loop() throw (Exception)
    {
        // 1. Atualizar time step
		allFrameCount++;

        // 2. Inputs
        SDL_Event event;
        bool quitGame = false;
        bool menuHandled = false;

        while (quitGame == false) {

            if(toggledFastForward)
            {
                toggledFastForward = false;
                Timer::toggleFastForward();
            }
            if(toggledPause)
            {
                toggledPause = false;
                Timer::togglePause();
            }
            Timer::set_currentFrameTick();

            gameBehaviour();
            if(Timer::get_currentFrameTick() >= timeForNextWave)
                callNextWave();

            while (SDL_PollEvent(&event)) {

                switch (event.type) {
                case SDL_QUIT:
                    quitGame = true;
                    gameConfig->exit = true;
                    break;		
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quitGame = true;
                        break;
					case SDLK_SPACE:
						togglePause();
						break;	
                    case SDLK_f:
                        toggleFastForward();
                        break;    
                    case SDLK_p:
                        togglePause();
                        break;    
                    case SDLK_x:
                        callNextWave();
                        break;  
                    case SDLK_k:
                        eva.killSwarm();
                        break;
                    default:
                        //eva.board->handleKeyboardEvent(&event.key);
                    	break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(menu)
                    {
                        menuHandled = menu->handleMouseEvent(event.button);
                    }
                    if(!menuHandled)
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                            selected = eva.select(event.button.x,event.button.y);
                        if(event.button.button == SDL_BUTTON_RIGHT && selected)
                        {
                            Field *oldSelected = selected;
                            selected = eva.select(event.button.x,event.button.y);
                            eva.moveTo(oldSelected,selected);
                            selected = NULL;
                        }
                        if(selected)
                        {
                            menu = new Menu(selected);
                            cout << "SELECTED ";                        
                            if(selected->habitant)
                                cout << "SKILL MENU" << endl;
                            else
                                cout << "UNIT MENU" << endl;
                        }
                        else
                        {
                            if(menu) menu->close();
                            menu = 0;
                        }
                    }
                    else
                    {
                        if(!menu->mPosition->habitant || !menu->mPosition->locked)
                            eva.emperorUnits.push_back(UnitFactory::create_unit((Class)menu->option,menu->mPosition));
                    }
                    break;
                default:
                    break;
                }
            }

            // 3. Rodar IA
			eva.IA();
            // 4. Rodar simulações de física
            // 5. Atualizar entidades do jogo
			eva.update();
            if(menu) menu->update();

            if(Timer::get_currentFrameTick() > RESOURCES_COOLDOWN){
                eva.increaseResources();
                RESOURCES_COOLDOWN = Timer::get_currentFrameTick() + THREE_SECONDS;
            }
            // 6. Enviar/receber mensagens da rede
            // 7. Atualizar o estado do jogo (display)
            eva.draw(window->getCanvas());
            if(menu) window->getCanvas()->drawMenu(*menu);

            window->getCanvas()->update();

            if(eva.isMainBuildingDestroyed()) 
            {
                cout << "LOSE" << endl;
                quitGame = true;
            }
            if(eva.noMoreEnemies()){
                cout << "WIN" << endl;
                quitGame = true;
            }

            int ticksElapsed = Timer::get_ticks() - Timer::get_currentFrameTick();
            int delayTime = ( 1000 / FRAMES_PER_SECOND ) - ticksElapsed;
            SDL_Delay( delayTime > 0 ? delayTime : 0);
        }


    }
    
    void
    Game::shutdown()
    {
        if (video && video->isUp()) {
            video->shutdown();
            delete video;
        }
        if (window) {
            delete window;
        }

        eva.shutdown();
    }

    void
    Game::initVideo() throw (Exception)
    {
        VideoSettings videoSettings;
        videoSettings.videoBufferLocation = VIDEO_MEMORY;
        videoSettings.machineArchitecture = MULTI_CORE;

        video = Video::getInstance();
        video->init();
        video->changeSettings(videoSettings);
    }

    void
    Game::initWindow() throw (Exception)
    {
        WindowSettings ws;
        ws.width = 1920;
        ws.height= 1080;
        ws.presentationMode = WINDOW;
        ws.title = "EmperorVsAliens";
        
        window = WindowFactory::create(ws);
    }
    
    void Game::toggleFastForward()
    {
        toggledFastForward = true;
    }

    void Game::togglePause()
    {
        toggledPause = true;
    }

	void Game::callNextWave()
	{
		if (WAVES_LEFT > 0) 
		{
			WAVES_LEFT--;
            timeForNextWave = Timer::get_currentFrameTick() + WAVE_COOLDOWN;
			eva.callNextWave();
		}	
	}
}
