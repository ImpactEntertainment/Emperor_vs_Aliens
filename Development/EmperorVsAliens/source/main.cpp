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
    gameConfig.level = LEVEL_01;

    GUI *gui = GUIFactory::create_GUI(GUI_MAIN);

    do{
        try {
            gui->init(gameConfig);
            gui->loop();
            gui->close();
        }
        catch (Exception e) {
            cout << e.getMessage() << endl;
            return -1;
        }

        if(gameConfig.exit) break;
        
        Game &game = *(GameFactory::create_game(gameConfig.difficulty));

        try {
            game.init(gameConfig);
            game.loop();
        }
        catch (Exception e) {
            cout << e.getMessage() << endl;
            return -1;
        }

    }while(!gameConfig.exit);

    gui->shutdown();
    return 0;
}
