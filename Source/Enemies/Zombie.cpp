#include "Enemies/Zombie.h"
#include <cmath>

Zombie::Zombie() {

	health_ = 50.f;
	damage_ = 5.f;
	speed_ = 100.f;

	zombie_.setSize({ 50.f,50.f });
	zombie_.setFillColor(sf::Color::Red);
	zombie_.setOrigin(zombie_.getGlobalBounds().getCenter());
	zombie_.setPosition({400.f, 200.f});
}

void Zombie::Update(float dt, sf::Vector2f playerPos) {
	sf::Vector2f zombiePos = zombie_.getPosition();
	sf::Vector2f direction = playerPos - zombiePos;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	
	if (length != 0.f) {
		direction /= length;
	}

	zombie_.move({direction * speed_ * dt});
}

void Zombie::Draw(sf::RenderWindow& window) {
	window.draw(zombie_);
}