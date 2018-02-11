#include "GameStates.h"
#include "Functions.h"

SDL_Event mainEvent;

int main (int argc, char * argv[]) {

	init();
	
	GameStates * mainGameState = new Title();
	
	while (!quitBool)
	{
		SDL_PollEvent(&mainEvent);
		if (mainEvent.type == SDL_QUIT)
		{
			quitBool = true;
		}
		if (mainEvent.type == SDL_KEYDOWN)
		{
			if (mainEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				quitBool = true;
			}
		}
		mainGameState->handle_input();
		mainGameState->logic();
		mainGameState->renderOutput();
		SDL_Flip(window);

		if (mainGameBool)
		{
			mainGameBool = false;
			delete mainGameState;
			mainGameState = new MainGame();
		}
		else if (resultsScreenBool)
		{
			resultsScreenBool = false;
			delete mainGameState;
			mainGameState = new ResultsScreen();
		}
	}
	quit();
    return 0;
}
