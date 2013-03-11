// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef SWARM_UNIT_H
#define SWARM_UNIT_H

#include "unit.h"
#include "building.h"

class SwarmUnit : public Unit {
public:
	virtual void loadBaseAttributes()=0;
	virtual void loadImage()=0;
    virtual float getMaxSpeedX()=0;
    virtual float getMaxSpeedY()=0;
    virtual float getMaxSpeedXY()=0;

	virtual void createPath();
	virtual void move();
	virtual void getTarget();
	virtual void startAttack(Building* newTarget);
	virtual void startAttack(Unit* newTarget);
	virtual void attack();
	virtual	void decision();
	virtual void loadRectangle();

	bool isAlien();

	SwarmUnit(Field *pos);
	Building *buildingTarget;
};


#endif
