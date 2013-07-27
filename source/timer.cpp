//CODIGO DO LAZY FOO
#include "timer.h"

#include <iostream>
using namespace std;

int Timer::START_TICKS = 0;
int Timer::CURRENT_FRAME_TICK = 0;
int Timer::PAUSED_TICKS = 0;
int Timer::FORWARDED_TICKS = 0;
int Timer::FORWARDED_START = 0;
bool Timer::PAUSED = false;
bool Timer::STARTED = false;
bool Timer::FAST_FORWARDED = false;

void Timer::start(){
    //Start the timer
    STARTED = true;

    //Unpause the timer
    PAUSED = false;

    
    CURRENT_FRAME_TICK = 0;
    FAST_FORWARDED = false;
    PAUSED_TICKS = 0;
    FORWARDED_TICKS = 0;
    FORWARDED_START = 0;

    //Get the current clck time
    START_TICKS = SDL_GetTicks();
}

void Timer::stop(){
    //Stop the timer
    STARTED = false;

    //Unpause the timer
    PAUSED = false;
}

void Timer::pause(){
    //If the timer is running and isn't already PAUSED

    if( ( STARTED == true ) && ( PAUSED == false ) ){
        if(FAST_FORWARDED) unfastforward();
        //Pause the timer
        PAUSED = true;

        //Calculate the PAUSED ticks
        PAUSED_TICKS = SDL_GetTicks() - START_TICKS;
    }
}

void Timer::unpause(){
    //If the timer is PAUSED
    if( PAUSED == true){
        //Unpause the timer
        PAUSED = false;

        //Reset the starting ticks
        START_TICKS = SDL_GetTicks() - PAUSED_TICKS;

        //Reset the PAUSED ticks
        PAUSED_TICKS = 0;
    }
}

void Timer::fastforward(){
    //If the timer is running and isn't already PAUSED
    if( STARTED && !FAST_FORWARDED && !PAUSED ){
        //Pause the timer
        FAST_FORWARDED = true;

        FORWARDED_START = SDL_GetTicks() + FORWARDED_TICKS;
    }
}

void Timer::unfastforward(){
    //If the timer is PAUSED
    if( STARTED && FAST_FORWARDED && !PAUSED){
        //Unpause the timer
        FAST_FORWARDED = false;

        //Reset the starting ticks
        FORWARDED_TICKS += (SDL_GetTicks() + FORWARDED_TICKS - FORWARDED_START)*2;
    }
}

void Timer::set_currentFrameTick(){
    CURRENT_FRAME_TICK = get_ticks();
}

int Timer::get_currentFrameTick(){
    return CURRENT_FRAME_TICK;
}

void Timer::toggleFastForward(){
    FAST_FORWARDED ? unfastforward() : fastforward();
}

void Timer::togglePause(){
    PAUSED ? unpause() : pause();
}

int Timer::get_ticks(){
    //If the timer is running
    if( STARTED == true ){
        //If the timer is PAUSED
        if( PAUSED == true )
        {
            //Return the number of ticks when the timer was PAUSED
            return PAUSED_TICKS+ FORWARDED_TICKS;
        }
        else if(FAST_FORWARDED)
        {
            return (SDL_GetTicks() + FORWARDED_TICKS- FORWARDED_START)*2 + (SDL_GetTicks() + FORWARDED_TICKS - START_TICKS) ;
        }
        else
        {
            //Return the current time minus the start time
            return (SDL_GetTicks() - START_TICKS) + FORWARDED_TICKS;
        }
    }

    //If the timer isn't running
    return -1;
}

bool Timer::is_started(){
    return STARTED;
}

bool Timer::is_paused(){
    return PAUSED;
}
