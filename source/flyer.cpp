#include "flyer.h"

Flyer::Flyer(Field *pos)
: SwarmUnit(pos){
	init();
}

void Flyer::loadImage(){
	image = Image::load("/opt/Emperor_vs_Aliens/data/images/sprite_sheet_flyer.png");
}

void Flyer::loadBaseAttributes(){
	backswingTime 		 = FLYER_BACKSWING_TIME;
	travelTime 		 	 = FLYER_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints     = FLYER_BASE_HITPOINTS;
	attributes.damage	 = FLYER_BASE_DAMAGE;
	attributes.defense	 = FLYER_BASE_DEFENSE;
}

float Flyer::getMaxSpeedX(){
    return FLYER_SPEED_X;
}

float Flyer::getMaxSpeedY(){
    return FLYER_SPEED_Y;
}

float Flyer::getMaxSpeedXY(){
    return FLYER_SPEED_XY;
}