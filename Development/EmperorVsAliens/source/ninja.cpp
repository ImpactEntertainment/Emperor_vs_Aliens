#include "ninja.h"

Ninja::Ninja(Field *pos)
: EmperorUnit(pos)
{
	init();
	cost = NINJA_COST;
}

void Ninja::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_ninja.png");
}

void Ninja::loadBaseAttributes()
{
	backswingTime 		 = NINJA_BACKSWING_TIME;
	travelTime 		 	 = NINJA_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints = NINJA_BASE_HITPOINTS;
	attributes.damage	 = NINJA_BASE_DAMAGE;
	attributes.defense	 = NINJA_BASE_DEFENSE;
}

float Ninja::getMaxSpeedX()
{
    return NINJA_SPEED_X;
}

float Ninja::getMaxSpeedY()
{
    return NINJA_SPEED_Y;
}

float Ninja::getMaxSpeedXY()
{
    return NINJA_SPEED_XY;
}