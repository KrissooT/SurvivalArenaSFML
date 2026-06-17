#pragma once

#include "Entities/Entity.h"

class Player : public Entity {
	private:
		sf::RectangleShape player_; //Just for now, testing

	protected:
		float health_;
		float damage_;
		float speed_;

	public:

		Player();

		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;
};