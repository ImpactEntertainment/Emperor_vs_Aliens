// Autor: Luis Gustavo Souza Silva
// Data: 23/01/2013
// e-mail: luisgustavodd@hotmail.com

#ifndef ENVIROMENT_ELEMENT_H
#define ENVIROMENT_ELEMENT_H

#include "element.h"

#define RESOURCES "/opt/EmperorVsAliens/resources/map_elements.png"

#define CHERRY_WIDTH	224
#define CHERRY_HEIGHT	224
#define CHERRY_OFFSET_X	0
#define CHERRY_OFFSET_Y	112

#define LARGE_ROCK_01_WIDTH		224
#define LARGE_ROCK_01_HEIGHT	112
#define LARGE_ROCK_01_OFFSET_X	336
#define LARGE_ROCK_01_OFFSET_Y	0

#define LARGE_ROCK_02_WIDTH		224
#define LARGE_ROCK_02_HEIGHT	112
#define LARGE_ROCK_02_OFFSET_X	560
#define LARGE_ROCK_02_OFFSET_Y	0

#define LARGE_ROCK_03_WIDTH		224
#define LARGE_ROCK_03_HEIGHT	112
#define LARGE_ROCK_03_OFFSET_X	784
#define LARGE_ROCK_03_OFFSET_Y	0

#define SMALL_ROCK_01_WIDTH		112
#define SMALL_ROCK_01_HEIGHT	112
#define SMALL_ROCK_01_OFFSET_X	1008
#define SMALL_ROCK_01_OFFSET_Y	0

class EnviromentElement : public Element 
{
public:
	EnviromentElement(int x=0, int y=0);
	void loadCherryTree();
	void loadLargeRock01();
	void loadLargeRock02();
	void loadLargeRock03();
	void loadSmallRock01();
	
private:
};


#endif
