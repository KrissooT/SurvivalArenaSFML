#pragma once

#include "Pickups/Pickup.h"

class XpOrb : public Pickup {

	private:
		sf::CircleShape xpOrb_; //Just testing

		int xp_;

	public:
		//Constructor
		XpOrb(sf::Vector2f enemyPosition, int xp);

		//Core
		void Update(float dt) override {}
		void Update(float dt, Player& player) override;
		void OnPickup(Player& player) override;
		void Draw(sf::RenderWindow& window) override;

		//Getters
		sf::FloatRect GetBounds()const override;
		sf::Vector2f GetPosition() const override;
};