// Autor: Edson Alves
// Data: 26/12/2012
// e-mail: edsonalves@unb.br
#include <iostream>
#include <SDL/SDL.h>

#include "draw.h"
#include "video.h"

using namespace std;

int main()
{
	init_sdl();
	setup_window();
	SDL_Surface *screen = setup_video();
	draw(screen);
	
	SDL_SaveBMP(screen, "screenshot.bmp");

	SDL_Delay(3000);

	return 0;
}

