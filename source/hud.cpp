#include "hud.h"
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

HUD::HUD(){
    loadButtons();
    HUD::loadImage();
    loadDisplays();
    frameCount = 0;
    option = NO_OPTION;
    mPosition = 0;

    victoryInfo = string("Victory");
    defeatInfo = string("Defeat");
}

HUD::HUD(int* r, int* t, int* w)
: resource(r), time(t), wavesLeft(w){
    loadButtons();
    HUD::loadImage();
    loadDisplays();
    frameCount = 0;
    option = NO_OPTION;
    mPosition = 0;

    victoryInfo = string("Victory");
    defeatInfo = string("Defeat");
    victory.update();
    defeat.update();
}

void HUD::loadDisplays(){
    addDisplay(resourceDisplay,&resourceInfo,990,5,30,250,250,0);
    addDisplay(timeDisplay,&timeInfo,988,60,13,0,0,50);
    addDisplay(wavesLeftDisplay,&wavesLeftInfo,1005,80,30,127,0,0);

    addDisplay(victory,&victoryInfo,428,540,200,200,200,10);
    addDisplay(defeat,&defeatInfo,540,540,200,255,0,0);
}

void HUD::addDisplay(Display& display, string* infoTracked, int x, int y, int size, int r, int g, int b){
    display.init(size);
    display.infoDisplayed = infoTracked;
    display.position.x = x;
    display.position.y = y;
    display.color.red = r;
    display.color.green = g;
    display.color.blue = b;
    //displays.push_back(new Display(infoTracked,x,y,size,r,g,b));

}

void HUD::update(){
    //cout << "resource: " << *resource << endl;
    //cout << "time: " << printTime() << endl;
    updateTime();
    updateResource();
    updateWavesLeft();
    timeDisplay.update();
    resourceDisplay.update();
    wavesLeftDisplay.update();
}

void HUD::updateTime(){
   stringstream ss;
   if(*time <= 0)
    ss << "00'000";
   else 
    ss << setfill('0') << setw(2) << ((*time)/1000) << "'" << setfill('0') << setw(3) << ((*time)%1000);
    
   timeInfo = ss.str();
}

void HUD::updateResource(){
   stringstream ss;

   ss << setfill('0') << setw(2) << *resource;
    
   resourceInfo = ss.str();
}
void HUD::updateWavesLeft(){
   stringstream ss;
   ss << *wavesLeft;
   wavesLeftInfo = ss.str();
}

void HUD::loadRectangle(){
	//mResource = NULL;
    mResource.width = 0;
    mResource.height= 0;
    mResource.x     = 0;
    mResource.y     = 0;   
}

void HUD::loadImage(){
    image = Image::load("/opt/EmperorVsAliens/data/images/InGameHUD.png");
}

void HUD::loadButtons(){
    addButton(1104,12,38,38); //togglepause
    addButton(1162,12,38,38); //toggleFastForward
    addButton(1218,12,38,38); //callNextWave
}

bool HUD::handleClick(int index){
    switch(index){
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
