/**
 * \file sdlsound.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 09/01/2013
 */
#include <fstream>

#include "sdlsound.h"


namespace edge{

    Sound * Sound::load(const string& soundPath) throw (Exception){

        ifstream file(soundPath.c_str());

        if (!file)
            throw Exception("Sound not found");

        file.close();

        Mix_Music *sound_stream = Mix_LoadMUS(soundPath.c_str());

        if (sound_stream == NULL) 
            throw Exception("Invalid sound");
      
        SDL_Sound *sound = new SDL_Sound(sound_stream);

        return sound;
    }

    void  Sound::release(Sound *sound) throw (Exception){
        if (sound) {
            delete sound;
        }
    }

    void  SDL_Sound::play(SDL_Sound* sound) throw (Exception){               
            Mix_PlayMusic(sound->sound_stream, 0);
    }

    SDL_Sound::~SDL_Sound(){
        if (sound_stream) {
            Mix_FreeMusic(sound_stream);
        }
    }

    SDL_Sound::SDL_Sound(Mix_Music * sound_stream){

        if (Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 ) < 0){
            printf("Error initializing SDL_mixer: %s\n", Mix_GetError());
            exit(1);
        }
        this->sound_stream = sound_stream;
    }

}
