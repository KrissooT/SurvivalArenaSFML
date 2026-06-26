#pragma once

#include "Entities/Player.h"

#include <SFML/Graphics.hpp>

class HUD {

	private:
		sf::Font font_;

		sf::Texture healthBarBackgroundTexture_;
		sf::Sprite healthBarBackgroundSprite_;
		sf::RectangleShape healthBar_;
		float maxHealthBarWidth_;
		sf::Text healthDisplay_;

	public:

		HUD();

		void Update(const Player& player);
		void Draw(sf::RenderWindow& window);
};