#pragma once

#include "Entities/Enemy.h"

class Ghost : public Enemy {

	private:
		sf::RectangleShape ghost_; //Just testing
	public:
		//Constructor
		Ghost(sf::Vector2f playerPos);

		//Core
		void Update(float dt, sf::Vector2f playerPos)override;
		void Draw(sf::RenderWindow& window)override;

		//Getters
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;
};