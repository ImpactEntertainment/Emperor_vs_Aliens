#include "gameconfig.h"


GameConfig::GameConfig()
{

    exit 				 = false;
    levelSelected 		 = true;
    level 				 = LEVEL_01;
    difficulty 			 = GAME_HARD;
	levelEnabled[0] 	 = true;
	difficultyEnabled[0] = true;

	for(int i=1; i<12; i++)
		levelEnabled[i] = false;
	
	for(int i=1; i<3; i++)
		difficultyEnabled[i] = false;
}

void GameConfig::levelCleared()
{
	if(level == LEVEL_12)
    {
        if(difficulty != GAME_HARD)
        {
            difficulty = (Difficulty) (difficulty + 1);
            difficultyEnabled[difficulty+1] = true;
        }
    }
    else
    {
        level = (Level) (level + 1);
        levelEnabled[level+1] = true;
    }
}
