/**
 * \file  Level_06.h
 * \brief Classe que representa o level 06.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef LEVEL_06_H
#define	LEVEL_06_H

#include "map.h"

using namespace std;
	
class Level_06 : public Map
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

