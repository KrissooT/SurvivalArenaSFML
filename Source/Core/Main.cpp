#include "Core/Game.h"

int main()
{
	Game game;
	sf::Clock clock;

	while (game.IsRunning()) {
		game.ProcessEvents();

		float dt = clock.restart().asSeconds();

		game.Update(dt);
		game.Render();
	}
}