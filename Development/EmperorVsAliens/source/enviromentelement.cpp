#include "enviromentelement.h"

EnviromentElement::EnviromentElement(EnviromentElementType type, Field *pos)
: Element(pos), mType(type)
{
	init();
	if(pos)
	{
		mPosition->habitant = this;
		mPosition->locked = true;	
	}
}

void EnviromentElement::loadCherryTree()
{
	mResource.width		=(CHERRY_WIDTH);
	mResource.height	=(CHERRY_HEIGHT);
	mResource.x			=(CHERRY_OFFSET_X);
	mResource.y			=(CHERRY_OFFSET_Y);
}

void EnviromentElement::loadLargeRock01()
{
	mResource.width		=(LARGE_ROCK_01_WIDTH);
	mResource.height	=(LARGE_ROCK_01_HEIGHT);
	mResource.x			=(LARGE_ROCK_01_OFFSET_X);
	mResource.y			=(LARGE_ROCK_01_OFFSET_Y);
}

void EnviromentElement::loadLargeRock02()
{
	mResource.width		=(LARGE_ROCK_02_WIDTH);
	mResource.height	=(LARGE_ROCK_02_HEIGHT);
	mResource.x			=(LARGE_ROCK_02_OFFSET_X);
	mResource.y			=(LARGE_ROCK_02_OFFSET_Y);
}

void EnviromentElement::loadLargeRock03()
{
	mResource.width		=(LARGE_ROCK_03_WIDTH);
	mResource.height	=(LARGE_ROCK_03_HEIGHT);
	mResource.x			=(LARGE_ROCK_03_OFFSET_X);
	mResource.y			=(LARGE_ROCK_03_OFFSET_Y);
}

void EnviromentElement::loadSmallRock01()
{
	mResource.width		=(SMALL_ROCK_01_WIDTH);
	mResource.height	=(SMALL_ROCK_01_HEIGHT);
	mResource.x			=(SMALL_ROCK_01_OFFSET_X);
	mResource.y			=(SMALL_ROCK_01_OFFSET_Y);
}

void EnviromentElement::loadImage()
{
	image = Image::load("/opt/EmperorVsAliens/data/images/map_elements.png",mResource.x,mResource.y,mResource.width,mResource.height);
}

void EnviromentElement::loadRectangle()
{
	switch(mType)
	{
	case CHERRY_TREE: loadCherryTree();
	break;
	case LARGE_ROCK_01: loadLargeRock01();
	break;
	case LARGE_ROCK_02: loadLargeRock02();
	break;
	case LARGE_ROCK_03: loadLargeRock03();
	break;
	case SMALL_ROCK_01: loadSmallRock01();
	break;
	case BOTTOM_GRASS:
	break;
	}
}

