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

#include "gameconfig.h"
#include "windowfactory.h"
#include "canvas.h"
#include "boundingrectangle.h"
#include "gamefactory.h"
#include "GUIfactory.h"

using namespace std;
using namespace edge;


int main()
{

    GameConfig gameConfig;
    gameConfig.exit = false;
    gameConfig.levelSelected = true;
    gameConfig.level = LEVEL_01;
    gameConfig.difficulty = GAME_NORMAL;


    Game *game = 0; 
    GUI *gui = GUIFactory::create_GUI(GUI_MAIN);

    do{
        
    /*
    */
        if(game)
        {
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
        }
        else
        {
            try {
                gui->init(gameConfig);
                gui->loop();
                gui->shutdown();
            }
            catch (Exception e) {
                cout << e.getMessage() << endl;
                return -1;
            }

            if(gameConfig.exit){
                //gui->shutdown();
                break;
            }
            game = (GameFactory::create_game(gameConfig.difficulty));
        }
    }while(!gameConfig.exit);

    game->shutdown();
    return 0;
}
