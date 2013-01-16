void plot4points(SDL_Surface *dest,int cx,int cy,int x,int y,Uint32 color){
	if(x!=0 && y!=0)if(cy-y>=0 && cy-y<dest->h)
		for(int a=highint(0,cx-x);a<lowint(dest->w,cx+x);a++)
			putpixel(dest,a,cy-y,color);
	if(x!=0)if(cy+y>=0 && cy+y<dest->h)
		for(int a=highint(0,cx-x);a<lowint(dest->w,cx+x);a++)
			putpixel(dest,a,cy+y,color);
}

void drawcircle(SDL_Surface *dest,int cx,int cy,int radius,Uint32 color){
	int error = -radius;
	int x = radius;
	int y = 0;
	while(x >= y){
		plot4points(dest,cx,cy,x,y,color);
		if(x!=y)plot4points(dest,cx,cy,y,x,color);
		error += y;
		++y;
		error += y;
		if (error >= 0){
			--x;
			error -= x;
			error -= x;
		}
	}
}

void antiplot4points(SDL_Surface *dest,int cx,int cy,int x,int y,Uint32 color){
	SDL_Rect temprect={0,0,0,1};
	if(y!=0 && cy-y>=0 && cy-y<dest->h){
		temprect.y=cy-y;
		if(lowint(dest->w,cx-x)>0){
			temprect.x=0;
			temprect.w=lowint(dest->w,cx-x);
			SDL_FillRect(dest,&temprect,color);
		}
		if(lowint(dest->w,cx+x)>0){
			temprect.x=lowint(dest->w,cx+x);
			temprect.w=dest->w-lowint(dest->w,cx-x);
			SDL_FillRect(dest,&temprect,color);
		}
	}
	if(cy+y>=0 && cy+y<dest->h){
		temprect.y=cy+y;
		if(lowint(dest->w,cx-x)>0){
			temprect.x=0;
			temprect.w=lowint(dest->w,cx-x);
			SDL_FillRect(dest,&temprect,color);
		}
		if(lowint(dest->w,cx+x)>0){
			temprect.x=lowint(dest->w,cx+x);
			temprect.w=dest->w-lowint(dest->w,cx-x);
			SDL_FillRect(dest,&temprect,color);
		}
	}
}

void drawanticircle(SDL_Surface *dest,int cx,int cy,int radius,Uint32 color){
	SDL_Rect temprect = {0,0,dest->w,dest->h};
	temprect.h=cy-radius;
	if(cy-radius>0)SDL_FillRect(dest,&temprect,color);
	temprect.y=cy+radius;
	temprect.h=dest->h-cy-radius;
	if(dest->h-cy-radius>0)SDL_FillRect(dest,&temprect,color);
	int error = -radius;
	int x = radius;
	int y = 0;
	while(x >= y){
		if(x!=0){
			antiplot4points(dest,cx,cy,x,y,color);
			if(x!=y)antiplot4points(dest,cx,cy,y,x,color);
		}
		error += y;
		++y;
		error += y;
		if (error >= 0){
			--x;
			error -= x;
			error -= x;
		}
	}
}