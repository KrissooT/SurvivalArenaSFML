#pragma once

#include "Entities/Enemy.h"

class Boss : public Enemy {
	private:
		sf::RectangleShape boss_; //Just testing
	public:
		//Constructor
		Boss();

		//Core
		void Update(float dt, sf::Vector2f playerPos)override;
		void Draw(sf::RenderWindow& window)override;

		//Getters
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;
};