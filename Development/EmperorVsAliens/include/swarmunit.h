// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef SWARM_UNIT_H
#define SWARM_UNIT_H

#include "unit.h"
#include "building.h"

#define SWARM_UNIT_BASE_HITPOINTS 100
#define	SWARM_UNIT_BASE_DAMAGE	40
#define SWARM_UNIT_BASE_DEFENSE	20

#define SWARM_UNIT_TRAVEL_TIME	ONE_SECOND
#define SWARM_UNIT_BACKSWING_TIME	ONE_SECOND

#define SWARM_UNIT_SPEED_X	112.0/SWARM_UNIT_TRAVEL_TIME
#define SWARM_UNIT_SPEED_Y  112.0/SWARM_UNIT_TRAVEL_TIME
#define SWARM_UNIT_SPEED_XY (112) // TODO: (sqrt(2) * 112)/SWARM_UNIT_TRAVEL_TIME

class SwarmUnit : public Unit {
public:
	virtual void loadBaseAttributes();
	virtual void createPath();
	virtual void move();
	virtual void getTarget();
	virtual void startAttack(Building* newTarget);
	virtual void startAttack(Unit* newTarget);
	virtual void attack();
	virtual	void decision();
	virtual void loadImage();

	void loadRectangle();

	bool isAlien();

	SwarmUnit(Field *pos);
	Building *buildingTarget;
};


#endif
