#include "unit.h"

Unit::Unit(Point position)
: status(UNIT_IDLE)
{
	speed.x = 0;
	speed.y = 0;
	mPosition = position;
	init();
}


void Unit::loadRectangle()
{
	mResource.width	= 112;
	mResource.height= 112;
	mResource.x		= 0;
	mResource.y		= 0;
}

void Unit::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/resources/hiver.png",mResource.x,mResource.y,mResource.width,mResource.height);
}

void Unit::update()
{
	frameCount = (frameCount + 1) % 8;
	mResource.x = mResource.width * frameCount;
	mResource.y = mResource.height * status;
}

void Unit::IA()
{
	switch(status)
	{
	case UNIT_MOVING: break;
	case UNIT_IDLE: break;
	}
}
