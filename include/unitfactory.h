/**
 * \file unitfactory.h
 * \brief Classe que implementa o metodo fabrica para instanciar as diferentes unidades.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef UNIT_FACTORY_H
#define UNIT_FACTORY_H

#include "samurai.h"
#include "archer.h"
#include "monk.h"
#include "ninja.h"
#include "hiver.h"
#include "assaulter.h"
#include "flyer.h"
#include "siege.h"

typedef enum Class{
    UNIT_EMPEROR_SAMURAI,
    UNIT_EMPEROR_ARCHER,
    UNIT_EMPEROR_MONK,
    UNIT_EMPEROR_NINJA,
    UNIT_SWARM_HIVER,
    UNIT_SWARM_FLYER,
    UNIT_SWARM_SIEGE,
    UNIT_SWARM_ASSAULTER
}Class;

class UnitFactory {
public:
    static Unit *create_unit(Class choice, Field *pos);
};

#endif

