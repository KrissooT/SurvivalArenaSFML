#pragma once

#include "Upgrades/UpgradeManager.h"
#include "Config/GameConfig.h"

#include <SFML/Graphics.hpp>

class UpgradeCard {

	private:
		sf::RectangleShape cardBox_;
		sf::Text nameText_;
		sf::Text descriptionText_;

		Upgrade upgrade_;

		bool isHovered_ = false;

	public:

		UpgradeCard(const Upgrade& upgrade, const sf::Font& font);

		void Initialize(const Upgrade& upgrade, const sf::Font& font);

		void SetPosition(float x, float y);

		void Update(const sf::Vector2f& mousePos);

		bool IsClicked(const sf::Vector2f& mousePos) const;

		const Upgrade& GetUpgrade() const;

		void Draw(sf::RenderWindow& window);
};