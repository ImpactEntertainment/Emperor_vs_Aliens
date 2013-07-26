#include "gui.h"
#include "windowfactory.h"
#include <iostream>
using namespace std;

GUI::GUI(){
    video = NULL;
    window = NULL;
}

void GUI::init(GameConfig& config) throw (Exception){
    initVideo();
    initWindow();
    loadImage();
    loadButtons();
    loadSubmenus();
    Timer::start();
    done = false;
    gameConfig = &config;
}

void GUI::openSubmenu(int index){
    if(submenus.size()){
        try {
            submenus[index]->init(*gameConfig);
            submenus[index]->loop();
            submenus[index]->close();
        }
        catch (Exception e) {
            cout << e.getMessage() << endl;
            return;
        }
    }
    else{
        //cout << "Nenhum submenu carrregado" << endl;
    }
}

void GUI::addButton(int x, int y, int w, int h){
    buttons.push_back(new Button(x,y,w,h));
    buttons.back()->index = buttons.size()-1;
}

void GUI::addSubmenu(GUI* submenu){
    submenus.push_back(submenu);
}


bool GUI::click(Button& area){
    return ( ( (clicked.x > area.x) && (clicked.x < area.x + area.width) ) && ( (clicked.y > area.y) && (clicked.y < area.y + area.height) ) );
}

void GUI::handleMouseEvent(SDL_MouseButtonEvent &event){

    int  buttonIndex = -1;

    if(event.button == SDL_BUTTON_LEFT){
        clicked.x = event.x;
        clicked.y = event.y;
    }

    if(buttons.size()){
        vector<Button*>::iterator it;
        for(it = buttons.begin(); it != buttons.end(); it++)
            if( click( *(*it) ) )
                buttonIndex = (*it)->index;
        if(buttonIndex != -1) handleClick(buttonIndex);
    }
    else{
        //cout << "not button to click" << endl;
    }
}

void GUI::loop() throw (Exception){
    SDL_Event event;

    while (!done && !gameConfig->exit) {       

        Timer::set_currentFrameTick();
        clicked.x = 0;
        clicked.y = 0;

        while (SDL_PollEvent(&event)) {

            switch (event.type) {
            case SDL_QUIT:
                done = true;
                gameConfig->exit = true;
                break;		
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    beDone();
                    break;
				/*case SDLK_s:
					toggleFastForward();
					break;    
                case SDLK_c:
                    callNextWave();
                    break;  
                case SDLK_x:
                    eva.killSwarm();
                    break;
                */
                default:
                    //eva.board->handleKeyboardEvent(&event.key);
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleMouseEvent(event.button);
                break;
            default:
                break;
            }
        }

        window->getCanvas()->drawImage(background); 
        window->getCanvas()->update();

        int ticksElapsed = Timer::get_ticks() - Timer::get_currentFrameTick();
        int delayTime = ( 1000 / FRAMES_PER_SECOND ) - ticksElapsed;
        SDL_Delay( delayTime > 0 ? delayTime : 0);
    }
}

void GUI::close(){
    buttons.clear();
    submenus.clear();
}

void GUI::shutdown(){
    if (window) {
        delete window;
    }

    close();
}


void GUI::die(){
    if (video && video->isUp()) {
        video->shutdown();
        delete video;
    }
}

void GUI::initVideo() throw (Exception){
   VideoSettings videoSettings;
    videoSettings.videoBufferLocation = VIDEO_MEMORY;
    videoSettings.machineArchitecture = MULTI_CORE;

    video = Video::getInstance();
    video->init();
    video->changeSettings(videoSettings);
}

void GUI::initWindow() throw (Exception){
    WindowSettings ws;
    ws.width = 1920;
    ws.height= 1080;
    ws.presentationMode = FULLSCREEN;
    ws.title = "EmperorVsAliens";
        
    window = WindowFactory::create(ws);
}

void GUI::beDone(){
    done = true;
}
