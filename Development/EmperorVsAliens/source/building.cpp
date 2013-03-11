#include "building.h"

#include <iostream>
using namespace std;

Building::Building(int hp, int damageReduction)
: Element()
{	
	init();
	MAX_HITPOINTS	 = hp;
	HITPOINTS 		 = hp;
	DAMAGE_REDUCTION = damageReduction;
	destroyed 		 = false;
	frameCount 		 = 0;

	range.clear();
}

void Building::addRange(Field *field)
{
	range.push_back(field);
	field->goalBuilding = this;
}

void Building::loadRectangle()
{
	mResource.width	= 112;
	mResource.height= 784;
	mResource.x		= 0;
	mResource.y		= 0;
}

void Building::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/hiver.png");
}

void Building::update()
{
	//TODO: fazer mudar o frame a medida q toma dano
	frameCount = (int)((MAX_HITPOINTS - HITPOINTS)*10.0/(MAX_HITPOINTS)) % 10;
	mResource.x = mResource.width * frameCount;
	mResource.y = 0;
	
	if(destroyed)	 onDestruction();	
}

void Building::receiveDamage(int damage)
{
	HITPOINTS -= (damage * (100 - DAMAGE_REDUCTION)/100);
	if(HITPOINTS <= 0)
		destroyed = true;
}

void Building::onDestruction()
{
	list<Field*>::iterator it;
	for(it = range.begin(); it != range.end(); it++)
		(*it)->goalBuilding = 0;
}
