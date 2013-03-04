// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef MENU_H
#define MENU_H

#include "element.h"

using namespace edge;

class Menu : public Element {
public:
	Menu();
	void update();
	void loadRectangle();
	void loadImage();

	int frameCount;
	int timeForNextFrame;
private:
};


#endif
