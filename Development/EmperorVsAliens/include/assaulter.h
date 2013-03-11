/* 
 * File:   assaulter.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef ASSAULTER_H
#define	ASSAULTER_H

#include "swarmunit.h"

#define ASSAULTER_BASE_HITPOINTS 	400
#define	ASSAULTER_BASE_DAMAGE		20
#define ASSAULTER_BASE_DEFENSE	50

#define ASSAULTER_TRAVEL_TIME		ONE_SECOND
#define ASSAULTER_BACKSWING_TIME	ONE_SECOND

#define ASSAULTER_SPEED_X         112.0/ASSAULTER_TRAVEL_TIME
#define ASSAULTER_SPEED_Y  		112.0/ASSAULTER_TRAVEL_TIME
#define ASSAULTER_SPEED_XY 		(112) // TODO: (sqrt(2) * 112)/ASSAULTER_TRAVEL_TIME

class Assaulter : public SwarmUnit {
public:
	void loadBaseAttributes();
	void loadImage();
	void loadRectangle();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Assaulter(Field *pos);
};



#endif	/* ASSAULTER_H */

