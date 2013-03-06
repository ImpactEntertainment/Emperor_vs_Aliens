// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef HUD_H
#define HUD_H

#include "menu.h"

using namespace edge;

class HUD : public Menu {
public:
	HUD();
	void update();
	void loadRectangle();
	void loadImage();
	void loadButtons();
	bool handleClick(int index);

private:
};


#endif
