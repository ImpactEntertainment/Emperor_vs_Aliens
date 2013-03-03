#include "normalgame.h"


void NormalGame::gameBehaviour()
{
		if(timeForNextWave != WAVE_COOLDOWN)  
    		timeForNextWave = Timer::get_currentFrameTick() + (eva.waveAlive() ? 1 : 0);
}