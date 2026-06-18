#include "Enemies/Zombie.h"

#include <cmath>

Zombie::Zombie() : Enemy(50.f, 5.f, 100.f, 0.3f)
{
	zombie_.setSize({ 25.f,25.f });
	zombie_.setFillColor(sf::Color::Red);
	zombie_.setOrigin(zombie_.getGlobalBounds().getCenter());
	zombie_.setPosition(RandomPosition());
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

sf::FloatRect Zombie::GetBounds()const {
	return zombie_.getGlobalBounds();
}