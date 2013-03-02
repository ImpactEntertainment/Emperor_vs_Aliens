#include "unit.h"
#include <algorithm>

#include <iostream>
using namespace std;

Unit::Unit(Field *pos)
: Element(pos), status(UNIT_IDLE)
{
	init();
	pos->habitant = this;
	spawned = false;
	decomposed = false;
	
	speed.x = 0;
	speed.y = 0;
	attackCooldown = false;

	attributes.hitpoints = UNIT_BASE_HITFieldS;
	attributes.damage	 = UNIT_BASE_DAMAGE;

	path.clear();
}

void Unit::spawn()
{
	if(!mPosition->habitant && !spawned)
	{
		spawned = true;
		mPosition->habitant = this;
	}
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

	if(frameCount == 7 && status == UNIT_MOVING) arrive();
	if(frameCount == 7 && attackCooldown)		 enableAttack();  
	if(frameCount == 7 && status == UNIT_DEAD)	 onDeath();	
}

void Unit::IA()
{
	switch(status)
	{
	case UNIT_DEAD:
	case UNIT_MOVING: break;
	case UNIT_IDLE:
		if(!mPosition->x){
			getTarget();
		}
		else if(!path.size()){
			createPath();
		}
		else{
			decision();
		}
	break;
	case UNIT_ATTACKING: 
		if(!attackCooldown) attack();
	break;
	default:
	break;
	}
}

void Unit::createPath()
{

	Field *next = mPosition->path[WEST];
	while(next)
	{ 
		path.push_front(next);
		next = next->path[WEST];
	}
}

void Unit::decision()
{
	Field *next = !path.empty() ? path.back() : 0;
	if(!next)
	{}
	else if(next->habitant){
    	startAttack((Unit *)next->habitant);
	}
	else if(!next->locked){
		next->locked = true;
    	move();
		next->locked = false;
	}
	else{
	}
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
	status = UNIT_IDLE;				
	speed.x = 0;
	speed.y = 0;
	mPosition = path.back();	
	mPosition->habitant = this;
	path.pop_back();
}

void Unit::onDeath()
{	
	cout << this << " Died and Decomposed" << endl;
	decomposed = true;
}

void Unit::enableAttack()
{
	attackCooldown = false;
}

void Unit::receiveDamage(int damage)
{
	attributes.hitpoints -= damage;
	if(attributes.hitpoints <= 0)
	{
		status = UNIT_DEAD;
		mPosition->habitant = NULL;		
	}
}

void Unit::attack()
{
	attackCooldown = true;
	target->receiveDamage(attributes.damage);
	if(target->status == UNIT_DEAD)
	{
		status = UNIT_IDLE;
		target = NULL;
	}
}

void Unit::startAttack(Unit* newTarget)
{
	status = UNIT_ATTACKING;
	target = newTarget;
}

void Unit::getTarget()
{
	//cout << "Attacking wall!" << endl;
	//startAttack(this);
}
