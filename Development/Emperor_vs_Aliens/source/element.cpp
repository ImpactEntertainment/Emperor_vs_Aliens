#include "element.h"

Element::Element(Point *pos)
: mPosition(pos)
{}

void Element::setPosition(Point *pos)
{ 
	mPosition = pos;
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

