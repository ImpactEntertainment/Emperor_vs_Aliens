#include "level_01.h"

using namespace std;

void Level_01::loadSpawnPoints()
{
	spawnPoints.push_back(&battlefield[15][2]);
	spawnPoints.push_back(&battlefield[15][3]);
	spawnPoints.push_back(&battlefield[15][4]);
}

void Level_01::loadWaves()
{
	vector<Unit> wave1,
				 wave2,
				 wave3;

	Unit a(spawnPoints[rand()%spawnPoints.size()]);
	Unit b(spawnPoints[rand()%spawnPoints.size()]);
	Unit c(spawnPoints[rand()%spawnPoints.size()]);


	wave1.push_back(a);
	wave2.push_back(b);
	wave3.push_back(c);
	
	waves.push_back(wave1);
	waves.push_back(wave2);
	waves.push_back(wave3);
}

void Level_01::loadEnviroment()
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