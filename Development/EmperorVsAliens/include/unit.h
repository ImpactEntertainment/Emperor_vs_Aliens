// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef UNIT_H
#define UNIT_H

#include <vector>
#include <list>
#include "element.h"
#include "field.h"

#define SPEED_X	 112/8.0
#define SPEED_Y  112/8.0
#define SPEED_XY 0
#define UNIT_BASE_HITFieldS 100
#define	UNIT_BASE_DAMAGE	10

typedef struct Speed{
	float x, y;
}Speed;

typedef struct Attributes{
	int hitpoints;
	int damage;
}Attributes;

typedef enum Status {
	UNIT_IDLE,
	UNIT_MOVING,
	UNIT_ATTACKING,
	UNIT_DEAD
} Status;

class Unit : public Element {
public:
	
	void spawn();
	void loadRectangle();
	void loadImage();
	
	Unit(Field* pos);

	void update();
	void IA();
	void moveTo(int x, int y);
	void createPath();
	void decision();
	void startAttack(Unit* newTarget);
	void move();
	void getTarget();
	void arrive();
	void attack();
	void enableAttack();
	void receiveDamage(int damage);
	void onDeath();
	
	Unit *target;

	bool  decomposed;
	bool  spawned;
	bool  attackCooldown;
	float attackSpeed;

	Attributes attributes;
	Speed speed;
	Status status;
	
	int frameCount;
protected:
	list<Field*> path;
};


#endif
