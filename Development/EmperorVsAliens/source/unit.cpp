#include "unit.h"
#include <algorithm>

Unit::Unit(Point *pos)
: Element(pos), status(UNIT_IDLE)
{
	speed.x = 0;
	speed.y = 0;
	attackCooldown = false;
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
	if(frameCount == 7 && attackCooldown)		 enableAttack();  
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
	case UNIT_ATTACKING: 
		if(!attackCooldown) attack();
	break;
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
	else if(next->habitant)
		startAttack((Unit *)next->habitant);
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

void Unit::arrive()
{
	mPosition = path[path.size()-1];	
	mPosition->habitant = this;
	status = UNIT_IDLE;				
	speed.x = 0;
	speed.y = 0;
	path.pop_back();
}

#include <iostream>
using namespace std;

void Unit::enableAttack()
{
	cout << "attack enabled" << endl;
	attackCooldown = false;
}

void Unit::attack()
{
	attackCooldown = true;
	cout << "attack done" << endl;
}

void Unit::startAttack(Unit* target)
{
	status = UNIT_ATTACKING;
	
	cout << this <<" Start Attacking! ->" << target << endl;
}

void Unit::getTarget()
{
	startAttack(NULL);
	cout << "Attacking wall!" << endl;
}
