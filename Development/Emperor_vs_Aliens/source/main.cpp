#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#ifdef PS3
	#include <sysutil/msg.h>
	#include <sysutil/sysutil.h>
	#include <io/pad.h>
	padInfo padinfo;
	padData paddata;
	#define audioPath "/dev_hdd0/game/EMPALIENS/USRDIR/data/sounds/thunder/0.ogg"
	#define splash1 "/dev_hdd0/game/EMPALIENS/USRDIR/data/images/splash1.png"
	#define splash2 "/dev_hdd0/game/EMPALIENS/USRDIR/data/images/splash2.png"
	#define logo "/dev_hdd0/game/EMPALIENS/USRDIR/data/images/ICON0.png"
	#define FontPath "/dev_hdd0/game/EMPALIENS/USRDIR/data/fonts/font.ttf"

#else
	#define audioPath "data/sounds/thunder/0.ogg"
	#define splash1 "data/images/splash1.png"
	#define splash2 "data/images/splash2.png"
	#define logo "data/images/ICON0.png"
	#define FontPath "data/fonts/font.ttf"
#endif
SDL_Event event;

Mix_Music *music = NULL;

void makeSound(){
	music = Mix_LoadMUS((const char*)audioPath);
	Mix_PlayMusic(music, 0);
}

SDL_Surface *Load_Image(char file[256]){
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(file);
	if(loadedImage!=NULL){
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	return optimizedImage;
}

void draw_surface(SDL_Surface* destination, SDL_Surface* source, int x, int y){
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( source, NULL, destination, &offset );
}

#ifdef PS3
int main (s32 argc, const char* argv[]){
#else
int main (int argc, const char* argv[]){
#endif
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = NULL;
	IMG_Init(IMG_INIT_PNG);
  	TTF_Init();

	SDL_WM_SetCaption("Emperor VS Aliens", "Emperor VS Aliens");
	SDL_WM_SetIcon(SDL_LoadBMP("data/images/ICON0.bmp"), NULL);


	screen = SDL_SetVideoMode(1024, 768, 32 ,SDL_SWSURFACE|SDL_DOUBLEBUF);

	if (!screen)
	{
		fprintf(stderr, "Nao foi possivel inicializar o video"
			"com as configuracoes indicadas: %s\n",
			SDL_GetError());
		return -2;
	}

	Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 );

	SDL_Surface *image = NULL;

	image = Load_Image(splash1);
	draw_surface(screen, image, 256,256);
	SDL_Flip(screen);
	SDL_Delay(2000);
	makeSound();
	
	
	image = Load_Image(splash2);
	draw_surface(screen, image, 256,256);
	SDL_Flip(screen);
	SDL_Delay(3000);
	
	SDL_FillRect(screen,NULL,0);	
	image = Load_Image(logo);
	draw_surface(screen, image, 128,128);
	SDL_Flip(screen);
	
	TTF_Font *Sans = TTF_OpenFont( FontPath , 20.0 );
	SDL_Color WHITE = { 255, 255, 255};
	SDL_Surface *txt = NULL;

	txt = TTF_RenderText_Blended( Sans, "EMPEROR VS ALIENS   V-0.1.0", WHITE);
	draw_surface(screen, txt, 400, 50);
	
	SDL_Flip(screen);
	
	SDL_Delay(4000);
	
	SDL_FreeSurface(image);
	SDL_FreeSurface(txt);
	SDL_FreeSurface(screen);
	TTF_CloseFont(Sans);
	Mix_FreeMusic(music);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	
	return 0;
}
