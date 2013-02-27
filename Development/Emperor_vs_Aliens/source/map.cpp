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

	/*for(int x=0; x < BATTLEFIELD_WIDTH; x++)
		for(int y=0; y < BATTLEFIELD_HEIGHT; y++)
		{
			cout << "--------------------------------------------------" << endl;
			cout << &battlefield[x][y] <<": "<<battlefield[x][y].x <<","<< battlefield[x][y].y << endl;
			cout << "NORTHWEST "<<battlefield[x][y].path[NORTHWEST] << endl;
			cout << "NORTH "<<battlefield[x][y].path[NORTH] << endl;
			cout << "NORTHEAST "<<battlefield[x][y].path[NORTHEAST] << endl;
			cout << "WEST "<<battlefield[x][y].path[WEST] << endl;
			cout << "EAST "<<battlefield[x][y].path[EAST] << endl;
			cout << "SOUTHWEST "<<battlefield[x][y].path[SOUTHWEST] << endl;
			cout << "SOUTH "<<battlefield[x][y].path[SOUTH] << endl;
			cout << "SOUTHEAST "<<battlefield[x][y].path[SOUTHEAST] << endl;

			cout << "--------------------------------------------------" << endl;
		}*/
}

void Map::draw(Canvas* canvas)
{
	canvas->drawBackground();
	canvas->drawEnviroment(enviromentElements);
	canvas->drawBottomGrass();			
}

void Map::shutdown()
{
}

void Map::NextWave()
{
	currentWave++;
}

vector<Unit>& Map::Wave()
{
	return waves[currentWave];
}

int Map::getWavesLeft()
{
	return waves.size();
}


