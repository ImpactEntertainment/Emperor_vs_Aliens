#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <io/pad.h>

#include <sysutil/msg.h>
#include <sysutil/sysutil.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

char audioPath[]="/dev_hdd0/game/EMPALIENS/data/sound/start.round.mp3";

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

int main (s32 argc, const char* argv[]){
  padInfo padinfo;
  padData paddata;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Surface* screen = NULL;
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
  screen = SDL_SetVideoMode(1280, 720, 32 ,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
  Mix_OpenAudio( AUDIO_S16MSB, MIX_DEFAULT_FORMAT, 2, 1024 );

  SDL_Surface *image = NULL;

  char imagePath[]="/dev_hdd0/game/EMPALIENS/data/images/ICON0.PNG";
  char FontPath[]="/dev_hdd0/game/SDL00TEST/font.ttf";


  image = Load_Image(imagePath);
  draw_surface(screen, image, 1280/4,720/4);

  TTF_Font *Sans = TTF_OpenFont( FontPath , 20.0 );
  SDL_Color WHITE = { 255, 255, 255};
  SDL_Surface *txt = NULL;
  
  txt = TTF_RenderText_Blended( Sans, "Press /\\ to make a sound and START to exit.", WHITE);
  draw_surface(screen, txt, 100, 50);
  
  
  
  
  while (1) {
    ioPadGetInfo (&padinfo);
    for(int i = 0; i < MAX_PADS; i++) {
        if(padinfo.status[i]) {
            ioPadGetData (i, &paddata);
            if(paddata.BTN_START) {
              goto end;
            }
            if(paddata.BTN_TRIANGLE) {
              makeSound();
            }
        }
    }
    SDL_Flip(screen);
  }

  end:

  SDL_FreeSurface(image);
  SDL_FreeSurface(txt);
  SDL_FreeSurface(screen);
  TTF_CloseFont(Sans);
  Mix_FreeMusic(music);
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
  ioPadEnd();
  return 0;
}

