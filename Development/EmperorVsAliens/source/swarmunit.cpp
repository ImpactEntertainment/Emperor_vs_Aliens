#include "swarmunit.h"

#include <iostream>
using namespace std;

SwarmUnit::SwarmUnit(Field *pos)
: Unit(pos)
{
	buildingTarget = 0;
}


void SwarmUnit::loadBaseAttributes()
{
	backswingTime 		 = SWARM_UNIT_BACKSWING_TIME;
	travelTime 			 = SWARM_UNIT_TRAVEL_TIME;
	attributes.hitpoints = SWARM_UNIT_BASE_HITPOINTS;
	attributes.damage	 = SWARM_UNIT_BASE_DAMAGE;
	attributes.defense	 = SWARM_UNIT_BASE_DEFENSE;
}

void SwarmUnit::createPath()
{
	Field *next = mPosition;
	while(next)
	{ 
		next = next->path[WEST];
		path.push_front(next);
	}
}

void SwarmUnit::move()
{
	Unit::move();
	//TODO: verificar qual a direcao para atribuir valores corretos as velocidades
	speed.x = -SWARM_UNIT_SPEED_X;
	speed.y = 0;
}

void SwarmUnit::startAttack(Unit* newTarget)
{
	Unit::startAttack(newTarget);
	buildingTarget = NULL;
}

void SwarmUnit::startAttack(Building* newTarget)
{
	status = UNIT_ATTACKING;
	buildingTarget = newTarget;
	target = NULL;
}

void SwarmUnit::attack()
{
	Unit::attack();
	
	if(buildingTarget)
	{
		buildingTarget->receiveDamage(attributes.damage);
		if(buildingTarget->destroyed)
		{
			status = UNIT_IDLE;
			buildingTarget = NULL;
		}
	}
	else if(target)
	{
		target->receiveDamage(attributes.damage);
		if(target->status == UNIT_DEAD)
		{
			status = UNIT_IDLE;
			target = NULL;
		}
	}
}

bool SwarmUnit::isAlien()
{
	return true;
}

void SwarmUnit::getTarget()
{
	if(mPosition->goalBuilding){
		if(!((Building *)mPosition->goalBuilding)->destroyed) startAttack((Building *)mPosition->goalBuilding);
	}
	
	//TODO: checar se e uma posicao com "alvo de construcao objetivo" se nao procurar alvos ao redor...
	//cout << "Attacking wall!" << endl;
	//startAttack(this);
}
