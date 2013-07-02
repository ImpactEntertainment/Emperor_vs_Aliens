#include "unitfactory.h"

Unit *UnitFactory::create_unit(Class choice, Field *pos){
    switch(choice)
    {   
        case UNIT_EMPEROR_SAMURAI : 
		return new Samurai(pos);
	break;
	case UNIT_EMPEROR_ARCHER : 
		return new Archer(pos);
	break;
	case UNIT_EMPEROR_MONK : 
		return new Monk(pos);
	break;
	case UNIT_EMPEROR_NINJA : 
		return new Ninja(pos);
	break;
	case UNIT_SWARM_HIVER : 
		return new Hiver(pos);
	break;
	case UNIT_SWARM_ASSAULTER : 
		return new Assaulter(pos);
	break;
	case UNIT_SWARM_FLYER : 
		return new Flyer(pos);
	break;
	case UNIT_SWARM_SIEGE : 
		return new Siege(pos);
	break;
	default:
		return 0;
	break;
    }
}



