#include "unit.h"
#include <algorithm>

Unit::Unit(Point *pos)
: status(UNIT_IDLE), Element(pos)
{
	speed.x = 0;
	speed.y = 0;
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
	image = Image::load("/opt/EmperorVsAliens/data/images/hiver.png",mResource.x,mResource.y,mResource.width,mResource.height);
}

void Unit::update()
{
	frameCount = (frameCount + 1) % 8;
	mResource.x = mResource.width * frameCount;
	mResource.y = mResource.height * status;

	if(frameCount == 7 && status == UNIT_MOVING) arrive();
}

void Unit::IA()
{
	switch(status)
	{
	case UNIT_MOVING: break;
	case UNIT_IDLE:
		if(!mPosition->x)
			getTarget();
		else if(!path.size())
			createPath();
		else
			decision();
	break;
	case UNIT_ATTACKING: break;
	}
}

void Unit::createPath()
{
	Point *next = mPosition->path[WEST];
	while(next)
	{ 
		path.push_back(next);
		next = next->path[WEST];
	}
	reverse(path.begin(),path.end());
}

void Unit::decision()
{
	Point *next = path.size() ? path[path.size()-1] : 0;
	if(!next)
	{}
	//else if(next->habitant)
	//	attack((Unit*) path.end()->habitant);
	else
		move();
}

void Unit::move()
{
	mPosition->habitant = NULL;
	status = UNIT_MOVING;
	speed.x = -SPEED_X;
	speed.y = 0;
}

#include <iostream>
using namespace std;

void Unit::arrive()
{
	mPosition = path[path.size()-1];	
	mPosition->habitant = this;
	status = UNIT_IDLE;				
	speed.x = 0;
	speed.y = 0;
	path.pop_back();
}

void Unit::attack(Unit* target)
{
	status = UNIT_ATTACKING;
	
	cout << this <<" Attacking! ->" << target << endl;
}

void Unit::getTarget()
{
	attack(NULL);
	cout << "Attacking wall!" << endl;
}
