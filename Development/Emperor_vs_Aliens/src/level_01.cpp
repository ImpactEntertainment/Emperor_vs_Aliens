#include "level_01.h"

using namespace std;

void Level_01::loadWaves()
{
	vector<Unit> wave1,
				 wave2,
				 wave3;
				 
	wave1.push_back(1);
	wave2.push_back(1);
	wave3.push_back(1);
	
	waves.push_back(wave1);
	waves.push_back(wave2);
	waves.push_back(wave3);
}

void Level_01::loadEnviroment()
{
	
	EnviromentElement	cherryTree1(11,0),
						cherryTree2(4,4),
						cherryTree3(14,5);
	
	EnviromentElement	largeRock01(4,4),
						largeRock03(11,5),
						smallRock01(11,0);
	
	cherryTree1.loadCherryTree();
	cherryTree2.loadCherryTree();
	cherryTree3.loadCherryTree();
	
	enviromentElements.push_back(cherryTree1);
	enviromentElements.push_back(cherryTree2);
	enviromentElements.push_back(cherryTree3);
	
	largeRock01.loadLargeRock01();
	largeRock03.loadLargeRock03();
	smallRock01.loadSmallRock01();

	enviromentElements.push_back(largeRock01);
	enviromentElements.push_back(largeRock03);
	enviromentElements.push_back(smallRock01);	
}
