#include "siege.h"

Siege::Siege(Field *pos)
: SwarmUnit(pos)
{
	init();
}

void Siege::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_siege.png");
}

void Siege::loadRectangle()
{
	mResource.width = 130;
	mResource.height= 130;
	mResource.x     = 0;
	mResource.y 	= 0;
}

void Siege::loadBaseAttributes()
{
	backswingTime 		 = SIEGE_BACKSWING_TIME;
	travelTime 		 	 = SIEGE_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints     = SIEGE_BASE_HITPOINTS;
	attributes.damage	 = SIEGE_BASE_DAMAGE;
	attributes.defense	 = SIEGE_BASE_DEFENSE;
}

float Siege::getMaxSpeedX()
{
    return SIEGE_SPEED_X;
}

float Siege::getMaxSpeedY()
{
    return SIEGE_SPEED_Y;
}

float Siege::getMaxSpeedXY()
{
    return SIEGE_SPEED_XY;
}