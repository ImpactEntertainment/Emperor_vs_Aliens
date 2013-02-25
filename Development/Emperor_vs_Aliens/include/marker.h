 /**
 * \file marker.h
 * \brief Classe que representa um marcador visual para o jogo da velha.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 28/01/2012
 */
#ifndef MARKER_H
#define	MARKER_H

#include <string>
#include "exception.h"
#include <SDL/SDL.h>
#include "video.h"
#include "window.h"
#include "boundingrectangle.h"

#include "element.h"

using namespace std;

namespace edge {

    class Marker : public Element{
    public:
        Marker();
        
        void loadRectangle();
        void loadImage();
    };
    
}

#endif

