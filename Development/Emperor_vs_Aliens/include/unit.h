// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef UNIT_H
#define UNIT_H

#include "element.h"

#define SPEED_X	 112/8.0
#define SPEED_Y  112/8.0
#define SPEED_XY 0

typedef struct Speed{
	float x, y;
}Speed;

typedef enum Status {
	UNIT_IDLE,
	UNIT_MOVING
} Status;

class Unit : public Element {
public:
	
	void loadRectangle();
	void loadImage();
	
	Unit(Point position);

	void update();
	void IA();
	void moveTo(int x, int y);

	Speed speed;
	Status status;
	int frameCount;
private:
	vector<Field*> path;
};


#endif
