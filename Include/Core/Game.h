#pragma once

#include <SFML/Graphics.hpp>

#include "Config/GameConfig.h"
#include "Entities/Player.h"


class Game {

	private:

		sf::RenderWindow window_;
		Player player_;

	public:

		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update(float dt);
		void Render();
};