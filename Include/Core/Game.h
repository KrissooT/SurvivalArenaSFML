#pragma once

#include <SFML/Graphics.hpp>

#include "Config/GameConfig.h"
#include "Entities/Player.h"
#include "Enemies/Zombie.h"


class Game {

	private:

		sf::RenderWindow window_;
		Player player_;
		Zombie zombie_;

	public:

		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update(float dt);
		void Render();
};