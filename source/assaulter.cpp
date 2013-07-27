#include "assaulter.h"

Assaulter::Assaulter(Field *pos)
: SwarmUnit(pos){
	init();
}

void Assaulter::loadImage(){
	image = Image::load("/opt/Emperor_vs_Aliens/data/images/sprite_sheet_assaulter.png");
}

void Assaulter::loadRectangle(){
	mResource.width = 130;
	mResource.height= 130;
	mResource.x     = 0;
	mResource.y 	= 0;
}

void Assaulter::loadBaseAttributes(){
	backswingTime 		 = ASSAULTER_BACKSWING_TIME;
	travelTime 		 	 = ASSAULTER_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints     = ASSAULTER_BASE_HITPOINTS;
	attributes.damage	 = ASSAULTER_BASE_DAMAGE;
	attributes.defense	 = ASSAULTER_BASE_DEFENSE;
}

float Assaulter::getMaxSpeedX(){
    return ASSAULTER_SPEED_X;
}

float Assaulter::getMaxSpeedY(){
    return ASSAULTER_SPEED_Y;
}

float Assaulter::getMaxSpeedXY(){
    return ASSAULTER_SPEED_XY;
}