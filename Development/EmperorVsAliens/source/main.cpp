/**
 * \file main.cpp
 * \brief Entrada do programa EmperorVsAliens.
 *
 * Módulo principal do jogo EmperorVsAliens, responsável para inicialização
 * dos componentes e do laço principal.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 26/12/2012
 */
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "gameconfig.h"
#include "windowfactory.h"
#include "canvas.h"
#include "boundingrectangle.h"
#include "gamefactory.h"
#include "GUIfactory.h"

using namespace std;
using namespace edge;
  Mix_Chunk *music = NULL;
  Mix_Chunk *music2 = NULL;

    void makeSound(){
       
	music = Mix_LoadWAV("/opt/EmperorVsAliens/data/sounds/sound_of_death.ogg");
	Mix_PlayChannel(-1,music, -1);
    }
     void makeSound2(){
        
        
	music2 = Mix_LoadWAV("/opt/EmperorVsAliens/data/sounds/thunder/0.ogg");
	Mix_PlayChannel(-1,music2, 0);
    }


int main()
{

    GameConfig gameConfig;
    gameConfig.exit = false;
    gameConfig.levelSelected = true;
    gameConfig.level = LEVEL_01;
    gameConfig.difficulty = GAME_HARD;


    Game *game = 0; 
    GUI *gui = GUIFactory::create_GUI(GUI_MAIN);

    /*
    */
    do{
        try 
        {
            gui->init(gameConfig);
                    
                    Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 );
              makeSound();
              makeSound2();
       
            gui->loop();
            gui->shutdown();
        }
        catch (Exception e) {
            cout << e.getMessage() << endl;
            return -1;
        }
        Mix_FreeChunk(music);
        Mix_FreeChunk(music2);
        if(gameConfig.exit) break;

        game = (GameFactory::create_game(gameConfig.difficulty));
        try 
        {
            game->init(gameConfig);
            game->loop();
            game->shutdown();
        }
        catch (Exception e) {
            cout << e.getMessage() << endl;
            return -1;
        }
        game = 0;
    }while(!gameConfig.exit);
    return 0;
}

