/**
 * \file tictactoe.cpp
 * \brief Módulo principal do jogo TicTacToe.
 *
 * Módulo principal do jogo TicTacToe, responsável para inicialização
 * dos componentes e do laço principal.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 26/12/2012
 */
#include <iostream>
#include <SDL/SDL.h>

#include "windowfactory.h"
#include "canvas.h"
#include "boundingrectangle.h"
#include "game.h"

using namespace std;
using namespace edge;

int main()
{
    Game game;

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
