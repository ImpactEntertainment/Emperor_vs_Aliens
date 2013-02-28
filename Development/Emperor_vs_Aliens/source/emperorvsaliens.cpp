#include "emperorvsaliens.h"
#include <iostream>

using namespace std;

namespace edge
{

    void EmperorVsAliens::init()
    {
        board.init();
    }

    void EmperorVsAliens::shutdown()
    {
        board.shutdown();
    }
    
    void EmperorVsAliens::update()
    {
		vector<Unit>::iterator it;
        for(it = swarmUnits.begin(); it < swarmUnits.end(); it++)
            it->update();
        for(it = emperorUnits.begin(); it < emperorUnits.end(); it++)
            it->update();
    }
    
    void EmperorVsAliens::callNextWave()
    {	
    	swarmUnits.insert(swarmUnits.end(),board.Wave().begin(),board.Wave().end());
    	board.NextWave();

        Unit test(&board.battlefield[8][3]);
        emperorUnits.push_back(test);
    }
    
    void EmperorVsAliens::draw(Canvas* canvas)
    {
        board.draw(canvas);
        canvas->drawUnits(swarmUnits);
        canvas->drawUnits(emperorUnits);
    }

	void EmperorVsAliens::IA()
	{
		vector<Unit>::iterator it;
		for(it = swarmUnits.begin(); it < swarmUnits.end(); it++)
			it->IA();
	}

}
