#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#define FRAMES_PER_SECOND   30

typedef enum Level {
    LEVEL_01,
    LEVEL_02,
    LEVEL_03,
    LEVEL_04,
    LEVEL_05,
    LEVEL_06,
    LEVEL_07,
    LEVEL_08,
    LEVEL_09,
    LEVEL_10,
    LEVEL_11,
    LEVEL_12
}Level;

typedef enum Difficulty {
    GAME_EASY,
    GAME_NORMAL,
    GAME_HARD
}Difficulty;

typedef struct GameConfig
{
    Difficulty      difficulty;
    Level           level;
    bool            levelSelected;
    bool            exit;
}GameConfig;

#endif