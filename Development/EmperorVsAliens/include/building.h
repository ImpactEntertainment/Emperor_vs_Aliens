// Autor: Luis Gustavo Souza Silva
// e-mail: luisgustavodd@hotmail.com

#ifndef BUILDING_H
#define BUILDING_H

#include <cmath>
#include <vector>
#include <list>
#include "element.h"
#include "field.h"

class Building : public Element {
public:	
	void loadRectangle();
	void loadImage();
	
	Building(int hp, int damageReduction);

	void addRange(Field *field);
	void update();
	void receiveDamage(int damage);
	void onDestruction();
	
	bool	destroyed;
	int		MAX_HITPOINTS;
	int		HITPOINTS;
	int		DAMAGE_REDUCTION;
	int		frameCount;
protected:
	list<Field*> range;
};


#endif
