/**
 * \file  map.h
 * \brief Classe que representa um campo de batalha.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef MAP_H
#define	MAP_H

#include <SDL/SDL.h>
#include <string>
#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

#include "exception.h"
#include "video.h"
#include "window.h"
#include "boundingrectangle.h"
#include "imageset.h"
#include "enviromentelement.h"
#include "unitfactory.h"
#include "field.h"
#include "building.h"

#define BATTLEFIELD_WIDTH 16
#define BATTLEFIELD_HEIGHT 6


using namespace std;

class Map
{
private:
	virtual void loadSpawnPoints() = 0;
	virtual void loadWaves() = 0;
	virtual void loadEnviroment() = 0;
	virtual void loadMainBuilding() = 0;
public:    
	virtual int getInitialResources() = 0;
	virtual int getResourcesIncrement() = 0;
    void init();
    void loadBattlefield();
    void shutdown();
    void NextWave();
    vector<Unit*>* Wave();
    int	 getWavesLeft();
	void reset();
	
	Field						battlefield[BATTLEFIELD_WIDTH][BATTLEFIELD_HEIGHT];
	Building					*mainBuilding;
	vector<Field*> 				spawnPoints;
	vector<EnviromentElement>	enviromentElements;
	vector< vector<Unit*> > 	waves;
	int 						currentWave;
};
#endif

