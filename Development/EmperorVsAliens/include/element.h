// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef ELEMENT_H
#define ELEMENT_H

#include "rectangle.h"
#include "image.h"
#include "point.h"
#include "field.h"
#include "timer.h"

using namespace edge;

class Element {
public:
	Rectangle mResource;	
	Field 	  *mPosition;
    Image 	  *image;
    
	virtual void loadRectangle() = 0;
	virtual void loadImage() = 0;
	
	virtual bool isAttackable();
	
	void init();
	Element(Field *pos);
	Element();

	void setPosition(Field *pos);
	void shutdown();
private:
};


#endif
