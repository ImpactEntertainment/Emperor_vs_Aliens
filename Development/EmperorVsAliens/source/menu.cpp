#include "menu.h"

#include <iostream>
using namespace std;

Menu::Menu()
{
	init();
	frameCount = 0;
	timeForNextFrame = 0;
}

void Menu::update()
{
	if(!mPosition) 
		frameCount = 0;
	else
		frameCount += frameCount < 7 ? 1 : 0;
	mResource.x = mResource.width * frameCount;
}

void Menu::loadRectangle()
{
	mResource.width	= 112;
	mResource.height= 112;
	mResource.x		= 0;
	mResource.y		= 0;
}

void Menu::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/hiver.png",mResource.x,mResource.y,mResource.width,mResource.height);
}