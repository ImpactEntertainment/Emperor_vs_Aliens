/**
 * \file gameconfig.h
 * \brief Classe com as configuracoes do jogo.
 *
 * \author Luis Gustavo (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */

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

class GameConfig
{
public:
    Difficulty      difficulty;
    Level           level;
    bool            levelSelected;
    bool            exit;
    bool            levelEnabled[12];
    bool            difficultyEnabled[3];

    GameConfig();
    void levelCleared();
    void toggleLifebars();
};

#endif