#include "easygame.h"

void EasyGame::init(const string& configFilePath)
{
	Game::init(configFilePath);
    timeToLive = timeForNextWave;
}


void EasyGame::gameBehaviour()
{
    if(Timer::get_currentFrameTick() >= timeToLive)
        eva.killSwarm();
}

void EasyGame::callNextWave()
{
	Game::callNextWave();
    timeToLive = timeForNextWave; 
}