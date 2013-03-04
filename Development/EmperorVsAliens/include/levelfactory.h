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

class LevelFactory {
public:
    static Map *create_level(Level choice);
};

#endif

