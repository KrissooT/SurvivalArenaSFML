#include "Enemies/Ghost.h"

Ghost::Ghost(sf::Vector2f playerPos) : Enemy(160.f, 20.f, 180.f, 0.3f)
{
	ghost_.setSize({25.f, 25.f});
	ghost_.setFillColor(sf::Color::Cyan);
	ghost_.setOrigin(ghost_.getGlobalBounds().getCenter());
	ghost_.setPosition(RandomPosition(playerPos));
}

void Ghost::Update(float dt, sf::Vector2f playerPos) {
	MoveToPlayer(dt, playerPos, ghost_);
}

void Ghost::Draw(sf::RenderWindow& window) {
	window.draw(ghost_);
}

sf::Vector2f Ghost::GetPosition()const {
	return ghost_.getPosition();
}

sf::FloatRect Ghost::GetBounds()const {
	return ghost_.getGlobalBounds();
}