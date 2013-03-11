/**
 * \file unitfactory.h
 * \brief Classe que implementa o metodo fabrica para instanciar as diferentes unidades.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef UNIT_FACTORY_H
#define UNIT_FACTORY_H

#include "swarmunit.h"
#include "samurai.h"
#include "archer.h"
#include "monk.h"
#include "ninja.h"

typedef enum UnitClass{
    UNIT_EMPEROR_SAMURAI,
    UNIT_EMPEROR_ARCHER,
    UNIT_EMPEROR_MONK,
    UNIT_EMPEROR_NINJA,
    UNIT_SWARM_HIVER,
    UNIT_SWARM_ASSAULTER,
    UNIT_SWARM_FLYER,
    UNIT_SWARM_SIEGE
}UnitClass;

class UnitFactory {
public:
    static Unit *create_unit(UnitClass choice, Field *pos);
};

#endif

