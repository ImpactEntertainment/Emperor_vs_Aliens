/**
 * \file gamefactory.h
 * \brief Classe que implementa o metodo fabrica para criar jogos com dificuldades diferentes.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \author Edson Alves (edsonalves@unb.br)
 * \date 25/01/2012
 */
#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "easygame.h"
#include "normalgame.h"
#include "hardgame.h"

typedef enum Difficulty {
    GAME_EASY,
    GAME_NORMAL,
    GAME_HARD
}Difficulty;

class GameFactory {
public:
    static Game *create_game(Difficulty choice);
};

#endif

