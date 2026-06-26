#pragma once

#include "Entities/Enemy.h"

class Skeleton : public Enemy {

	private:
		sf::RectangleShape skeleton_; // Just for now

	public:
		//Constructor
		Skeleton();

		//Core
		void Update(float dt, sf::Vector2f playerPos) override;
		void Draw(sf::RenderWindow& window) override;

		//Getters
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;
};