/**
 * \file sdlsound.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 09/01/2013
 */
#include <fstream>

#include "sdlsound.h"

    SDL_Sound * load(const string& soundPath) throw (Exception){

        ifstream file(soundPath.c_str());

        if (!file)
            throw Exception("Sound not found");

        file.close();

        Mix_Chunk *sound_stream = Mix_LoadWAV(soundPath.c_str());

        if (sound_stream == NULL) 
            throw Exception("Invalid sound");
      
        SDL_Sound *sound = new SDL_Sound(sound_stream);

        return sound;
    }

    void  SDL_Sound::play(SDL_Sound* sound) throw (Exception){               
            Mix_PlayChannel(-1,sound->sound, 0);
    }

    SDL_Sound::~SDL_Sound(){
        if (sound) {
            Mix_FreeChunk(sound);
        }
    }

    SDL_Sound::SDL_Sound(Mix_Chunk * sound){

        if (Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 ) < 0){
            printf("Error initializing SDL_mixer: %s\n", Mix_GetError());
            exit(1);
        }
        this->sound= sound;
    }


