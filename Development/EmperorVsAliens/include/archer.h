/* 
 * File:   archer.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef ARCHER_H
#define	ARCHER_H

#include "emperorunit.h"

#define ARCHER_BASE_HITPOINTS 100
#define	ARCHER_BASE_DAMAGE	40
#define ARCHER_BASE_DEFENSE	20

#define ARCHER_TRAVEL_TIME	ONE_SECOND
#define ARCHER_BACKSWING_TIME	ONE_SECOND

#define ARCHER_SPEED_X         112.0/ARCHER_TRAVEL_TIME
#define ARCHER_SPEED_Y  	112.0/ARCHER_TRAVEL_TIME
#define ARCHER_SPEED_XY 	(112) // TODO: (sqrt(2) * 112)/ARCHER_TRAVEL_TIME

#define ARCHER_COST		300

class Archer : public EmperorUnit {
public:
	void loadBaseAttributes();
	void loadImage();
        float getMaxSpeedX();
        float getMaxSpeedY();
        float getMaxSpeedXY();
	
	Archer(Field *pos);
};



#endif	/* ARCHER_H */

