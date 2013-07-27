/**
 * \file gamefactory.h
 * \brief Classe que implementa o metodo fabrica para criar jogos com dificuldades diferentes.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "easygame.h"
#include "normalgame.h"
#include "hardgame.h"

class GameFactory {
public:
    static Game *create_game(Difficulty choice);
};

#endif

