#ifdef WII
SDL_Surface *lodepng_loadsdlsurface(const char* filename){
	//load and decode the file
	std::vector<unsigned char> buffer, image;
	LodePNG::loadFile(buffer, filename);
	LodePNG::Decoder decoder;
	decoder.decode(image, buffer);
	//get width, height and pixels
	unsigned w = decoder.getWidth(), h =  decoder.getHeight();
	//stop if there is an error
	if(decoder.hasError())return NULL;
	//make the surface
	SDL_Surface* loadedImage = SDL_CreateRGBSurface(
		screen->flags,
		w,h,32,
		0x000000FF,
		0x0000FF00,
		0x00FF0000,
		0xFF000000);
	//plot the pixels of the PNG file
	for(unsigned y=0; y<h; y++)
	for(unsigned x=0; x<w; x++){
		//get RGBA components
		Uint32 r = image[4 * y * w + 4 * x + 0]; //red
		Uint32 g = image[4 * y * w + 4 * x + 1]; //green
		Uint32 b = image[4 * y * w + 4 * x + 2]; //blue
		Uint32 a = image[4 * y * w + 4 * x + 3]; //alpha
		//put the pixel data onto the surface
		SDL_Rect temprect={x,y,1,1};
		SDL_FillRect(loadedImage,&temprect,SDL_MapRGBA(loadedImage->format,r,g,b,a));
	}
	//return the surface
	return loadedImage;
}
#endif

SDL_Surface *IMG_LoadOptimize( std::string filename ){
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL; 
	#ifdef WII	
	loadedImage = lodepng_loadsdlsurface(filename.c_str());
	#else
	loadedImage = IMG_Load( filename.c_str() );
	#endif
	if( loadedImage != NULL ){
		optimizedImage = SDL_DisplayFormat( loadedImage );
		SDL_FreeSurface( loadedImage );
	} 
	return optimizedImage;
}

SDL_Surface *IMG_LoadOptimizeWithColorKey( std::string filename ){
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	#ifdef WII	
	loadedImage = lodepng_loadsdlsurface(filename.c_str());
	#else
	loadedImage = IMG_Load( filename.c_str() );
	#endif
	if( loadedImage != NULL ){
		optimizedImage = SDL_DisplayFormat( loadedImage );
		Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
		SDL_FreeSurface( loadedImage );
	} 
	return optimizedImage;
}

SDL_Surface *IMG_LoadOptimizeAlpha( std::string filename ){
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL; 
	#ifdef WII	
	loadedImage = lodepng_loadsdlsurface(filename.c_str());
	#else
	loadedImage = IMG_Load( filename.c_str() );
	#endif
	if( loadedImage != NULL ){
		optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
		SDL_FreeSurface( loadedImage );
	} 
	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ){
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( source, clip, destination, &offset );
}
