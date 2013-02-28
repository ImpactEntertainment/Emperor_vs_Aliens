/**
 * \file image.h
 * \brief Interface que representa uma imagem.
 *
 * Esta interface representa uma imagem.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 10/01/2013
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <string>

#include "exception.h"
#include "point.h"
#include "rectangle.h"

using namespace std;

namespace edge {

    class Image {
    public:
        static Image * load(const string& imagePath, int offsetX=0, int offsetY=0, int width=0, int height=0) throw (Exception);
        static void release(Image *image) throw (Exception);
        
		virtual Image *select(const Point& position, 
			const Rectangle& rect) const = 0;
        
        virtual int width() const = 0;
        virtual int height() const = 0;
        virtual	bool hasClip() const = 0;
        
        int offsetX,
        	offsetY,
        	w,
        	h;
    };
}

#endif

