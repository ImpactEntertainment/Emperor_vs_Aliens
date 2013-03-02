//CODIGO DO LAZY FOO
#include "timer.h"

int Timer::START_TICKS = 0;
int Timer::PAUSED_TICKS = 0;
bool Timer::PAUSED = false;
bool Timer::STARTED = false;

void Timer::start()
{
    //Start the timer
    STARTED = true;

    //Unpause the timer
    PAUSED = false;

    //Get the current clck time
    START_TICKS = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    STARTED = false;

    //Unpause the timer
    PAUSED = false;
}

void Timer::pause()
{
    //If the timer is running and isn't already PAUSED
    if( ( STARTED == true ) && ( PAUSED == false ) )
    {
        //Pause the timer
        PAUSED = true;

        //Calculate the PAUSED ticks
        PAUSED_TICKS = SDL_GetTicks() - START_TICKS;
    }
}

void Timer::unpause()
{
    //If the timer is PAUSED
    if( PAUSED == true )
    {
        //Unpause the timer
        PAUSED = false;

        //Reset the starting ticks
        START_TICKS = SDL_GetTicks() - PAUSED_TICKS;

        //Reset the PAUSED ticks
        PAUSED_TICKS = 0;
    }
}

int Timer::get_ticks()
{
    //If the timer is running
    if( STARTED == true )
    {
        //If the timer is PAUSED
        if( PAUSED == true )
        {
            //Return the number of ticks when the timer was PAUSED
            return PAUSED_TICKS;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - START_TICKS;
        }
    }

    //If the timer isn't running
    return -1;
}

bool Timer::is_STARTED()
{
    return STARTED;
}

bool Timer::is_PAUSED()
{
    return PAUSED;
}
