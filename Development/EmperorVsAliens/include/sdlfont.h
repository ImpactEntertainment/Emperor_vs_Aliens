/**
 * \file sdlfont.h
 * \brief Class que representa uma fonte em SDL.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 80/02/2012
 */

#ifndef SDL_FONT_H
#define	SDL_FONT_H

#include <SDL/SDL_ttf.h>
#include <string>

#include "font.h"

using namespace std;

namespace edge {
	
	class SDL_Font : public Font {
	public:
		SDL_Font(TTF_Font *font = NULL, int size = 1);
		~SDL_Font();
		
		int size() const;
		TTF_Font * font() const;
		
	private:
		TTF_Font *handle;
		int fontSize;
	};
}

#endif	/* FONT_H */

