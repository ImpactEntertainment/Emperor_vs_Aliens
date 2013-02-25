// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef ELEMENT_H
#define ELEMENT_H

#include "point.h"
#include "rectangle.h"
#include "image.h"

using namespace edge;

class Element {
public:
	Rectangle mResource;	
	Point mPosition;
    Image *image;
	
	virtual void loadRectangle() = 0;
	virtual void loadImage() = 0;
	
	void init();
	Element(int x=0, int y=0);
	void setPosition(int, int);
	void shutdown();
private:
};


#endif
