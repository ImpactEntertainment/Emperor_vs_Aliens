/**
 * \file levelfactory.h
 * \brief Classe que implementa o metodo fabrica para instanciar os diferentes mapas.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "level_01.h"

typedef enum Level {
    LEVEL_01,
    LEVEL_02,
    LEVEL_03,
    LEVEL_04,
    LEVEL_05,
    LEVEL_06,
    LEVEL_07,
    LEVEL_08,
    LEVEL_09,
    LEVEL_10,
    LEVEL_11,
    LEVEL_12
}Level;

class LevelFactory {
public:
    static Map *create_level(Level choice);
};

#endif

