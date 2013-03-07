#include "hud.h"

#include <iostream>
using namespace std;

HUD::HUD()
{
    loadButtons();
    loadImage();
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
	image = Image::load("/opt/EmperorVsAliens/data/images/InGameHUD.png");
}

void HUD::loadButtons()
{
    addButton(1104,12,38,38); //togglepause
    addButton(1162,12,38,38); //toggleFastForward
    addButton(1218,12,38,38); //callNextWave
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
