/**
 * \file SoundEffects.h
 * \brief Classe que implementa os diferentes sons.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 25/01/2012
 */
#ifndef SOUND_EFFECTS_H
#define SOUND_EFFECTS_H
#include "sdlsound.h"
typedef struct Effect
{
	SDL_Sound *main;
	SDL_Sound *level01;
	SDL_Sound *level02;
	SDL_Sound *level03;
	SDL_Sound *level04;
	SDL_Sound *level05;
	SDL_Sound *level06;
	SDL_Sound *level07;
	SDL_Sound *level08;
	SDL_Sound *level09;
	SDL_Sound *level10;
	SDL_Sound *level11;
	SDL_Sound *level12;
	SDL_Sound *hit;
	SDL_Sound *whip;
	SDL_Sound *thunder;
	SDL_Sound *rain;
}Effect;

class SoundEffect {
public:
    static void play_effects();
};

#endif

