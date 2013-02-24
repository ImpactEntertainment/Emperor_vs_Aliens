#include <iostream>
#include <cstdlib>

#include "video.hpp"

using namespace std;

void init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO)== -1)
	{
		cerr << "Erro na inicializacao da SDL: " << SDL_GetError() << endl;
		exit(-1);
	}

	atexit(SDL_Quit);
}

void setup_window()
{
	const string appName = "Emperor VS Aliens";
	const string resourcesDirectory = "data/";

	string icon = "images/ICON0.bmp";
	string iconPath = resourcesDirectory + icon;

	SDL_WM_SetCaption(appName.c_str(), appName.c_str());
	SDL_WM_SetIcon(SDL_LoadBMP(iconPath.c_str()), NULL);
}

SDL_Surface * setup_video()
{
	SDL_Surface *screen = NULL;
	int width = 1024, height = 768, bitsPerPixel = 32;
	Uint32 videoOptions = SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN;

	screen = SDL_SetVideoMode(width, height, bitsPerPixel, videoOptions);

	if (!screen)
	{
		cerr << "Nao foi possivel inicializar o video com as configuracoes " 
			<< "indicadas: " << SDL_GetError() << endl;
		exit(-2);
	}

	return screen;
}

