// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef EMPEROR_UNIT_H
#define EMPEROR_UNIT_H

#include "unit.h"
#include "building.h"

class EmperorUnit : public Unit {
public:
	virtual void loadBaseAttributes()=0;
	virtual void loadImage()=0;
        virtual float getMaxSpeedX()=0;
        virtual float getMaxSpeedY()=0;
        virtual float getMaxSpeedXY()=0;

	virtual void createPath();
	virtual void move();
	virtual void getTarget();
	virtual void attack();
	virtual void decision();

	
	void loadRectangle();
	bool isAlien();

	int cost;
	Field *destination;
	EmperorUnit(Field *pos);
};


#endif
