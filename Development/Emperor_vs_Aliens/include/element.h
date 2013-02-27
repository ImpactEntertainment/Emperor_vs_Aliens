// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef ELEMENT_H
#define ELEMENT_H

#include "rectangle.h"
#include "image.h"
#include "point.h"

using namespace edge;

class Element {
public:
	Rectangle mResource;	
	Point *mPosition;
    Image *image;
    
	virtual void loadRectangle() = 0;
	virtual void loadImage() = 0;
	
	void init();
	Element(Point *pos);
	void setPosition(Point *pos);
	void shutdown();
private:
};


#endif
