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
	#define logo "/dev_hdd0/game/EMPALIENS/USRDIR/data/images/impact/Logo_800_600.png"
	#define FontPath "/dev_hdd0/game/EMPALIENS/USRDIR/data/fonts/font.ttf"

#else
	#define audioPath "data/sounds/thunder/0.ogg"
	#define splash1 "data/images/splash1.png"
	#define splash2 "data/images/splash2.png"
	#define logo "data/images/impact/Logo_800_600.png"
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

void screenLogo (SDL_Surface* screen){
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

	txt = TTF_RenderText_Blended( Sans, "EMPEROR VS ALIENS   V-0.2.0", WHITE);
	draw_surface(screen, txt, 400, 50);
	
	SDL_Flip(screen);
	
	SDL_Delay(4000);
	SDL_FreeSurface(txt);
	SDL_FreeSurface(image);
	TTF_CloseFont(Sans);
	Mix_FreeMusic(music);
	
}


void draw(SDL_Surface *screen){
	SDL_FillRect(screen,NULL,0); //limpar tela  
	// Tabuleiro 
	SDL_Color white;
	white.r = white.g = white.b = 255;
	
	SDL_Color darkgray;
	darkgray.r = darkgray.g = darkgray.b = 60;
	
	SDL_Color gray;
	gray.r = gray.g = gray.b = 127;
	
	SDL_Color lightgray;
	lightgray.r = lightgray.g = lightgray.b = 190;
	
	SDL_Color blue;
	blue.r = 50;
	blue.g = 50;
	blue.b = 255;

	SDL_Color lightgreen;
	lightgreen.r = 90;
	lightgreen.g = 200;
	lightgreen.b = 100;

	SDL_Color darkgreen;
	darkgreen.r = 0;
	darkgreen.g = 80;
	darkgreen.b = 10;
	
	SDL_Color middlegreen;
	middlegreen.r = 20;
	middlegreen.g = 170;
	middlegreen.b = 40;

	SDL_Color grassgreen;
	grassgreen.r = 150;
	grassgreen.g = 230;
	grassgreen.b = 30;


	SDL_Color yellow;
	yellow.r = 230;
	yellow.g = 230;
	yellow.b = 90;
	
	SDL_Color lightpink;
	lightpink.r = 240;
	lightpink.g = 180;
	lightpink.b = 240;
	
	SDL_PixelFormat *format = screen->format;

	Uint32 whitePixel = SDL_MapRGB(format, white.r, white.g, white.b);
	Uint32 darkgrayPixel = SDL_MapRGB(format, darkgray.r, darkgray.g, darkgray.b);
	Uint32 grayPixel = SDL_MapRGB(format, gray.r, gray.g, gray.b);
	Uint32 lightgrayPixel = SDL_MapRGB(format, lightgray.r, lightgray.g, lightgray.b);
	Uint32 bluePixel = SDL_MapRGB(format, blue.r, blue.g, blue.b);
	Uint32 lightgreenPixel = SDL_MapRGB(format, lightgreen.r, lightgreen.g, lightgreen.b);
	Uint32 darkgreenPixel = SDL_MapRGB(format, darkgreen.r, darkgreen.g, darkgreen.b);
	Uint32 middlegreenPixel = SDL_MapRGB(format, middlegreen.r, middlegreen.g, middlegreen.b);
	Uint32 grassgreenPixel = SDL_MapRGB(format, grassgreen.r, grassgreen.g, grassgreen.b);
	Uint32 yellowPixel = SDL_MapRGB(format, yellow.r, yellow.g, yellow.b);	
	Uint32 lightpinkPixel = SDL_MapRGB(format, lightpink.r, lightpink.g, lightpink.b);	
	

	SDL_Rect sky;
	sky.x = 0;
	sky.y = 0;
	sky.w = 800;
	sky.h = 300;

	SDL_FillRect(screen, &sky, bluePixel);
	
	SDL_Rect ground;
	ground.x = 0;
	ground.y = 300;
	ground.w = 800;
	ground.h = 300;

	SDL_FillRect(screen, &ground, lightgreenPixel);

	SDL_Rect mountainleft;
	mountainleft.x = 25;
	mountainleft.y = 170;
	mountainleft.w = 380;
	mountainleft.h = 150;

	SDL_FillRect(screen, &mountainleft, darkgreenPixel);

	SDL_Rect mountainright;
	mountainright.x = 430;
	mountainright.y = 150;
	mountainright.w = 300;
	mountainright.h = 180;

	SDL_FillRect(screen, &mountainright, middlegreenPixel);

	SDL_Rect sun;
	sun.x = 360;
	sun.y = 30;
	sun.w = 80;
	sun.h = 80;

	SDL_FillRect(screen, &sun, yellowPixel);


	SDL_Rect wall;
	wall.x = 5;
	wall.y = 290;
	wall.w = 80;
	wall.h = 310;

	SDL_FillRect(screen, &wall, grayPixel);

	SDL_Rect cloudleft;
	cloudleft.x = 105;
	cloudleft.y = 25;
	cloudleft.w = 80;
	cloudleft.h = 50;

	SDL_FillRect(screen, &cloudleft, whitePixel);

	SDL_Rect cloudright;
	cloudright.x = 405;
	cloudright.y = 35;
	cloudright.w = 80;
	cloudright.h = 50;

	SDL_FillRect(screen, &cloudright, whitePixel);
	
	SDL_Rect rockA;
	rockA.x = 280;
	rockA.y = 350;
	rockA.w = 40;
	rockA.h = 40;

	SDL_FillRect(screen, &rockA, darkgrayPixel);
	
	SDL_Rect rockB;
	rockB.x = 255;
	rockB.y = 520;
	rockB.w = 40;
	rockB.h = 40;

	SDL_FillRect(screen, &rockB, darkgrayPixel);
	
	SDL_Rect rockC;
	rockC.x = 480;
	rockC.y = 380;
	rockC.w = 40;
	rockC.h = 40;

	SDL_FillRect(screen, &rockC, darkgrayPixel);
	
	SDL_Rect rockD;
	rockD.x = 460;
	rockD.y = 540;
	rockD.w = 40;
	rockD.h = 40;

	SDL_FillRect(screen, &rockD, darkgrayPixel);
	
	SDL_Rect leafsA;
	leafsA.x = 420;
	leafsA.y = 350;
	leafsA.w = 60;
	leafsA.h = 60;

	SDL_FillRect(screen, &leafsA, lightpinkPixel);

	SDL_Rect woodA;
	woodA.x = 440;
	woodA.y = 410;
	woodA.w = 20;
	woodA.h = 60;

	SDL_FillRect(screen, &woodA, lightgrayPixel);
	
	SDL_Rect leafsB;
	leafsB.x = 590;
	leafsB.y = 480;
	leafsB.w = 60;
	leafsB.h = 60;

	SDL_FillRect(screen, &leafsB, lightpinkPixel);

	SDL_Rect woodB;
	woodB.x = 610;
	woodB.y = 540;
	woodB.w = 20;
	woodB.h = 60;

	SDL_FillRect(screen, &woodB, lightgrayPixel);
	
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}






#ifdef PS3
int main (s32 argc, const char* argv[]){
#else
int main (){
#endif
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = NULL;
	IMG_Init(IMG_INIT_PNG);
  	TTF_Init();

	SDL_WM_SetCaption("Emperor VS Aliens", "Emperor VS Aliens");
	SDL_WM_SetIcon(SDL_LoadBMP("data/images/ICON0.bmp"), NULL);


	screen = SDL_SetVideoMode(800, 600, 32 ,SDL_SWSURFACE|SDL_DOUBLEBUF);

	if (!screen)
	{
		fprintf(stderr, "Nao foi possivel inicializar o video"
			"com as configuracoes indicadas: %s\n",
			SDL_GetError());
		return -2;
	}

	
    //screenLogo(screen);
    
    draw(screen);
    SDL_Delay(2000);
    
    SDL_FreeSurface(screen);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	
	return 0;
}
