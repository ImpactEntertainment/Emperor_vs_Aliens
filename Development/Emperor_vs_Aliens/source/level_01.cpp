#include "level_01.h"

using namespace std;

void Level_01::loadWaves()
{
	vector<Unit> wave1,
				 wave2,
				 wave3;
	//Unit a(spawnPoint);
	Unit a(100,100);
	wave1.push_back(1);
	wave2.push_back(1);
	wave3.push_back(1);
	
	waves.push_back(wave1);
	waves.push_back(wave2);
	waves.push_back(wave3);
}

void Level_01::loadEnviroment()
{
	EnviromentElement	cherryTree1(CHERRY_TREE,11,0),
						cherryTree2(CHERRY_TREE,4,4),
						cherryTree3(CHERRY_TREE,14,5);
	
	EnviromentElement	largeRock01(LARGE_ROCK_01,4,4),
						largeRock03(LARGE_ROCK_03,11,5),
						smallRock01(SMALL_ROCK_01,11,0);
	
	
	enviromentElements.push_back(cherryTree1);
	enviromentElements.push_back(cherryTree2);
	enviromentElements.push_back(cherryTree3);
	
	enviromentElements.push_back(largeRock01);
	enviromentElements.push_back(largeRock03);
	enviromentElements.push_back(smallRock01);	
}
