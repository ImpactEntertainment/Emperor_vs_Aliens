// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef UNIT_H
#define UNIT_H

#include "element.h"

class Unit : public Element {
public:
	
	void loadRectangle();
	void loadImage();
	
	Unit(int x=0, int y=0);
private:
};


#endif
