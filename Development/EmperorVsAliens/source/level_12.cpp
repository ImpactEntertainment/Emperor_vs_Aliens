#include "level_12.h"

using namespace std;

void Level_12::loadBackground()
{
	background = Image::load("/opt/EmperorVsAliens/data/images/level_12.png");
}

void Level_12::loadBottomGrass()
{
	bottomGrass = new EnviromentElement(BOTTOM_GRASS,NULL);
	bottomGrass->mResource.x = 0;
	bottomGrass->mResource.y = 1020;
	bottomGrass->mResource.width = 1920;
	bottomGrass->mResource.height = 60;
	bottomGrass->mPosition = new Field(0,1020);
}

void Level_12::loadSpawnPoints()
{
	spawnPoints.push_back(&battlefield[15][2]);
	spawnPoints.push_back(&battlefield[15][3]);
	spawnPoints.push_back(&battlefield[15][4]);
}

void Level_12::loadMainBuilding()
{
	mainBuilding = new Building(500,50);

	for(int y = 0; y < BATTLEFIELD_HEIGHT ; y++)
		mainBuilding->addRange(&battlefield[0][y]);
}

void Level_12::loadWaves()
{
	vector<Unit*>	wave1,
					wave2,
					wave3;

	wave1.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave1.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave2.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave2.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave2.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave3.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave3.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave3.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));
	wave3.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,spawnPoints[rand()%spawnPoints.size()]));

	waves.push_back(wave1);
	waves.push_back(wave2);
	waves.push_back(wave3);
}

void Level_12::loadEnviroment()
{
	EnviromentElement	cherryTree1(CHERRY_TREE,&battlefield[11][0]),
						cherryTree2(CHERRY_TREE,&battlefield[4][4]),
						cherryTree3(CHERRY_TREE,&battlefield[14][5]);
	
	EnviromentElement	largeRock01(LARGE_ROCK_01,&battlefield[4][4]),
						largeRock03(LARGE_ROCK_03,&battlefield[11][5]),
						smallRock01(SMALL_ROCK_01,&battlefield[11][0]);
	
	
	enviromentElements.push_back(cherryTree1);
	enviromentElements.push_back(cherryTree2);
	enviromentElements.push_back(cherryTree3);
	
	enviromentElements.push_back(largeRock01);
	enviromentElements.push_back(largeRock03);
	enviromentElements.push_back(smallRock01);	
}

int Level_12::getInitialResources()
{
	return 1000;
}

int Level_12::getResourcesIncrement()
{
	return 10;
}
