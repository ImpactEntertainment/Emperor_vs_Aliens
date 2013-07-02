#include "menu.h"

#include <iostream>
using namespace std;

Menu::Menu(){}

Menu::Menu(Field *pos){
	init(pos);
	loadButtons();
	frameCount = 0;
    option = NO_OPTION;
}

void Menu::init(Field *pos){
    Element::init();
    mPosition = pos;
}

void Menu::init(){
    Element::init();
    mPosition = 0;
}

void Menu::update(){
    if(!mPosition) 
		frameCount = 0;
	else
		frameCount += frameCount < 7 ? 1 : 0;
	mResource.x = mResource.width * frameCount;    
}

void Menu::loadRectangle(){
	mResource.width	= 112;
	mResource.height= 112;
	mResource.x		= 0;
	mResource.y		= 0;
}

void Menu::loadImage(){
	image = Image::load("/opt/EmperorVsAliens/data/images/InGameMenu.png");
}

void Menu::loadButtons(){
    int boardPositionX = 134,
        boardPositionY = 409,
        fieldSize      = 112;
	int x = (mPosition->x)*fieldSize + boardPositionX - (mResource.width -fieldSize);//(mPosition->x - boardPositionX)/fieldSize;
	int y = (mPosition->y)*fieldSize + boardPositionY - (mResource.height-fieldSize/2);//(mPosition->y - boardPositionY)/fieldSize;
	addButton( 3+x,58+y,39,35);
    addButton(12+x,14+y,39,35);
    addButton(58+x,14+y,39,35);
    addButton(68+x,58+y,39,35);
}

bool Menu::handleClick(int index){
    if(mPosition->habitant)
        return false;

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
    case 3:
        option = OPTION_04; 
    break;
    default:
        option = NO_OPTION;
        return false;
    break;
    }
    return true;
}

void Menu::addButton(int x, int y, int w, int h){
    buttons.push_back(new Button(x,y,w,h));
    buttons.back()->index = buttons.size()-1;
}


bool Menu::click(Button& area){
    return ( ( (clicked.x > area.x) && (clicked.x < area.x + area.width) ) && ( (clicked.y > area.y) && (clicked.y < area.y + area.height) ) );
}

bool Menu::handleMouseEvent(SDL_MouseButtonEvent &event){
    int  buttonIndex = -1;

    if(event.button == SDL_BUTTON_LEFT)
    {
        clicked.x = event.x;
        clicked.y = event.y;
    }

    if(buttons.size())
    {
        vector<Button*>::iterator it;
        for(it = buttons.begin(); it != buttons.end(); it++)
            if( click( *(*it) ) )
                buttonIndex = (*it)->index;
        if(buttonIndex != -1)
        {
        	return handleClick(buttonIndex);
    	}
    }
    return false;
}

void Menu::close(){
    buttons.clear();
}
