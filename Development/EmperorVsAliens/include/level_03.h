/**
 * \file  Level_03.h
 * \brief Classe que representa o level 03.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef LEVEL_03_H
#define	LEVEL_03_H

#include "map.h"

using namespace std;
	
class Level_03 : public Map
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

