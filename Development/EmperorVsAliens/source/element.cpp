#include "element.h"

Element::Element(int x, int y)
: mPosition(x,y)
{}

void Element::setPosition(int x, int y)
{ 
	mPosition.x = x;
	mPosition.y = y;
}

void Element::init()
{
	loadRectangle();
	loadImage();
}

void Element::shutdown()
{
    Image::release(image);
}

