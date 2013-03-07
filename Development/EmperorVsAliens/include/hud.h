// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef HUD_H
#define HUD_H

#include <string>
#include "menu.h"
//#include "display.h"

using namespace edge;
using namespace std;

class HUD : public Menu {
public:
	HUD();
	HUD(int* r, int* t);
	void update();
	void loadRectangle();
	void loadImage();
	void loadButtons();
	bool handleClick(int index);
	string printTime();

	//Display display;
	int* resource;
	int* time;
private:
};


#endif
