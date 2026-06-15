#pragma once

#include <SFML/Graphics.hpp>

class Game {

	private:

		sf::RenderWindow window_;

	public:

		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};