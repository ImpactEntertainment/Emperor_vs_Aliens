/**
 * \file text.h
 * \brief Classe que representa um texto em SDL.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 80/02/2012
 */

#ifndef SDL_TEXT_H
#define	SDL_TEXT_H

#include <string>

#include "text.h"

using namespace std;

namespace edge {
	
	class SDL_Text : public Text {
	public:
		SDL_Text(const string& text = "");
		
		Image * render(Font *font, const Color& color) const throw (Exception);
	};
}

#endif

