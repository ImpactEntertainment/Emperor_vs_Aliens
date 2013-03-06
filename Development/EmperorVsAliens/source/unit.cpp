#include "unit.h"
#include <algorithm>

#include <iostream>
using namespace std;

Unit::Unit(Field *pos)
: Element(pos), status(UNIT_IDLE)
{
	init();
	target = 0;
	markForDeath = false;
	spawned = false;
	decomposed = false;
	
	speed.x = 0;
	speed.y	= 0;

	attackCooldown	= false;
	
	path.clear();
}

bool Unit::spawn()
{
	if(!mPosition->habitant && !spawned)
	{
		spawned = true;
		mPosition->habitant = this;
		loadBaseAttributes();
		return true;
	}
	return false;
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
	if(!spawned) spawn();

	frameCount = (frameCount + 1) % 8;
	mResource.x = mResource.width * frameCount;
	mResource.y = mResource.height * status;

	if((ARRIVAL_TIME <= Timer::get_currentFrameTick()) && status == UNIT_MOVING)	arrive();
	if((ATTACK_READY_TIME <= Timer::get_currentFrameTick()) && attackCooldown)		enableAttack();  
	
	if(frameCount == 7 && status == UNIT_DEAD)	 onDeath();	
}

void Unit::IA()
{
	switch(status)
	{
	case UNIT_DEAD:
	case UNIT_MOVING: break;
	case UNIT_IDLE:
		if(markForDeath)
			status = UNIT_DEAD;
		else
			decision();
	break;
	case UNIT_ATTACKING: 
		if(!attackCooldown) attack();
	break;
	default:
	break;
	}
}

void Unit::decision()
{
	if(!path.size()) 
		createPath();
	else if(!path.back()->locked){
    	move();
	}
	//olhar em volta e interagir com os habitantes ao redor

	/*
	Field *next = !path.empty() ? path.back() : 0;

	if(!next)	
		getTarget();
	else if(next->habitant && next->habitant->isAttackable())
    	interact((Unit*)next->habitant);
	else if(!target && !next->locked){
		next->locked = true;
    	move();
	}
	else{
	}
	*/
}

void Unit::interact(Unit* unit)
{
	if(unit->isAlien() != this->isAlien())
		startAttack(unit);
}

void Unit::move()
{
	if(path.back()->locked  && path.back()->habitant) 
	{
		status = UNIT_IDLE;
		return;
	}
	path.back()->locked = true;
	ARRIVAL_TIME = Timer::get_currentFrameTick() + travelTime;
	mPosition->habitant = NULL;
	status = UNIT_MOVING;
}

void Unit::arrive()
{
	status = UNIT_IDLE;				
	speed.x = 0;
	speed.y = 0;
	mPosition = path.back();	
	mPosition->habitant = this;
	mPosition->locked = false;
	path.pop_back();
}

void Unit::onDeath()
{	
	mPosition->locked = false;
	decomposed = true;
}

void Unit::enableAttack()
{
	attackCooldown = false;
}

void Unit::receiveDamage(int damage)
{
	attributes.hitpoints -= (damage - attributes.defense);
	if(attributes.hitpoints <= 0)
	{
		status = UNIT_DEAD;
		mPosition->habitant = NULL;
	}
}

void Unit::attack()
{
	ATTACK_READY_TIME = Timer::get_currentFrameTick() + backswingTime;
	attackCooldown = true;
}

void Unit::startAttack(Unit* newTarget)
{
	status = UNIT_ATTACKING;
	target = newTarget;
}

bool Unit::isAttackable()
{
	return true;
}
