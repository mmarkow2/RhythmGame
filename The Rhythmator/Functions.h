#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <fstream>
#include <sstream>
#include <queue>
#include <deque>

extern bool quitBool;
extern bool mainGameBool;
extern bool resultsScreenBool;
extern SDL_Surface * window;

extern SDL_Event mainEvent;

extern int p1Score;
extern int p2Score;
extern int p3Score;
extern int p4Score;



const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int DISTANCE_BETWEEN_BOARDS = 20;
const int DISTANCE_TO_EDGE = 50;
const int DISTANCE_TO_TOP = 100;
extern int numPlayers;



const int BPP = 32;
const int BOARD_BAR_WIDTH = 20;
//smaller is faster
const int SPEED = 500;
const int BOTTOMBARABOVEBOTTOMAMOUNT = 200;
const int BARCENTEREDAMOUNT = 50;
const int BARHEIGHT = 50;
const int GHOSTBAREXTENSION = 20;
const int SCOREABOVETOP = 50;

const int SPACEBETWEENSCORES = 300;
const int DISTANCE_TO_TOP_SCORES = 500;

/*
 *  Functions.h
 *  Pac Man Game
 *
 *  Created by Matthew Markowitz on 4/8/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

void init();

void quit();

class Timer
{
private:
	int starttime;
public:
	Timer();
	void start();
	int getTime();
};

SDL_Surface * load_image(const char * input, Uint32 colorkey);
void apply_image(int x, int y, SDL_Surface * image);
void apply_image(int x, int y, SDL_Surface * image, SDL_Rect * clipLocation);
void apply_rect(int x, int y, int w, int h, Uint32 color);
bool rectangularCollision(SDL_Rect rect1, SDL_Rect rect2);
bool rectangularCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif