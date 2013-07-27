#include "levelfactory.h"

Map *LevelFactory::create_level(Level choice){
   	switch(choice){   
    case LEVEL_01:
        return new Level_01;
    break;
	case LEVEL_02:
		return new Level_02; 
	break;    
	case LEVEL_03:
		return new Level_03; 
	break;   
	case LEVEL_04:
		return new Level_04; 
	break;
	case LEVEL_05:
		return new Level_05; 
	break;
	case LEVEL_06:
		return new Level_06; 
	break;
	case LEVEL_07:
		return new Level_07; 
	break;
	case LEVEL_08:
		return new Level_08; 
	break;
	case LEVEL_09:
		return new Level_09; 
	break;
	case LEVEL_10:
		return new Level_10; 
	break;
	case LEVEL_11:
		return new Level_11; 
	break;
	case LEVEL_12:
		return new Level_12; 
	break;    
    
    default:
        return 0;
    break;
    }
}



		
		
		
		
		
		
		
		
		
		
		















