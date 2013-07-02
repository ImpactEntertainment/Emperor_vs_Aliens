#include "swarmunit.h"

#include <iostream>
using namespace std;

SwarmUnit::SwarmUnit(Field *pos)
: Unit(pos){
	buildingTarget = 0;
}

void SwarmUnit::loadRectangle(){
	mResource.width = 112;
	mResource.height= 112;
	mResource.x     = 0;
	mResource.y 	= 0;
}

void SwarmUnit::decision(){
	if(!(target && buildingTarget) && spawned) getTarget();
    if(!(target && buildingTarget)) {
		if(!path.empty())
		{
			if(!path.back()->locked)
			{
				if(!path.back()->habitant)						move();
				else if(path.back()->habitant->isAttackable())  interact((Unit*)path.back()->habitant);
		    }
		    else
		    {
		    	//anti-stuck
	    		path.clear();
	    	}
	    }
	    else createPath();
    }
}


void SwarmUnit::createPath(){
	Field *next = mPosition;
	while(next->path[WEST]){ 
		next = next->path[WEST];
		path.push_front(next);
	}
}

void SwarmUnit::move(){
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

void SwarmUnit::startAttack(Unit* newTarget){
	Unit::startAttack(newTarget);
	buildingTarget = NULL;
}

void SwarmUnit::startAttack(Building* newTarget){
	status = UNIT_ATTACKING;
	buildingTarget = newTarget;
	target = NULL;
}

void SwarmUnit::attack(){
	Unit::attack();
	
	if(buildingTarget){
		buildingTarget->receiveDamage(attributes.damage);
		if(buildingTarget->destroyed)
		{
			status = UNIT_IDLE;
			buildingTarget = NULL;
		}
	}
	else if(target){
		target->receiveDamage(attributes.damage);
		if(target->status == UNIT_DEAD)
		{
			status = UNIT_IDLE;
			target = NULL;
		}
	}
}

bool SwarmUnit::isAlien(){
	return true;
}

void SwarmUnit::getTarget(){
	if(mPosition->goalBuilding){
		if(!((Building *)mPosition->goalBuilding)->destroyed) startAttack((Building *)mPosition->goalBuilding);
		target = 0;
	}
	/*else if(mPosition){
	cout << "updated4 " << this << endl;
		for(int way = 0; (way < 8); way ++)
		{
	cout << "updated5" << this << endl;
			if(mPosition->path[way])
			{
	cout << "updated6 " << this << endl;
				if(mPosition->path[way]->habitant && !mPosition->path[way]->locked)
				{
	cout << mPosition->path[way]->habitant <<"updated7 " << this << endl;
	cout << mPosition->path[way]->habitant <<"updated7 " << this << endl;
	cout << mPosition->path[way]->habitant <<"updated7 " << this << endl;
					if(mPosition->path[way]->habitant->isAttackable())
					{
	cout << "updated8 " << this << endl;
						interact((Unit*)mPosition->path[way]->habitant);
						if(status == UNIT_ATTACKING) break;
					}
				}
			}
		}
	}
	cout << "updated9 " << this << endl;*/
	//TODO: checar se e uma posicao com "alvo de construcao objetivo" se nao procurar alvos ao redor...
	//cout << "Attacking wall!" << endl;
	//startAttack(this);
}
