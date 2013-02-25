#include "unit.h"

Unit::Unit(int x, int y)
: Element(x,y)
{
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
