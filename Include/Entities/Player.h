#pragma once

#include "Entities/LivingEntity.h"

class Player : public LivingEntity {
	private:
		sf::RectangleShape player_; //Just for now, testing

	public:
		//Constructor
		Player();

		//Core
		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;

		//Getters
		sf::Vector2f GetPosition()const;
		sf::FloatRect GetBounds()const override;
};