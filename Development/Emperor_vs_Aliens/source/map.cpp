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
	loadSpawnPoints();
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

void Map::moveUnit(Unit& unit,const Point& dst)
{	
	unit.status = UNIT_MOVING;
	unit.speed.x = -SPEED_X;
	battlefield[unit.mPosition.x][unit.mPosition.y].habitant = NULL;
	
	//unit.mPosition = dst;
	//battlefield[unit.mPosition.x][unit.mPosition.y].habitant = &unit;
}

