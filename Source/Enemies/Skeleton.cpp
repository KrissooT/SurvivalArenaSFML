#include "Enemies/Skeleton.h"

Skeleton::Skeleton(sf::Vector2f playerPos) : Enemy(80.f, 10.f, 125.f, 0.3f)
{
	skeleton_.setSize({ 25.f,25.f });
	skeleton_.setFillColor(sf::Color(119, 0, 200));
	skeleton_.setOrigin(skeleton_.getGlobalBounds().getCenter());
	skeleton_.setPosition(RandomPosition(playerPos));
}

void Skeleton::Update(float dt, sf::Vector2f playerPos) {
	MoveToPlayer(dt, playerPos, skeleton_);
}

void Skeleton::Draw(sf::RenderWindow& window) {
	window.draw(skeleton_);
}

sf::Vector2f Skeleton::GetPosition()const {
	return skeleton_.getPosition();
}

sf::FloatRect Skeleton::GetBounds()const {
	return skeleton_.getGlobalBounds();
}