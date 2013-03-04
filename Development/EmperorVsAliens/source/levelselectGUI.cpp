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

void LevelSelectGUI::handleClick(int index)
{
    switch(index)
    {
    case 0:
        gameConfig->level = LEVEL_01;
    break;
    case 1:
        gameConfig->level = LEVEL_02;
    break;
    case 2:
        gameConfig->level = LEVEL_03;
    break;
    case 3:
        gameConfig->level = LEVEL_04;
    break;
    case 4:
        gameConfig->level = LEVEL_05;
    break;
    case 5:
        gameConfig->level = LEVEL_06;
    break;
    case 6:
        gameConfig->level = LEVEL_07;
    break;
    case 7:
        gameConfig->level = LEVEL_08;
    break;
    case 8:
        gameConfig->level = LEVEL_09;
    break;
    case 9:
        gameConfig->level = LEVEL_10;
    break;
    case 10:
        gameConfig->level = LEVEL_11;
    break;
    case 11:
        gameConfig->level = LEVEL_12;
    break;
    case 12:
        beDone();
        gameConfig->levelSelected = true;
    break;
    case 13:
        beDone();
    break;
    }
}
