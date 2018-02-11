#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "Functions.h"

class GameStates
{
private:
public:
	virtual void handle_input() = 0;
	virtual void logic() = 0;
	virtual void renderOutput() = 0;
};

class Title : public GameStates
{
private:
//holds mouse coordinates
int mX;
int mY;

//stores what button the user is hovering over
int whichButton;

//holds title sheet
SDL_Surface * titleWord;

//holds buttons sheet
SDL_Surface * buttonSheet;

//enum used for different button types (YES means hovered and NO means unhovered)
//used in conjunction with buttonLocation array
enum buttons
{
	ONEPLAYERNO = 0,
	ONEPLAYERYES,
	TWOPLAYERNO,
	TWOPLAYERYES,
	THREEPLAYERNO,
	THREEPLAYERYES,
	FOURPLAYERNO,
	FOURPLAYERYES,
	MUSICSETUPNO,
	MUSICSETUPYES,
	EXITNO,
	EXITYES,
};

//rectangle that contains non-highlighted button coordinates
SDL_Rect buttonLocation[12];

public:
	Title();
	~Title();
	void handle_input();
	void logic();
	void renderOutput();
};

class MainGame : public GameStates
{
private:
	class Bar
	{
	private:
		//location of bar
		int x;
		int y;

		//dimensions of board
		int bX;
		int bY;
		int bW;
		int bH;

		//time since bar was created
		Timer time;
		//time from creation that the bar must hit the bottom
		const static int songTime = SPEED;
		//width of bar
		int width;
		//height of bar
		int height;
		//distance to bottom that the bar must reach in songTime
		int distanceToBar;
	public:
		Bar(int x, int y, int w, int h);
		SDL_Rect getRect();
		bool logic();
		void render();
	};

	class Board
	{
	private:
		//dimensions of board
		int x;
		int y;
		int w;
		int h;

		//score
		int score;

		//holds all bars
		std::deque <Bar> bars;

		//font
		TTF_Font * font;
		SDL_Color color;
		SDL_Surface * textSurface;

	public:
		Board();
		~Board();
		void setDimensions(int inputX, int inputY, int inputW, int inputH);
		void incrementScore();
		void decrementScore();
		int getScore();
		bool empty();
		void addBar();
		void buttonHit();
		void logic();
		void render();
	};

	Board * boards;

	//the times (in milliseconds that the bars should hit the bottom of the screen)
	std::queue<int> times;

	Mix_Music * music;

	//timer used for music times
	Timer mainTimer;
	
	//gamepads used for input
	SDL_Joystick ** sticks;

public:
	MainGame();
	~MainGame();
	void handle_input();
	void logic();
	void renderOutput();
};

class ResultsScreen : public GameStates
{
private:
	//timer to progress score
	Timer scoreTimer;

	//font
	TTF_Font * fontTitle;
	TTF_Font * fontScores;
	SDL_Color color;
	SDL_Surface * textSurface;
public:
	ResultsScreen();
	~ResultsScreen();
	void handle_input();
	void logic();
	void renderOutput();
};

#endif