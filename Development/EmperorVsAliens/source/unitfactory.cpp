#include "unitfactory.h"

Unit *UnitFactory::create_unit(Class choice, Field *pos)
{
    switch(choice)
    {   
        case UNIT_EMPEROR_SAMURAI : 
		return new Samurai(pos);
	break;
	case UNIT_EMPEROR_ARCHER : 
		return new Samurai(pos);
	break;
	case UNIT_EMPEROR_MONK : 
		return new Samurai(pos);
	break;
	case UNIT_EMPEROR_NINJA : 
		return new Samurai(pos);
	break;
	case UNIT_SWARM_HIVER : 
		return new SwarmUnit(pos);
	break;
	case UNIT_SWARM_ASSAULTER : 
		return new SwarmUnit(pos);
	break;
	case UNIT_SWARM_FLYER : 
		return new SwarmUnit(pos);
	break;
	case UNIT_SWARM_SIEGE : 
		return new SwarmUnit(pos);
	break;
	default:
		return 0;
	break;
    }
}



