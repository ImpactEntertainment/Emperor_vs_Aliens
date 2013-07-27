/**
 * \file easygame.h
 * \brief Classe que varia o comportamento para um jogo na dificuldade facil.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef EASY_GAME_H
#define	EASY_GAME_H

#include "game.h"

class EasyGame : public Game {
public:
    void init(GameConfig& config);
    void gameBehaviour();
    void callNextWave();

    int timeToLive;

//private:
};

#endif

