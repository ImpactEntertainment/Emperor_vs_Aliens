//CODIGO DO LAZY FOO
/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

#ifndef TIMER_H
#define TIMER_H

//The headers
#include "SDL/SDL.h"

#define ONE_SECOND		1000
#define TWO_SECONDS		2000
#define THREE_SECONDS	3000
#define FOUR_SECONDS	4000
#define FIVE_SECONDS	5000
#define TEN_SECONDS		10000

//The timer
class Timer
{
private:
    //The clck time when the timer STARTED
    static int START_TICKS;
    static int CURRENT_FRAME_TICK;
    //The ticks stored when the timer was PAUSED
    static int PAUSED_TICKS;

    //The timer status
    static bool PAUSED;
    static bool STARTED;
    static bool FAST_FORWARDED;

public:
    //Initializes variables
    //Timer();

    //The various clck actions
    static void start();
    static void stop();
    static void pause();
    static void unpause();

    static void set_currentFrameTick();
    static int get_currentFrameTick();
    static void toggleFastForward();
    static void togglePause();

    //Gets the timer's time
    static int get_ticks();

    //Checks the status of the timer
    static bool is_started();
    static bool is_paused();
};

#endif