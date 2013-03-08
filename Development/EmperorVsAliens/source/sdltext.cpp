#include "sdltext.h"
#include "sdlfont.h"
#include "sdlimage.h"

#include <iostream>
using namespace std;

namespace edge {

	SDL_Text::SDL_Text(const string& text) : Text(text)
	{
	}

	Image *
	SDL_Text::render(Font *font, const Color& color) const throw(Exception)
	{
		SDL_Font *sdlFont = dynamic_cast<SDL_Font *>(font);
		if (!sdlFont) {
			throw Exception("Tipo de fonte invalido");
		}
		TTF_Font *ttfFont = sdlFont->font();
		
		if (!ttfFont) {
			throw Exception("Referencia a fonte invalida");
		}
		SDL_Color fontColor;
		fontColor.r = color.red;
		fontColor.g = color.green;
		fontColor.b = color.blue;

		SDL_Surface *surface = TTF_RenderText_Blended(ttfFont, text.c_str(),fontColor);
		
		if (!surface) {
			throw Exception("Nao foi possivel renderizar a fonte");
		}
		return new SDL_Image(surface);
	}
	
}