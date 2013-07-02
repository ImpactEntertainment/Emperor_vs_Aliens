#include "archer.h"

Archer::Archer(Field *pos)
: EmperorUnit(pos){
	init();
	cost = ARCHER_COST;
}

void Archer::loadImage(){
	image = Image::load("/opt/EmperorVsAliens/data/images/sprite_sheet_archer.png");
}

void Archer::loadBaseAttributes(){
	backswingTime 		 = ARCHER_BACKSWING_TIME;
	travelTime 		 	 = ARCHER_TRAVEL_TIME;
	MAX_HITPOINTS 		 = attributes.hitpoints = ARCHER_BASE_HITPOINTS;
	attributes.damage	 = ARCHER_BASE_DAMAGE;
	attributes.defense	 = ARCHER_BASE_DEFENSE;
}

float Archer::getMaxSpeedX(){
    return ARCHER_SPEED_X;
}

float Archer::getMaxSpeedY(){
    return ARCHER_SPEED_Y;
}

float Archer::getMaxSpeedXY(){
    return ARCHER_SPEED_XY;
}