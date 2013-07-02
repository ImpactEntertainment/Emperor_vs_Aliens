#include "hiver.h"

Hiver::Hiver(Field *pos)
: SwarmUnit(pos){
	init();
}

void Hiver::loadImage(){
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_hiver.png");
}

void Hiver::loadBaseAttributes(){
	backswingTime 		 = HIVER_BACKSWING_TIME;
	travelTime 		 	 = HIVER_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints     = HIVER_BASE_HITPOINTS;
	attributes.damage	 = HIVER_BASE_DAMAGE;
	attributes.defense	 = HIVER_BASE_DEFENSE;
}

float Hiver::getMaxSpeedX(){
    return HIVER_SPEED_X;
}

float Hiver::getMaxSpeedY(){
    return HIVER_SPEED_Y;
}

float Hiver::getMaxSpeedXY(){
    return HIVER_SPEED_XY;
}