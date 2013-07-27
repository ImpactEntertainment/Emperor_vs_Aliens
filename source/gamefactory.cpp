#include "gamefactory.h"

Game *GameFactory::create_game(Difficulty choice){
    switch(choice){   
    case GAME_EASY:
        return new EasyGame;
    break;
    case GAME_NORMAL:
        return new NormalGame;
    break;
    case GAME_HARD:
        return new HardGame;
    break;
    default:
        return 0;
    break;
    }
}
