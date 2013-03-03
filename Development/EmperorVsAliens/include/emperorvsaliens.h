/**
 * \file emperorvsaliens.h
 * \brief Classe que representa o jogo.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef EMPERORVSALIENS_H
#define	EMPERORVSALIENS_H

#include <SDL/SDL.h>
#include <string>
#include <list>

#include "exception.h"
#include "video.h"
#include "window.h"
#include "boundingrectangle.h"
#include "levelfactory.h"

using namespace std;

namespace edge
{
    class EmperorVsAliens
    {
    public:
        void init(Level choice);
        void shutdown();
        void update();
        void draw(Canvas *canvas);
		void IA();
        
        void callNextWave();
        
        void decomposeDead();
        void updateUnits();
        void increaseResources();
        void killSwarm();
        bool waveAlive();

        int         resources;
        list<Unit*> swarmUnits;
        list<Unit*> emperorUnits;
        Map         *board;
    };
}

#endif

