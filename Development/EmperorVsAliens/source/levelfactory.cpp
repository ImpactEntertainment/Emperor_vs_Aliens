#include "levelfactory.h"

Map *LevelFactory::create_level(Level choice)
{
   	switch(choice)
    {   
    case LEVEL_01:
        return new Level_01;
    break;
    default:
        return 0;
    break;
    }
}
