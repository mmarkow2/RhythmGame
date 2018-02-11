/*
 *  Functions.cpp
 *  Pac Man Game
 *
 *  Created by Matthew Markowitz on 4/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Functions.h"

bool quitBool = false;
bool mainGameBool = false;
bool resultsScreenBool = false;
SDL_Surface * window;
int p1Score = 0;
int p2Score = 0;
int p3Score = 0;
int p4Score = 0;
int numPlayers = 0;

void init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	TTF_Init();
	window = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BPP, SDL_SWSURFACE | SDL_FULLSCREEN);
}

void quit()
{
	SDL_Quit();
	TTF_Quit();
	Mix_CloseAudio();
}

Timer::Timer()
{
	starttime = 0;
}

void Timer::start()
{
	starttime = SDL_GetTicks();
}

int Timer::getTime()
{
	return (SDL_GetTicks() - starttime);
}

SDL_Surface * load_image(const char * input, Uint32 colorkey)
{
	SDL_Surface * loadedImage = NULL;
	SDL_Surface * optimizedImage = NULL;
	
	loadedImage = SDL_LoadBMP(input);
	if (loadedImage == NULL)
	{
		return NULL;
	}
	if (colorkey >= 0)
	{
		SDL_SetColorKey(loadedImage, SDL_SRCCOLORKEY, colorkey);
	}

	optimizedImage = SDL_DisplayFormat(loadedImage);
	if (optimizedImage == NULL)
	{
		return loadedImage;
	}
	
	return optimizedImage;
}

void apply_image(int x, int y, SDL_Surface * image)
{
	SDL_Rect location;
	location.x = x;
	location.y = y;
	SDL_BlitSurface(image, NULL, window, &location);
}

void apply_image(int x, int y, SDL_Surface * image, SDL_Rect * clipLocation)
{
	SDL_Rect location;
	location.x = x;
	location.y = y;
	SDL_BlitSurface(image, clipLocation, window, &location);
}

void apply_rect(int x, int y, int w, int h, Uint32 color)
{
	SDL_Rect location;
	location.x = x;
	location.y = y;
	location.w = w;
	location.h = h;

	SDL_FillRect(window, &location, color);
}

bool rectangularCollision(SDL_Rect rect1, SDL_Rect rect2)
{
	if (rect1.x + rect1.w < rect2.x)
	{
		return false;
	}
	
	if (rect1.x > rect2.x + rect2.w)
	{
		return false;
	}
	
	if (rect1.y + rect1.h  < rect2.y)
	{
		return false;
	}
	
	if (rect1.y > rect2.y + rect2.h)
	{
		return false;
	}
	
	return true;
}

bool rectangularCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if (x1 + w1 < x2)
	{
		return false;
	}
	
	if (x1 > x2 + w2)
	{
		return false;
	}
	
	if (y1 + h1  < y2)
	{
		return false;
	}
	
	if (y1 > y2 + h2)
	{
		return false;
	}
	
	return true;
}




