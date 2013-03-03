#include "swarmunit.h"

SwarmUnit::SwarmUnit(Field *pos)
: Unit(pos)
{}

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
