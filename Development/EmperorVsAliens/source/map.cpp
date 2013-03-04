#include "map.h"
#include <iostream>

using namespace std;

void Map::reset()
{
	currentWave = 0;
}

void Map::init()
{
  	reset();
 	loadBattlefield();
	loadMainBuilding();
  	loadSpawnPoints();
	loadWaves();
	loadEnviroment();
}

void Map::loadBattlefield()
{
	for(int x=0; x < BATTLEFIELD_WIDTH; x++)
		for(int y=0; y < BATTLEFIELD_HEIGHT; y++)
		{
			battlefield[x][y].x = x;
			battlefield[x][y].y = y;
		}
	
	for(int x=0; x < BATTLEFIELD_WIDTH; x++)
		for(int y=0; y < BATTLEFIELD_HEIGHT; y++)
		{
			battlefield[x][y].path[NORTHWEST]	= (!y || !x) ? 0 : &battlefield[x-1][y-1];
			battlefield[x][y].path[NORTH]		= !y ? 0 : &battlefield[x][y -1];
			battlefield[x][y].path[NORTHEAST]	= (!y || x==BATTLEFIELD_WIDTH-1) ? 0 : &battlefield[x+1][y - 1];
			battlefield[x][y].path[WEST]		= !x ? 0 : &battlefield[x-1][y];
			battlefield[x][y].path[EAST]		= (y == BATTLEFIELD_HEIGHT-1) ? 0 : &battlefield[x+1][y];
			battlefield[x][y].path[SOUTHWEST]	= (y == BATTLEFIELD_HEIGHT-1 || !x) ? 0 : &battlefield[x-1][y+1];
			battlefield[x][y].path[SOUTH]		= (y == BATTLEFIELD_HEIGHT-1) ? 0 : &battlefield[x][y+1];
			battlefield[x][y].path[SOUTHEAST]	= (y == BATTLEFIELD_HEIGHT-1 || x == BATTLEFIELD_WIDTH-1) ? 0 : &battlefield[x+1][y+1];
		}
}

bool Map::isMainBuildingDestroyed()
{
	return  mainBuilding->destroyed;
}

void Map::shutdown()
{
}

void Map::NextWave()
{
	currentWave++;
}

vector<Unit*>* Map::Wave()
{
	return &waves[currentWave];
}

int Map::getWavesLeft()
{
	return waves.size();
}

