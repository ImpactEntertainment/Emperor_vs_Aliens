// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef EMPEROR_UNIT_H
#define EMPEROR_UNIT_H

#include "unit.h"
#include "building.h"

#define EMPEROR_UNIT_BASE_HITPOINTS 100
#define	EMPEROR_UNIT_BASE_DAMAGE	40
#define EMPEROR_UNIT_BASE_DEFENSE	20

#define EMPEROR_UNIT_TRAVEL_TIME	ONE_SECOND
#define EMPEROR_UNIT_BACKSWING_TIME	ONE_SECOND

#define EMPEROR_UNIT_SPEED_X	112.0/EMPEROR_UNIT_TRAVEL_TIME
#define EMPEROR_UNIT_SPEED_Y  	112.0/EMPEROR_UNIT_TRAVEL_TIME
#define EMPEROR_UNIT_SPEED_XY 	(112) // TODO: (sqrt(2) * 112)/EMPEROR_UNIT_TRAVEL_TIME

class EmperorUnit : public Unit {
public:
	virtual void loadBaseAttributes();
	virtual void createPath();
	virtual void move();
	virtual void getTarget();
	virtual void attack();

	bool isAlien();

	Field *dest;
	EmperorUnit(Field *pos);
};


#endif
