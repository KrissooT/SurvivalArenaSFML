#pragma once

#include <SFML/Graphics.hpp>

class Entity {
	private:

	public:

		virtual ~Entity() = default;

		virtual void Update(float dt) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;
};