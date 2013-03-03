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

#include "windowfactory.h"
#include "canvas.h"
#include "boundingrectangle.h"
#include "gamefactory.h"

using namespace std;
using namespace edge;

int main()
{
    Difficulty difficulty = GAME_EASY;
    Game &game = *(GameFactory::create_game(difficulty));

    try {
        game.init("");
        game.loop();
        game.shutdown();
    }
    catch (Exception e) {
        cout << e.getMessage() << endl;
        return -1;
    }
    
    return 0;
}