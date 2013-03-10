#include "samurai.h"

Samurai::Samurai(Field *pos)
: EmperorUnit(pos)
{
	init();
	cost = SAMURAI_COST;
}

void Samurai::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_samurai.png");
}

void Samurai::loadBaseAttributes()
{
	backswingTime 		 = SAMURAI_BACKSWING_TIME;
	travelTime 		 = SAMURAI_TRAVEL_TIME;
	attributes.hitpoints     = SAMURAI_BASE_HITPOINTS;
	attributes.damage	 = SAMURAI_BASE_DAMAGE;
	attributes.defense	 = SAMURAI_BASE_DEFENSE;
}

float Samurai::getMaxSpeedX()
{
    return SAMURAI_SPEED_X;
}

float Samurai::getMaxSpeedY()
{
    return SAMURAI_SPEED_Y;
}

float Samurai::getMaxSpeedXY()
{
    return SAMURAI_SPEED_XY;
}