// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef UNIT_H
#define UNIT_H

#include <cmath>
#include <vector>
#include <list>
#include "element.h"
#include "field.h"

typedef struct Speed{
	float x, y;
}Speed;

typedef struct Attributes{
	int hitpoints;
	int damage;
	int defense;
}Attributes;

typedef enum Status {
	UNIT_IDLE,
	UNIT_MOVING,
	UNIT_ATTACKING,
	UNIT_DEAD
} Status;

class SwarmUnit;
class EmperorUnit;

class Unit : public Element {
public:
	
	virtual void loadBaseAttributes() = 0;
	virtual void createPath() = 0;
	virtual void move() = 0;
	virtual void getTarget() = 0;
	virtual void attack() = 0;
	virtual	bool isAlien()=0;
	void loadRectangle();
	void loadImage();
	//virtual void alienTarget(Unit* unit) = 0;
	//virtual void emperorTarget(Unit* unit) = 0;

	void interact(Unit* unit);
	
	bool spawn();
	
	Unit(Field* pos);

	void update();
	void IA();
	void moveTo(int x, int y);
	void decision();
	void startAttack(Unit* newTarget);
	void arrive();
	void enableAttack();
	void receiveDamage(int damage);
	void onDeath();
	
	Unit *target;

	bool  markForDeath;
	bool  decomposed;
	bool  spawned;
	bool  attackCooldown;
	int	  backswingTime;
	int	  travelTime;

	Attributes attributes;
	Speed speed;
	Status status;
	
	int ARRIVAL_TIME;
	int ATTACK_READY_TIME;
	int frameCount;
protected:
	list<Field*> path;
};


#endif
