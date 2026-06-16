#pragma once

#include "Entities/Entity.h"

class Player : public Entity {
	private:
		sf::RectangleShape player_; //Just for now, testing

	public:

		Player();

		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;
};