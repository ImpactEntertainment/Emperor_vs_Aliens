// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef UNIT_H
#define UNIT_H

#include <vector>
#include "element.h"
#include "point.h"

#define SPEED_X	 112/8.0
#define SPEED_Y  112/8.0
#define SPEED_XY 0

typedef struct Speed{
	float x, y;
}Speed;

typedef enum Status {
	UNIT_IDLE,
	UNIT_MOVING,
	UNIT_ATTACKING
} Status;

class Unit : public Element {
public:
	
	void loadRectangle();
	void loadImage();
	
	Unit(Point *pos);

	void update();
	void IA();
	void moveTo(int x, int y);
	void createPath();
	void decision();
	void attack(Unit* target);
	void move();
	void getTarget();
	void arrive();
	
	float attackSpeed;
	Speed speed;
	Status status;
	int frameCount;
private:
	vector<Point*> path;
};


#endif
