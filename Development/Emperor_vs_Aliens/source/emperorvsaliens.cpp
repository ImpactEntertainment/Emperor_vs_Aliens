#include "emperorvsaliens.h"

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
    }
    
    void EmperorVsAliens::callNextWave()
    {	
    	swarmUnits.insert(swarmUnits.end(),board.Wave().begin(),board.Wave().end());
    	board.NextWave();
    }
    
    void EmperorVsAliens::draw(Canvas* canvas)
    {
        board.draw(canvas);
        canvas->drawUnits(swarmUnits);
    }

	void EmperorVsAliens::IA()
	{
		vector<Unit>::iterator it;
		for(it = swarmUnits.begin(); it < swarmUnits.end(); it++)
			it->IA();
	}

}
