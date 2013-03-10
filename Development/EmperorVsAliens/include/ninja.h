/* 
 * File:   ninja.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef NINJA_H
#define	NINJA_H

#include "emperorunit.h"

#define NINJA_BASE_HITPOINTS 	100
#define	NINJA_BASE_DAMAGE		100
#define NINJA_BASE_DEFENSE		20

#define NINJA_TRAVEL_TIME		ONE_SECOND/2
#define NINJA_BACKSWING_TIME	ONE_SECOND/2

#define NINJA_SPEED_X         	112.0/NINJA_TRAVEL_TIME
#define NINJA_SPEED_Y  		  	112.0/NINJA_TRAVEL_TIME
#define NINJA_SPEED_XY 		 	(112) // TODO: (sqrt(2) * 112)/NINJA_TRAVEL_TIME

#define NINJA_COST				100

class Ninja : public EmperorUnit {
public:
	void loadBaseAttributes();
	void loadImage();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Ninja(Field *pos);
};



#endif	/* NINJA_H */

