#pragma once

#include <SFML/Graphics.hpp>

class Entity {
	private:

	public:
		
		//Destructor
		virtual ~Entity() = default;

		//Core
		virtual void Update(float dt) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

		//Getters
		virtual sf::FloatRect GetBounds()const = 0;
		virtual sf::Vector2f GetPosition() const = 0;
};