#include "hud.h"

#include <iostream>
using namespace std;

HUD::HUD(Field *pos)
: Menu(pos)
{
    init(pos);
    loadButtons();
    frameCount = 0;
    option = NO_OPTION;
    mPosition = 0;
}

void HUD::update()
{
    //frameCount += frameCount < 7 ? 1 : 0;
	//mResource.x = mResource.width * frameCount; 
}

void HUD::loadRectangle()
{
	//mResource = NULL;
    mResource.width = 0;
    mResource.height= 0;
    mResource.x     = 0;
    mResource.y     = 0;   
}

void HUD::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/InGameMenu.png");
}

void HUD::loadButtons()
{
    int boardPositionX = 134,
        boardPositionY = 409,
        fieldSize      = 112;
	int x = (mPosition->x)*fieldSize + boardPositionX - (mResource.width -fieldSize);//(mPosition->x - boardPositionX)/fieldSize;
	int y = (mPosition->y)*fieldSize + boardPositionY - (mResource.height-fieldSize/2);//(mPosition->y - boardPositionY)/fieldSize;
	addButton( 3+x,58+y,39,35); //togglepause
    addButton(12+x,14+y,39,35); //toggleFastForward
    addButton(58+x,14+y,39,35); //callNextWave
}

bool HUD::handleClick(int index)
{
    switch(index)
    {
    case 0:
        option = OPTION_01; 
    break; 
    case 1:
        option = OPTION_02; 
    break;
    case 2:
        option = OPTION_03; 
    break;
    default:
        option = NO_OPTION;
        return false;
    break;
    }
    return true;
}
