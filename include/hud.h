// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef HUD_H
#define HUD_H

#include <string>
#include "menu.h"
#include "display.h"

using namespace edge;
using namespace std;

class HUD : public Menu {
public:
	HUD();
	HUD(int* r, int* t, int* w);
	void update();
	void loadRectangle();
	void loadImage();
	void loadButtons();
	bool handleClick(int index);
	
	void updateTime();
	void updateResource();
	void updateWavesLeft();

	void loadDisplays();
	void addDisplay(Display& display, string* infoTracked, int x, int y, int size, int r, int g, int b);

	int* resource;
	int* time;
	int* wavesLeft;
	string resourceInfo;
	string timeInfo;
	string wavesLeftInfo;
	Display resourceDisplay;
	Display timeDisplay;
	Display wavesLeftDisplay;


	string  victoryInfo;
	string  defeatInfo;
	Display victory;
	Display defeat;
private:
};


#endif
