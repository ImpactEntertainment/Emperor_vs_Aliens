#include "soundeffect.h"


void SoundEffect::play_effects(){

	if(this->effects.main->enabled){
		 SDL_Sound::play(this->effects.main);
	}

	if(this->effects.level01->enabled){
		 SDL_Sound::play(this->effects.level01);
	}

	if(this->effects.level02->enabled){
		 SDL_Sound::play(this->effects.level02);
	}

	if(this->effects.level03->enabled){
		 SDL_Sound::play(this->effects.level03);
	}

	if(this->effects.level04->enabled){
		 SDL_Sound::play(this->effects.level04);
	}

	if(this->effects.level05->enabled){
		 SDL_Sound::play(this->effects.level05);
	}

	if(this->effects.level06->enabled){
		 SDL_Sound::play(this->effects.level06);
	}

	if(this->effects.level07->enabled){
		 SDL_Sound::play(this->effects.level07);
	}

	if(this->effects.level08->enabled){
		 SDL_Sound::play(this->effects.level08);
	}

	if(this->effects.level09->enabled){
		 SDL_Sound::play(this->effects.level09);
	}

	if(this->effects.level10->enabled){
		 SDL_Sound::play(this->effects.level10);
	}

	if(this->effects.level11->enabled){
		 SDL_Sound::play(this->effects.level11);
	}

	if(this->effects.level12->enabled){
		 SDL_Sound::play(this->effects.level12);
	}

	if(this->effects.hit->enabled){
		 SDL_Sound::play(this->effects.hit);
	}

	if(this->effects.whip->enabled){
		 SDL_Sound::play(this->effects.whip);
	}

	if(this->effects.thunder->enabled){
		 SDL_Sound::play(this->effects.thunder);
	}

	if(this->effects.rain->enabled){
		 SDL_Sound::play(this->effects.rain);
	}


}



		
		
		
		
		
		
		
		
		
		
		















