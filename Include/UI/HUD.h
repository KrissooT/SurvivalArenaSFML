#pragma once

#include "Entities/Player.h"

#include <SFML/Graphics.hpp>

class HUD {

	private:
		sf::Font font_;

		//Health
		sf::Texture healthBarBackgroundTexture_;
		sf::Sprite healthBarBackgroundSprite_;

		sf::RectangleShape healthBar_;
		float maxHealthBarWidth_;

		sf::Text healthDisplay_;

		sf::Texture heartIconTexture_;
		sf::Sprite heartIconSprite_;

		//Xp
		sf::Texture xpBarBackgroundTexture_;
		sf::Sprite xpBarBackgroundSprite_;

		sf::RectangleShape xpBar_;
		float maxXpBarWidth_;

	public:

		HUD();

		void Update(const Player& player);
		void Draw(sf::RenderWindow& window);
};