#include "configGUI.h"

void ConfigGUI::loadImage(){
    background = Image::load("/opt/EmperorVsAliens/data/images/ConfigMenu.png");
}

void ConfigGUI::loadSubmenus(){
}

void ConfigGUI::loadButtons(){
    addButton(290,180,132,26);
    addButton(435,180,132,26);
    addButton(583,180,132,26);
}

#include <iostream>
using namespace std;

void ConfigGUI::handleClick(int index){
    switch(index){
    case 0:
        if(gameConfig->difficultyEnabled[GAME_EASY])
            gameConfig->difficulty = GAME_EASY;
    break;
    case 1:
        if(gameConfig->difficultyEnabled[GAME_NORMAL])
            gameConfig->difficulty = GAME_NORMAL;
    break;
    case 2:
        if(gameConfig->difficultyEnabled[GAME_HARD])
            gameConfig->difficulty = GAME_HARD;
    default:
        beDone();
    break;
    }
}
