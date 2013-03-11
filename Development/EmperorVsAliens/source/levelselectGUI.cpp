#include "levelselectGUI.h"

void LevelSelectGUI::loadImage()
{
    background = Image::load("/opt/EmperorVsAliens/data/images/LevelSelectMenu.png");
}

void LevelSelectGUI::loadSubmenus()
{
}

void LevelSelectGUI::loadButtons()
{
    addButton(78,508,25,25);
    addButton(125,457,25,25);
    addButton(209,443,25,25);
    addButton(287,430,25,25);
    addButton(340,389,25,25);
    addButton(387,336,25,25);
    addButton(495,295,25,25);
    addButton(578,321,25,25);
    addButton(637,294,25,25);
    addButton(687,308,25,25);
    addButton(721,348,25,25);
    addButton(713,403,25,25);


    addButton(666,169,120,42);
    addButton(666,209,120,42);
}

#include <iostream>
using namespace std;

void LevelSelectGUI::handleClick(int index)
{
    switch(index)
    {
    case 0:
        if(gameConfig->levelEnabled[LEVEL_01])
            gameConfig->level = LEVEL_01;
    break;
    case 1:
        if(gameConfig->levelEnabled[LEVEL_02])
            gameConfig->level = LEVEL_02;
    break;
    case 2:
        if(gameConfig->levelEnabled[LEVEL_03])
            gameConfig->level = LEVEL_03;
    break;
    case 3:
        if(gameConfig->levelEnabled[LEVEL_04])
            gameConfig->level = LEVEL_04;
    break;
    case 4:
        if(gameConfig->levelEnabled[LEVEL_05])
            gameConfig->level = LEVEL_05;
    break;
    case 5:
        if(gameConfig->levelEnabled[LEVEL_06])
            gameConfig->level = LEVEL_06;
    break;
    case 6:
        if(gameConfig->levelEnabled[LEVEL_07])
            gameConfig->level = LEVEL_07;
    break;
    case 7:
        if(gameConfig->levelEnabled[LEVEL_08])
            gameConfig->level = LEVEL_08;
    break;
    case 8:
        if(gameConfig->levelEnabled[LEVEL_09])
            gameConfig->level = LEVEL_09;
    break;
    case 9:
        if(gameConfig->levelEnabled[LEVEL_10])
            gameConfig->level = LEVEL_10;
    break;
    case 10:
        if(gameConfig->levelEnabled[LEVEL_11])
            gameConfig->level = LEVEL_11;
    break;
    case 11:
        if(gameConfig->levelEnabled[LEVEL_12])
            gameConfig->level = LEVEL_12;
    break;
    case 12:
        beDone();
        gameConfig->levelSelected = true;
    break;
    case 13:
        beDone();
        gameConfig->levelSelected = false;
    break;
    }
}
