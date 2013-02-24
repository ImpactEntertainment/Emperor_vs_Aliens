#include "enviromentelement.h"

EnviromentElement::EnviromentElement(int x, int y)
: Element(x,y)
{}

void EnviromentElement::loadCherryTree()
{
	mWidth				=(CHERRY_WIDTH);
	mHeight				=(CHERRY_HEIGHT);
	mResourcePositionX	=(CHERRY_OFFSET_X);
	mResourcePositionY	=(CHERRY_OFFSET_Y);
}

void EnviromentElement::loadLargeRock01()
{
	mWidth				=(LARGE_ROCK_01_WIDTH);
	mHeight				=(LARGE_ROCK_01_HEIGHT);
	mResourcePositionX	=(LARGE_ROCK_01_OFFSET_X);
	mResourcePositionY	=(LARGE_ROCK_01_OFFSET_Y);
}

void EnviromentElement::loadLargeRock02()
{
	mWidth				=(LARGE_ROCK_02_WIDTH);
	mHeight				=(LARGE_ROCK_02_HEIGHT);
	mResourcePositionX	=(LARGE_ROCK_02_OFFSET_X);
	mResourcePositionY	=(LARGE_ROCK_02_OFFSET_Y);
}

void EnviromentElement::loadLargeRock03()
{
	mWidth				=(LARGE_ROCK_03_WIDTH);
	mHeight				=(LARGE_ROCK_03_HEIGHT);
	mResourcePositionX	=(LARGE_ROCK_03_OFFSET_X);
	mResourcePositionY	=(LARGE_ROCK_03_OFFSET_Y);
}

void EnviromentElement::loadSmallRock01()
{
	mWidth				=(SMALL_ROCK_01_WIDTH);
	mHeight				=(SMALL_ROCK_01_HEIGHT);
	mResourcePositionX	=(SMALL_ROCK_01_OFFSET_X);
	mResourcePositionY	=(SMALL_ROCK_01_OFFSET_Y);
}

