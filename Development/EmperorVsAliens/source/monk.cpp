#include "monk.h"

Monk::Monk(Field *pos)
: EmperorUnit(pos)
{
	init();
	cost = MONK_COST;
}

void Monk::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_monk.png");
}

void Monk::loadBaseAttributes()
{
	backswingTime 		 = MONK_BACKSWING_TIME;
	travelTime 		 	 = MONK_TRAVEL_TIME;
	attributes.hitpoints = MONK_BASE_HITPOINTS;
	attributes.damage	 = MONK_BASE_DAMAGE;
	attributes.defense	 = MONK_BASE_DEFENSE;
}

float Monk::getMaxSpeedX()
{
    return MONK_SPEED_X;
}

float Monk::getMaxSpeedY()
{
    return MONK_SPEED_Y;
}

float Monk::getMaxSpeedXY()
{
    return MONK_SPEED_XY;
}