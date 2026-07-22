#pragma once

#include "Entities/Player.h"

#include <SFML/Graphics.hpp>

class Camera {
	
	private:
		sf::View camera_;
		sf::View currentView_;

		sf::FloatRect cameraBounds_;

	public:

		//Constructor
		Camera();

		//Core
		void Update(sf::Vector2f playerPos);
		void Draw(sf::RenderWindow& window);

		void CalculateBounds();

		//Getters
		sf::FloatRect GetBounds();
		

};