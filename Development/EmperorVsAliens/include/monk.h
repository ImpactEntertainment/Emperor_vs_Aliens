/* 
 * File:   monk.h
 * Author: luis
 *
 * Created on 10 de Março de 2013, 13:04
 */

#ifndef MONK_H
#define	MONK_H

#include "emperorunit.h"

#define MONK_BASE_HITPOINTS 200
#define	MONK_BASE_DAMAGE	10
#define MONK_BASE_DEFENSE	30

#define MONK_TRAVEL_TIME	ONE_SECOND
#define MONK_BACKSWING_TIME	ONE_SECOND

#define MONK_SPEED_X         112.0/MONK_TRAVEL_TIME
#define MONK_SPEED_Y  		 112.0/MONK_TRAVEL_TIME
#define MONK_SPEED_XY 		 (112) // TODO: (sqrt(2) * 112)/MONK_TRAVEL_TIME

#define MONK_COST			 200

class Monk : public EmperorUnit {
public:
	void loadBaseAttributes();
	void loadImage();
    float getMaxSpeedX();
    float getMaxSpeedY();
    float getMaxSpeedXY();
	
	Monk(Field *pos);
};



#endif	/* MONK_H */

