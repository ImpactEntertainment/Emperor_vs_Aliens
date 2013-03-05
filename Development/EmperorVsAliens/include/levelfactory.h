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
#include "level_02.h"
#include "level_03.h"
#include "level_04.h"
#include "level_05.h"
#include "level_06.h"
#include "level_07.h"
#include "level_08.h"
#include "level_09.h"
#include "level_10.h"
#include "level_11.h"
#include "level_12.h"

class LevelFactory {
public:
    static Map *create_level(Level choice);
};

#endif

