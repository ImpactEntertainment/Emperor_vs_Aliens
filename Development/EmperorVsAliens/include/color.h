/**
 * \file color.h
 * \brief Classe que representa uma cor.
 *
 * Esta classe representa uma cor no padrão RGB.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 09/01/2013
 */

#ifndef COLOR_H
#define	COLOR_H

namespace edge {

    class Color {
    public:
        Color(unsigned char red = 0, unsigned char green = 0, 
                unsigned char blue = 0);

        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

}

#endif

