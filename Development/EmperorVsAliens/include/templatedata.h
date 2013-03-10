// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef TEMPLATE_DATA_H
#define TEMPLATE_DATA_H

#include "image.h"

using namespace edge;

class TemplateData {
public:
	virtual Image* getImage()= 0;
protected:
	virtual void loadImage() = 0;
};


#endif
