#include "emperorvsaliens.h"
#include <iostream>

using namespace std;

namespace edge
{
    void EmperorVsAliens::init(Level choice)
    {
        board = (LevelFactory::create_level(choice));
        board->init();
        resources = board->getInitialResources();
    }

    void EmperorVsAliens::shutdown()
    {
        board->shutdown();
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
        resources += board->getResourcesIncrement();
    }
    
    void EmperorVsAliens::update()
    {   
        updateUnits();
        decomposeDead();
        board->mainBuilding->update();
    }
    
    void EmperorVsAliens::callNextWave()
    {	
    	swarmUnits.insert(swarmUnits.end(),board->Wave()->begin(),board->Wave()->end());
    	board->NextWave();

        emperorUnits.push_back(UnitFactory::create_unit(UNIT_SWARM_HIVER,&board->battlefield[1][1]));
    }
    
    void EmperorVsAliens::draw(Canvas* canvas)
    {
        canvas->drawBackground(board->background);
        canvas->drawUnits(swarmUnits);
        canvas->drawUnits(emperorUnits);
        canvas->drawEnviroment(board->enviromentElements);
        canvas->drawBottomGrass(board->bottomGrass);          
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

    bool EmperorVsAliens::noMoreEnemies()
    {
        return swarmUnits.empty() && (board->currentWave == board->waves.size()); 
    }

    bool EmperorVsAliens::isMainBuildingDestroyed()
    {
        return board->isMainBuildingDestroyed();
    }

    bool EmperorVsAliens::gameEnded()
    {
        return  isMainBuildingDestroyed() || noMoreEnemies();
    }

    Field* EmperorVsAliens::select(int x, int y)
    {
        int boardPositionX = 134,
            boardPositionY = 409,
            fieldSize      = 112;
        if(x < boardPositionX || y < boardPositionY)
            return NULL;
        else
        {    
            x = (x - boardPositionX)/fieldSize;
            y = (y - boardPositionY)/fieldSize;
            return &board->battlefield[x][y];
        }

    }
    void EmperorVsAliens::moveTo(Field* origin, Field* dest)
    {
        if(!origin->habitant) return;
        if(origin == dest)    return;
        cout << "SHOULD CREATE NEW PATH HERE!" << endl;
    }
}
