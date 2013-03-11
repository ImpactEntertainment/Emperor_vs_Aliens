/* 
 * File:   hiver.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef HIVER_H
#define	HIVER_H

#include "swarmunit.h"

#define HIVER_BASE_HITPOINTS 	400
#define	HIVER_BASE_DAMAGE		20
#define HIVER_BASE_DEFENSE	50

#define HIVER_TRAVEL_TIME		ONE_SECOND
#define HIVER_BACKSWING_TIME	ONE_SECOND

#define HIVER_SPEED_X         112.0/HIVER_TRAVEL_TIME
#define HIVER_SPEED_Y  		112.0/HIVER_TRAVEL_TIME
#define HIVER_SPEED_XY 		(112) // TODO: (sqrt(2) * 112)/HIVER_TRAVEL_TIME

class Hiver : public SwarmUnit {
public:
	void loadBaseAttributes();
	void loadImage();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Hiver(Field *pos);
};



#endif	/* HIVER_H */

