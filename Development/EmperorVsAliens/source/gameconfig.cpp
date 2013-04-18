#include "gameconfig.h"


GameConfig::GameConfig()
{
    for(int dif=0; dif<3; dif++)
       for(int stage=0; stage<12; stage++)
       {
            difficultyEnabled[dif] = false;
            levelEnabled[dif][stage] = false;
       }

    exit 				 = false;
    levelSelected 		 = true;
    level 				 = LEVEL_01;
    difficulty 			 = GAME_EASY;
	levelEnabled[0][0] 	 = true;
	difficultyEnabled[0] = true;    
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
        levelEnabled[difficulty][level+1] = true;
    }
}
