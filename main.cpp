
#include "main.h"

Uint32 deltaTime;
Menu menu;
bool gameState = false;
int main(int argc, char *argv[])
{
	initSDL();
	initgame();
	initStage();
	Uint32 lastTime = SDL_GetTicks();
    menu.init();
    while (app.running)
	{
	    Uint32 currentTime = SDL_GetTicks();
	    deltaTime = currentTime - lastTime;
        lastTime = currentTime;
		prepareScene();
		doInput();

		if (!gameState) {
            menu.update();
            menu.draw();
        } else {
            stage.logic();
            stage.draw();
        }



		presentScene();
        Uint32 frameTime = SDL_GetTicks() - currentTime;
        if(frameTime < 1000/FPS)
            SDL_Delay(1000/FPS - frameTime);
	}
	close();
    return 0;
}
