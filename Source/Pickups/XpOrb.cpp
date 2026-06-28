#include "Pickups/XpOrb.h"

#include <cmath>

XpOrb::XpOrb(sf::Vector2f enemyPosition, int xp) :
	Pickup(120.f),
	xp_(xp)
{

	xpOrb_.setRadius(3.f);
	xpOrb_.setFillColor(sf::Color::Green);
	xpOrb_.setOrigin(xpOrb_.getGlobalBounds().getCenter());
	xpOrb_.setPosition(enemyPosition);
}

void XpOrb::Update(float dt,Player& player) {

	sf::Vector2f differnce = player.GetPosition() - xpOrb_.getPosition();

	float distance = std::sqrt(differnce.x * differnce.x + differnce.y * differnce.y);

	float attractionPlusBonus = attractionRadius_ + player.GetXpAttractionBonus();

	if (distance <= attractionPlusBonus) {
		MoveToPlayer(dt, player.GetPosition(), xpOrb_);
	}

}

void XpOrb::Draw(sf::RenderWindow& window) {
	window.draw(xpOrb_);
}

sf::FloatRect XpOrb::GetBounds()const {
	return xpOrb_.getGlobalBounds();
}

sf::Vector2f XpOrb::GetPosition()const {
	return xpOrb_.getPosition();
}