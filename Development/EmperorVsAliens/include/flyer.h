/* 
 * File:   flyer.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef FLYER_H
#define	FLYER_H

#include "swarmunit.h"

#define FLYER_BASE_HITPOINTS 	400
#define	FLYER_BASE_DAMAGE		20
#define FLYER_BASE_DEFENSE	50

#define FLYER_TRAVEL_TIME		ONE_SECOND
#define FLYER_BACKSWING_TIME	ONE_SECOND

#define FLYER_SPEED_X         112.0/FLYER_TRAVEL_TIME
#define FLYER_SPEED_Y  		112.0/FLYER_TRAVEL_TIME
#define FLYER_SPEED_XY 		(112) // TODO: (sqrt(2) * 112)/FLYER_TRAVEL_TIME

class Flyer : public SwarmUnit {
public:
	void loadBaseAttributes();
	void loadImage();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Flyer(Field *pos);
};



#endif	/* FLYER_H */

