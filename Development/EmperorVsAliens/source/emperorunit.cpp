#include "emperorunit.h"

#include <iostream>
using namespace std;

EmperorUnit::EmperorUnit(Field *pos)
: Unit(pos){
	destination = NULL;
}

void EmperorUnit::loadRectangle(){
	mResource.width = 112;
	mResource.height= 112;
	mResource.x     = 0;
	mResource.y 	= 0;
}

void EmperorUnit::getTarget(){
	for(int way = 0; (way < 8); way ++)
		if(mPosition->path[way])
			if(mPosition->path[way]->habitant && !mPosition->path[way]->locked)
				if(mPosition->path[way]->habitant->isAttackable())
				{
					interact((Unit*)mPosition->path[way]->habitant);
					if(status == UNIT_ATTACKING) break;
				}
}

void EmperorUnit::decision(){
	if(!path.empty()){
		if(!path.back()->locked)
		{
			if(!path.back()->habitant)						move();
			else if(path.back()->habitant->isAttackable())  interact((Unit*)path.back()->habitant);
	    }
	    else
	    {
	    	//anti-stuck
    		path.clear();
    		getTarget();
    	}
    }
	else if(destination) {
		createPath();
	}
	else if(!target) {
		getTarget();
	}
	else {
		interact(target);
	}
}

void EmperorUnit::createPath(){
	if(!destination) return;
	int difX = mPosition->x - destination->x;
	int difY = mPosition->y - destination->y;
	Field *next = mPosition;

	if(difY > 0){
		for(int y = 0; y < difY ; y++)
		{
			next = next->path[NORTH];
			path.push_front(next);
		}
	}
	else if(difY < 0){
		for(int y = 0; y > difY ; y--)
		{
			next = next->path[SOUTH];
			path.push_front(next);
		}
	}
	if(difX < 0){
		next = next ? next->path[EAST] : mPosition->path[EAST];
		for(int x = 0; x < abs(difX) ; x++)
		{
			path.push_front(next);
			next = next->path[EAST];
		}
	}
	else if(difX > 0){
		next = next ? next->path[WEST] : mPosition->path[WEST];
		for(int x = 0; x > -difX ; x--)
		{
			path.push_front(next);
			next = next->path[WEST];
		}
	}
	destination = NULL;
}

void EmperorUnit::move(){
	Unit::move();
	//TODO: verificar qual a direcao para atribuir valores corretos as velocidades
	if(path.back() == mPosition->path[NORTHWEST]){
		speed.x = -getMaxSpeedXY();
		speed.y = -getMaxSpeedXY();
	}
	else if(path.back() == mPosition->path[NORTH]){
		speed.x = 0;
		speed.y = -getMaxSpeedY();
	}
	else if(path.back() == mPosition->path[NORTHEAST]){
		speed.x = -getMaxSpeedXY();
		speed.y = getMaxSpeedXY();
	}
	else if(path.back() == mPosition->path[WEST]){
		speed.x = -getMaxSpeedX();
		speed.y = 0;
	}
	else if(path.back() == mPosition->path[EAST]){
		speed.x = getMaxSpeedX();
		speed.y = 0;
	}
	else if(path.back() == mPosition->path[SOUTHWEST]){
		speed.x = -getMaxSpeedXY();
		speed.y = getMaxSpeedXY();
	}
	else if(path.back() == mPosition->path[SOUTH]){
		speed.x = 0;
		speed.y = getMaxSpeedY();
	}
	else if(path.back() == mPosition->path[SOUTHEAST]){
		speed.x = getMaxSpeedXY();
		speed.y = getMaxSpeedXY();
	}
	else{}
}

void EmperorUnit::attack(){
	Unit::attack();
	
	target->receiveDamage(attributes.damage);
	if(target->status == UNIT_DEAD){
		status = UNIT_IDLE;
		target = NULL;
	}
}

bool EmperorUnit::isAlien(){
	return false;
}