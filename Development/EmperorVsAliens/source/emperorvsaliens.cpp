#include "emperorvsaliens.h"
#include <iostream>

using namespace std;

namespace edge
{

    void EmperorVsAliens::init()
    {
        board.init();
        resources = board.getInitialResources();
    }

    void EmperorVsAliens::shutdown()
    {
        board.shutdown();
    }
    
    void EmperorVsAliens::killSwarm()
    {
        list<Unit*>::iterator it;
        for(it = swarmUnits.begin(); it != swarmUnits.end();it++)
            (*it)->markForDeath = true;
    }

    void EmperorVsAliens::decomposeDead()
    {
        list<Unit*>::iterator it;
        for(it = swarmUnits.begin(); it != swarmUnits.end();)
            if((*it)->decomposed)
                it = swarmUnits.erase(it);
            else
                it ++;
        for(it = emperorUnits.begin(); it != emperorUnits.end();)
            if((*it)->decomposed)
                it = swarmUnits.erase(it);
            else
                it ++;
    }

    void EmperorVsAliens::updateUnits()
    {
        list<Unit*>::iterator it;
        for(it = swarmUnits.begin(); it != swarmUnits.end(); it++)
            (*it)->update();
        for(it = emperorUnits.begin(); it != emperorUnits.end(); it++)
            (*it)->update();
    
    }

    void EmperorVsAliens::increaseResources()
    {
        resources += board.getResourcesIncrement();
    }
    
    void EmperorVsAliens::update()
    {   
        updateUnits();
        decomposeDead();
    }
    
    void EmperorVsAliens::callNextWave()
    {	
    	swarmUnits.insert(swarmUnits.end(),board.Wave()->begin(),board.Wave()->end());
    	board.NextWave();

        //emperorUnits.push_back(new Unit(&board.battlefield[8][3]));
    }
    
    void EmperorVsAliens::draw(Canvas* canvas)
    {
        canvas->drawBackground();
        canvas->drawUnits(swarmUnits);
        canvas->drawUnits(emperorUnits);
        canvas->drawEnviroment(board.enviromentElements);
        canvas->drawBottomGrass();          
    }

	void EmperorVsAliens::IA()
	{
		list<Unit*>::iterator it;
		for(it = swarmUnits.begin(); it != swarmUnits.end(); it++)
			(*it)->IA();
	}

    bool EmperorVsAliens::waveAlive()
    {
        return !swarmUnits.empty();
    }

}