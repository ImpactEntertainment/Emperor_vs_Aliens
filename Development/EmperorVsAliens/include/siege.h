/* 
 * File:   siege.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef SIEGE_H
#define	SIEGE_H

#include "swarmunit.h"

#define SIEGE_BASE_HITPOINTS 	400
#define	SIEGE_BASE_DAMAGE		20
#define SIEGE_BASE_DEFENSE	50

#define SIEGE_TRAVEL_TIME		ONE_SECOND
#define SIEGE_BACKSWING_TIME	ONE_SECOND

#define SIEGE_SPEED_X         112.0/SIEGE_TRAVEL_TIME
#define SIEGE_SPEED_Y  		112.0/SIEGE_TRAVEL_TIME
#define SIEGE_SPEED_XY 		(112) // TODO: (sqrt(2) * 112)/SIEGE_TRAVEL_TIME

class Siege : public SwarmUnit {
public:
	void loadBaseAttributes();
	void loadImage();
	void loadRectangle();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Siege(Field *pos);
};



#endif	/* SIEGE_H */

