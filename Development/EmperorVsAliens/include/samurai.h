/* 
 * File:   samurai.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef SAMURAI_H
#define	SAMURAI_H

#include "emperorunit.h"

#define SAMURAI_BASE_HITPOINTS 100
#define	SAMURAI_BASE_DAMAGE	40
#define SAMURAI_BASE_DEFENSE	20

#define SAMURAI_TRAVEL_TIME	ONE_SECOND
#define SAMURAI_BACKSWING_TIME	ONE_SECOND

#define SAMURAI_SPEED_X         112.0/SAMURAI_TRAVEL_TIME
#define SAMURAI_SPEED_Y  	112.0/SAMURAI_TRAVEL_TIME
#define SAMURAI_SPEED_XY 	(112) // TODO: (sqrt(2) * 112)/SAMURAI_TRAVEL_TIME

#define SAMURAI_COST		300

class Samurai : public EmperorUnit {
public:
	void loadBaseAttributes();
	void loadImage();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Samurai(Field *pos);
};



#endif	/* SAMURAI_H */

