/**
 * \file  Level_07.h
 * \brief Classe que representa o level 07.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef LEVEL_07_H
#define	LEVEL_07_H

#include "map.h"

using namespace std;
	
class Level_07 : public Map
{
public:
	int getInitialResources();
	int getResourcesIncrement();
private:
	void loadWaves();
	void loadEnviroment();
	void loadSpawnPoints();
	void loadMainBuilding();
	void loadBackground();
	void loadBottomGrass();
};
#endif

