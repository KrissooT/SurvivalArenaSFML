#pragma once

#include "Projectiles/Projectile.h"

#include <SFML/Graphics.hpp>

class Bullet : public Projectile {

	private:
		sf::CircleShape bullet_; // Just testing;
		sf::Vector2f direction_;

	public:
		Bullet(sf::Vector2f startPos, sf::Vector2f direction);

		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;

		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;
};