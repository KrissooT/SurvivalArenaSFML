#pragma once

#include "Entities/Enemy.h"

class Zombie : public Enemy {
	private:
		sf::RectangleShape zombie_; //Just for now, testing

	public:
		//Constructor
		Zombie(sf::Vector2f playerPos);

		//Core
		void Update(float dt, sf::Vector2f playerPos) override;
		void Draw(sf::RenderWindow& window) override;

		//Getters	
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;

};