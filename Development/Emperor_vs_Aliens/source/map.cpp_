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
	loadWaves();
	loadEnviroment();
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
