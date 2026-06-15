#include "Core/Game.h"

int main()
{
	Game game;

	while (game.IsRunning()) {
		game.ProcessEvents();
		game.Update();
		game.Render();
	}
}