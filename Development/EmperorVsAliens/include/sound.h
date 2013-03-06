/**
 * \file sound.h
 * \brief Interface que representa um som.
 *
 * Esta interface representa um som.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 06/03/2013
 */

#ifndef SOUND_H
#define SOUND_H

#include <string>

namespace edge {

    class Sound {
    public:
        static Sound * load(const string& soundPath) throw (Exception);
        static void release(Sound *sound) throw (Exception);    
        static void play(Sound *sound) throw (Exception);           
    };
}

#endif
