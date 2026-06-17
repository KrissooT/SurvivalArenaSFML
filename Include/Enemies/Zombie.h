#pragma once

#include "Entities/Enemy.h"

#include <SFML/Graphics.hpp>

class Zombie : public Enemy {
	private:
		sf::RectangleShape zombie_; //Just for now, testing

	public:
		Zombie();

		void Update(float dt, sf::Vector2f playerPos) override;
		void Draw(sf::RenderWindow& window) override;
};