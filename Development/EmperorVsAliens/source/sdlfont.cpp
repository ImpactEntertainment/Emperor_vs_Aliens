#include "sdlfont.h"

namespace edge {

	Font *
	Font::load(const string& fontPath, int size) throw(Exception)
	{
		if (!TTF_WasInit()) {
			int rc = TTF_Init();

			if (rc != 0) {
				throw Exception("Erro na inicializacao da SDL_ttf");
			}
		}

		TTF_Font *handle = TTF_OpenFont(fontPath.c_str(), size);

		if (handle == NULL) {
			throw Exception("Erro no carregamento da fonte");
		}

		SDL_Font *font = new SDL_Font(handle);

		return font;
	}

	SDL_Font::SDL_Font(TTF_Font *font, int size)
	{
		handle = font;
		fontSize = size;
	}

	SDL_Font::~SDL_Font()
	{
		if (handle) {
			TTF_CloseFont(handle);
		}
	}

	int
	SDL_Font::size() const
	{
		return fontSize;
	}

	TTF_Font *
	SDL_Font::font() const
	{
		return handle;
	}
}
