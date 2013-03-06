// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef HUD_H
#define HUD_H

#include "menu.h"

using namespace edge;

class HUD : public Menu {
public:
	HUD(Field *pos);
	void update();
	void loadRectangle();
	void loadImage();

	void loadButtons();
	bool handleClick(int index);
	bool click(Button& area);
	bool handleMouseEvent(SDL_MouseButtonEvent &event);
	void close();

	Option 			option;
	int 			frameCount;
	int 			timeForNextFrame;
	Point 			clicked;
	vector<Button*> buttons;
private:
};


#endif
