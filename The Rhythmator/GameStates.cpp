#include "GameStates.h"

Title::Title()
{
	mX = 0;
	mY = 0;
	whichButton = 0;
	titleWord = load_image("Title/Title.bmp", -1);
	buttonSheet = load_image("Title/Buttons.bmp", -1);

#pragma region ButtonLocations
	buttonLocation[ONEPLAYERNO].x = 0;
	buttonLocation[ONEPLAYERNO].y = 0;
	buttonLocation[ONEPLAYERNO].w = 353;
	buttonLocation[ONEPLAYERNO].h = 74;

	buttonLocation[ONEPLAYERYES].x = 355;
	buttonLocation[ONEPLAYERYES].y = 0;
	buttonLocation[ONEPLAYERYES].w = 353;
	buttonLocation[ONEPLAYERYES].h = 74;

	buttonLocation[TWOPLAYERNO].x = 0;
	buttonLocation[TWOPLAYERNO].y = 75;
	buttonLocation[TWOPLAYERNO].w = 353;
	buttonLocation[TWOPLAYERNO].h = 74;

	buttonLocation[TWOPLAYERYES].x = 355;
	buttonLocation[TWOPLAYERYES].y = 75;
	buttonLocation[TWOPLAYERYES].w = 353;
	buttonLocation[TWOPLAYERYES].h = 74;

	buttonLocation[THREEPLAYERNO].x = 0;
	buttonLocation[THREEPLAYERNO].y = 150;
	buttonLocation[THREEPLAYERNO].w = 353;
	buttonLocation[THREEPLAYERNO].h = 74;

	buttonLocation[THREEPLAYERYES].x = 355;
	buttonLocation[THREEPLAYERYES].y = 150;
	buttonLocation[THREEPLAYERYES].w = 353;
	buttonLocation[THREEPLAYERYES].h = 74;

	buttonLocation[FOURPLAYERNO].x = 0;
	buttonLocation[FOURPLAYERNO].y = 225;
	buttonLocation[FOURPLAYERNO].w = 353;
	buttonLocation[FOURPLAYERNO].h = 74;

	buttonLocation[FOURPLAYERYES].x = 355;
	buttonLocation[FOURPLAYERYES].y = 225;
	buttonLocation[FOURPLAYERYES].w = 353;
	buttonLocation[FOURPLAYERYES].h = 74;

	buttonLocation[MUSICSETUPNO].x = 0;
	buttonLocation[MUSICSETUPNO].y = 300;
	buttonLocation[MUSICSETUPNO].w = 353;
	buttonLocation[MUSICSETUPNO].h = 74;

	buttonLocation[MUSICSETUPYES].x = 355;
	buttonLocation[MUSICSETUPYES].y = 300;
	buttonLocation[MUSICSETUPYES].w = 353;
	buttonLocation[MUSICSETUPYES].h = 74;

	buttonLocation[EXITNO].x = 0;
	buttonLocation[EXITNO].y = 375;
	buttonLocation[EXITNO].w = 353;
	buttonLocation[EXITNO].h = 74;

	buttonLocation[EXITYES].x = 355;
	buttonLocation[EXITYES].y = 375;
	buttonLocation[EXITYES].w = 353;
	buttonLocation[EXITYES].h = 74;
#pragma endregion

}

Title::~Title()
{
	SDL_FreeSurface(titleWord);
	SDL_FreeSurface(buttonSheet);
}

void Title::handle_input()
{
	if (mainEvent.type == SDL_MOUSEMOTION)
	{
		mX = mainEvent.motion.x;
		mY = mainEvent.motion.y;
	}
	else if (mainEvent.type == SDL_MOUSEBUTTONUP)
	{
		if (mainEvent.button.button == SDL_BUTTON_LEFT)
		{
			switch (whichButton)
			{
			case ONEPLAYERYES:
				numPlayers = 1;
				mainGameBool = true;
				break;
			case TWOPLAYERYES:
				numPlayers = 2;
				mainGameBool = true;
				break;
			case THREEPLAYERYES:
				numPlayers = 3;
				mainGameBool = true;
				break;
			case FOURPLAYERYES:
				numPlayers = 4;
				mainGameBool = true;
				break;
			case MUSICSETUPYES:
				break;
			case EXITYES:
				quitBool = true;
				break;
			default:
				break;
			}
		}
	}
}

void Title::logic()
{
	//if the user hovers over one player
	if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[ONEPLAYERNO].w / 2), 250, buttonLocation[ONEPLAYERNO].w, buttonLocation[ONEPLAYERNO].h))
	{
		whichButton = ONEPLAYERYES;
	}
	//if the user hovers over two player
	else if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[TWOPLAYERNO].w / 2), 350, buttonLocation[TWOPLAYERNO].w, buttonLocation[TWOPLAYERNO].h))
	{
		whichButton = TWOPLAYERYES;
	}
	//if the user hovers over three player
	else if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[THREEPLAYERNO].w / 2), 450, buttonLocation[THREEPLAYERNO].w, buttonLocation[THREEPLAYERNO].h))
	{
		whichButton = THREEPLAYERYES;
	}
	//if the user hovers over four player
	else if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[FOURPLAYERNO].w / 2), 550, buttonLocation[FOURPLAYERNO].w, buttonLocation[FOURPLAYERNO].h))
	{
		whichButton = FOURPLAYERYES;
	}
	//if the user hovers over music setup
	else if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[MUSICSETUPNO].w / 2), 650, buttonLocation[MUSICSETUPNO].w, buttonLocation[MUSICSETUPNO].h))
	{
		whichButton = MUSICSETUPYES;
	}
	//if the user hovers over exit
	else if (rectangularCollision(mX, mY, 0, 0, (SCREEN_WIDTH / 2) - (buttonLocation[ONEPLAYERNO].w / 2), 750, buttonLocation[ONEPLAYERNO].w, buttonLocation[ONEPLAYERNO].h))
	{
		whichButton = EXITYES;
	}
	//if the user hovers over nothing
	else
	{
		whichButton = -1;
	}
}

void Title::renderOutput()
{
	//clear screen
	SDL_FillRect(window, &(window->clip_rect), SDL_MapRGB(window->format, 0, 0, 0));

	//apply title
	apply_image((SCREEN_WIDTH / 2) - (titleWord->w / 2), 50, titleWord);

	//One Player
	if (whichButton == ONEPLAYERYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[ONEPLAYERYES].w / 2), 250, buttonSheet, &buttonLocation[ONEPLAYERYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[ONEPLAYERNO].w / 2), 250, buttonSheet, &buttonLocation[ONEPLAYERNO]);
	}

	//Two Player
	if (whichButton == TWOPLAYERYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[TWOPLAYERYES].w / 2), 350, buttonSheet, &buttonLocation[TWOPLAYERYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[TWOPLAYERNO].w / 2), 350, buttonSheet, &buttonLocation[TWOPLAYERNO]);
	}

	//Three Player
	if (whichButton == THREEPLAYERYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[THREEPLAYERYES].w / 2), 450, buttonSheet, &buttonLocation[THREEPLAYERYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[THREEPLAYERNO].w / 2), 450, buttonSheet, &buttonLocation[THREEPLAYERNO]);
	}

	//Four Player
	if (whichButton == FOURPLAYERYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[FOURPLAYERYES].w / 2), 550, buttonSheet, &buttonLocation[FOURPLAYERYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[FOURPLAYERNO].w / 2), 550, buttonSheet, &buttonLocation[FOURPLAYERNO]);
	}

	//Music Setup Player
	if (whichButton == MUSICSETUPYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[MUSICSETUPYES].w / 2), 650, buttonSheet, &buttonLocation[MUSICSETUPYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[MUSICSETUPNO].w / 2), 650, buttonSheet, &buttonLocation[MUSICSETUPNO]);
	}

	//Exit
	if (whichButton == EXITYES)
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[EXITYES].w / 2), 750, buttonSheet, &buttonLocation[EXITYES]);
	}
	else
	{
		apply_image((SCREEN_WIDTH / 2) - (buttonLocation[EXITNO].w / 2), 750, buttonSheet, &buttonLocation[EXITNO]);
	}

}


MainGame::Bar::Bar(int x, int y, int w, int h)
{
	bX = x;
	bY = y;
	bW = w;
	bH = h;

	width = bW - (2 * BOARD_BAR_WIDTH) - (2 * BARCENTEREDAMOUNT);
	height = BARHEIGHT;

	time.start();

	//BARHEIGHT is added to accomodate the bars entering
	distanceToBar = bH - BOTTOMBARABOVEBOTTOMAMOUNT - BOARD_BAR_WIDTH + BARHEIGHT;
}

SDL_Rect MainGame::Bar::getRect()
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	return rect;
}

//returns true if bar should be popped
bool MainGame::Bar::logic()
{
	//center bar in board
	x = ((2 * bX + bW) / 2) - (width / 2);
	//find distance to bottom and add it to board y BarHEIGHT is used to raise bar above top
	y = static_cast<int>((bY + ((static_cast<double>(time.getTime()) / songTime) * distanceToBar)) - BARHEIGHT);

	if (y > bY + bH)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MainGame::Bar::render()
{
	apply_rect(x, y, width, height, SDL_MapRGB(window->format, 255, 0, 0));
}

MainGame::Board::Board()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;

	score = 0;

	font = TTF_OpenFont("MainGame/calibri.ttf", 32);
	color.r = 255;
	color.g = 255;
	color.b = 255;
}

MainGame::Board::~Board()
{
	TTF_CloseFont(font);
}

void MainGame::Board::setDimensions(int inputX, int inputY, int inputW, int inputH)
{
	x = inputX;
	y = inputY;
	w = inputW;
	h = inputH;
}

void MainGame::Board::incrementScore()
{
	score += 100;
}

void MainGame::Board::decrementScore()
{
	score -= 100;
}

int MainGame::Board::getScore()
{
	return score;
}

bool MainGame::Board::empty()
{
	if (bars.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MainGame::Board::addBar()
{
	bars.push_back(Bar(x, y, w, h));
}

void MainGame::Board::buttonHit()
{
	if (!bars.empty())
	{
		//these are copys from render's apply_rect function
		SDL_Rect ghostBar;
		ghostBar.x = ((2 * x + w) / 2) - ((w - (2 * BOARD_BAR_WIDTH) - (2 * BARCENTEREDAMOUNT)) / 2);
		ghostBar.y = y + (h - BOTTOMBARABOVEBOTTOMAMOUNT - BOARD_BAR_WIDTH) - GHOSTBAREXTENSION;
		ghostBar.w = w - (2 * BOARD_BAR_WIDTH) - (2 * BARCENTEREDAMOUNT);
		ghostBar.h = BARHEIGHT + 2 * GHOSTBAREXTENSION;

		if (rectangularCollision(bars.front().getRect(), ghostBar))
		{
			incrementScore();
			bars.pop_front();
		}
	}
}

void MainGame::Board::logic()
{
	for (unsigned int i = 0; i < bars.size(); i++)
	{
		if (bars[i].logic())
		{
			bars.pop_front();
		}
	}
}

void MainGame::Board::render()
{
	//draw ghost bar (inputs are copy's from bar class's values)
	apply_rect (((2 * x + w) / 2) - ((w - (2 * BOARD_BAR_WIDTH) - (2 * BARCENTEREDAMOUNT)) / 2), y + (h - BOTTOMBARABOVEBOTTOMAMOUNT - BOARD_BAR_WIDTH), w - (2 * BOARD_BAR_WIDTH) - (2 * BARCENTEREDAMOUNT),BARHEIGHT, SDL_MapRGB(window->format, 0, 0, 255));

	//draw bars
	for (unsigned int i = 0; i < bars.size(); i++)
	{
		bars[i].render();
	}

	//draw board
	apply_rect(x, y, BOARD_BAR_WIDTH, h, SDL_MapRGB(window->format, 20, 20, 20));
	apply_rect(x, y + h - BOARD_BAR_WIDTH, w, BOARD_BAR_WIDTH, SDL_MapRGB(window->format, 20, 20, 20));
	apply_rect(x + w - BOARD_BAR_WIDTH, y, BOARD_BAR_WIDTH, h, SDL_MapRGB(window->format, 20, 20, 20));

	//cover bars on bottom and top
	apply_rect(x, y + h, w, BARHEIGHT, SDL_MapRGB(window->format, 0, 0, 0));
	apply_rect(x, y - BARHEIGHT, w, BARHEIGHT, SDL_MapRGB(window->format, 0, 0, 0));

	//adds score and Score: string together
	std::stringstream converter;
	converter<<"Score: "<<score;

	//draw score
	textSurface = TTF_RenderText_Solid(font, converter.str().c_str(), color);
	apply_image(((2 * x + w) / 2) - (textSurface->w / 2), y - BARHEIGHT, textSurface);
	SDL_FreeSurface(textSurface);
}

MainGame::MainGame()
{
	//this is allocated on the heap because the length of the array is not a compile-time constant
	boards = new Board[numPlayers];

	//temporary integers to simplify dimension assignment (they are unnecessary)
	int tX;
	int tY;
	int tW;
	int tH;

	//set dimensions for all players
	for (int i = 0; i < numPlayers; i++)
	{
		tY = DISTANCE_TO_TOP;
		tW = (SCREEN_WIDTH - (2 * DISTANCE_TO_EDGE) - ((numPlayers - 1) * DISTANCE_BETWEEN_BOARDS)) / numPlayers;
		tH = SCREEN_HEIGHT - (2 * DISTANCE_TO_TOP);

		if (i == 0)
		{
			tX = DISTANCE_TO_EDGE;
		}
		else
		{
			tX = DISTANCE_TO_EDGE + (i * tW) + (i * DISTANCE_BETWEEN_BOARDS);
		}
		boards[i].setDimensions(tX, tY, tW, tH);
	}

	//load the times into the game
	std::ifstream timeloader("Music/timing.time");
	for (int i = 0; timeloader>>i;)
	{
		times.push(i);
	}

	//loads the music into the game
	music = Mix_LoadMUS("Music/music.wav");

	//starts the music
	Mix_PlayMusic(music, 0);

	//starts the timer
	mainTimer.start();

	//initializes joysticks
	sticks = new SDL_Joystick * [SDL_NumJoysticks()];

	//loads joysticks
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		sticks[i] = SDL_JoystickOpen(i);
	}

	//hides mouse
	SDL_ShowCursor(0);
}

MainGame::~MainGame()
{
	delete[] boards;
	Mix_FreeMusic(music);

	//closes joysticks
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		SDL_JoystickClose(sticks[i]);
	}

	//save scores to external ints so they can be loaded in results screen
	for (int i = 0; i < numPlayers; i++)
	{
		if (i == 0)
		{
			p1Score = boards[i].getScore();
		}
		else if (i == 1)
		{
			p2Score = boards[i].getScore();
		}
		else if (i == 2)
		{
			p3Score = boards[i].getScore();
		}
		else
		{
			p4Score = boards[i].getScore();
		}
	}
}

void MainGame::handle_input()
{
	if (mainEvent.type == SDL_JOYBUTTONDOWN)
	{
		if (mainEvent.jbutton.which < numPlayers)
		{
			boards[mainEvent.jbutton.which].buttonHit();
		}
		mainEvent.type = NULL;
	}
}

void MainGame::logic()
{
	//if the times are empty, times.front() will cause a runtime error
	if (!times.empty())
	{
		if (mainTimer.getTime() > times.front() - SPEED)
		{
			//for each player
			for (int i = 0; i < numPlayers; i++)
			{
				boards[i].addBar();
			}
			times.pop();
		}
	}
	else
	{
		//if there are no more bars to be released and no bars present
		if (boards[0].empty())
		{
			resultsScreenBool = true;
		}
	}

	//for each player
	for (int i = 0; i < numPlayers; i++)
	{
		boards[i].logic();
	}
}

void MainGame::renderOutput()
{
	//clear screen
	SDL_FillRect(window, &(window->clip_rect), SDL_MapRGB(window->format, 0, 0, 0));

	//for each player
	for (int i = 0; i < numPlayers; i++)
	{
		boards[i].render();
	}

	SDL_Flip(window);
}


ResultsScreen::ResultsScreen()
{
	scoreTimer.start();

	fontTitle = TTF_OpenFont("MainGame/calibri.ttf", 72);
	fontScores = TTF_OpenFont("MainGame/calibri.ttf", 32);
	color.r = 255;
	color.g = 255;
	color.b = 255;
}

ResultsScreen::~ResultsScreen()
{
}

void ResultsScreen::handle_input()
{
}

void ResultsScreen::logic()
{
}

void ResultsScreen::renderOutput()
{
	//clear screen
	SDL_FillRect(window, &(window->clip_rect), SDL_MapRGB(window->format, 0, 0, 0));

	if (scoreTimer.getTime() >= 500 && scoreTimer.getTime() < 1000)
	{
		textSurface = TTF_RenderText_Solid(fontTitle, "Scores", color);
		apply_image((SCREEN_WIDTH / 2) - (textSurface->w / 2), (SCREEN_HEIGHT / 2) - (textSurface->h / 2), textSurface);
		SDL_FreeSurface(textSurface);
	}
	else if (scoreTimer.getTime() >= 1000 && scoreTimer.getTime() < 1500)
	{
		textSurface = TTF_RenderText_Solid(fontTitle, "Scores", color);
		apply_image((SCREEN_WIDTH / 2) - (textSurface->w / 2), (SCREEN_HEIGHT / 2) - (textSurface->h / 2) - (((scoreTimer.getTime() - 1000) / 500.) * ((SCREEN_HEIGHT / 2) - (textSurface->h / 2) - SCOREABOVETOP)), textSurface);
		SDL_FreeSurface(textSurface);
	}
	else if (scoreTimer.getTime() >= 1500)
	{
		textSurface = TTF_RenderText_Solid(fontTitle, "Scores", color);
		apply_image((SCREEN_WIDTH / 2) - (textSurface->w / 2), SCOREABOVETOP, textSurface);
		SDL_FreeSurface(textSurface);

		int width;

		if (scoreTimer.getTime() > 2000)
		{
			textSurface = TTF_RenderText_Solid(fontScores, "Player 1:", color);
			width = ((textSurface->w) * numPlayers) + ((numPlayers - 1) * SPACEBETWEENSCORES);
			apply_image((SCREEN_WIDTH / 2) - (width / 2), DISTANCE_TO_TOP_SCORES,textSurface);
			SDL_FreeSurface(textSurface);
		}

		if (scoreTimer.getTime() > 2500)
		{
			textSurface = TTF_RenderText_Solid(fontScores, "Player 2:", color);
			apply_image((SCREEN_WIDTH / 2) - (width / 2) + textSurface->w + SPACEBETWEENSCORES, DISTANCE_TO_TOP_SCORES,textSurface);
			SDL_FreeSurface(textSurface);
		}

		if (scoreTimer.getTime() > 3000)
		{
			textSurface = TTF_RenderText_Solid(fontScores, "Player 3:", color);
			apply_image((SCREEN_WIDTH / 2) - (width / 2) + 2 * textSurface->w + 2 * SPACEBETWEENSCORES, DISTANCE_TO_TOP_SCORES,textSurface);
			SDL_FreeSurface(textSurface);
		}

		if (scoreTimer.getTime() > 3500)
		{
			textSurface = TTF_RenderText_Solid(fontScores, "Player 4:", color);
			apply_image((SCREEN_WIDTH / 2) - (width / 2) + 3 * textSurface->w + 3 * SPACEBETWEENSCORES, DISTANCE_TO_TOP_SCORES,textSurface);
			SDL_FreeSurface(textSurface);
		}

	}
}