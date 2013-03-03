#include "unitfactory.h"

Unit *UnitFactory::create_unit(Class choice, Field *pos)
{
    switch(choice)
    {   
    case UNIT_SWARM_HIVER:
        return new SwarmUnit(pos);
    break;
    default:
        return 0;
    break;
    }
}
