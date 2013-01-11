#include <stdio.h>
#include <fstream>
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
	char audioPath[]="/dev_hdd0/game/EMPALIENS/USRDIR/data/sounds/start_round.ogg";
	char imagePath[]="/dev_hdd0/game/EMPALIENS/USRDIR/data/images/ICON0.png";
	char FontPath[]="/dev_hdd0/game/EMPALIENS/USRDIR/data/fonts/font.ttf";

#else
	char audioPath[]="data/sounds/start_round.ogg";
	char imagePath[]="data/images/ICON0.png";
	char FontPath[]="data/fonts/font.ttf";
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
  screen = SDL_SetVideoMode(1024, 768, 32 ,SDL_FULLSCREEN|SDL_SWSURFACE|SDL_DOUBLEBUF);
  Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 );

  SDL_Surface *image = NULL;

  image = Load_Image(imagePath);
  draw_surface(screen, image, 1024/4,168/4);

  TTF_Font *Sans = TTF_OpenFont( FontPath , 20.0 );
  SDL_Color WHITE = { 255, 255, 255};
  SDL_Surface *txt = NULL;
  
  txt = TTF_RenderText_Blended( Sans, "Press /\\ to make a sound and START to exit.", WHITE);
  draw_surface(screen, txt, 100, 50);
  
  
  

  while (1) {
    #ifdef PS3
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
	#else
    makeSound();
    #endif
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
  #ifdef PS3
  ioPadEnd();
  #endif
  return 0;
}

