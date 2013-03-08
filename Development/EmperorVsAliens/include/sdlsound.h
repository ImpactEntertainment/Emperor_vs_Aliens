/**
 * \file sdlsound.h
 * \brief Classe que representa um som em SDL.
 *
 * Esta classe representa um som em SDL.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 10/01/2013
 */

#ifndef SDL_SOUND_H
#define	SDL_SOUND_H

#include <SDL/SDL_mixer.h>

#include "exception.h"

    class SDL_Sound {
    public:
        SDL_Sound * load(const string& soundPath) throw (Exception);
        SDL_Sound(Mix_Chunk *sound);               
        ~SDL_Sound();
        static void play(SDL_Sound *sound) throw (Exception); 
       
        Mix_Chunk *sound;
        int enabled;
    };


#endif

