#include "Enemies/Zombie.h"

Zombie::Zombie() {

	health_ = 50.f;
	damage_ = 5.f;
	speed_ = 100.f;

	zombie_.setSize({ 50.f,50.f });
	zombie_.setFillColor(sf::Color::Red);
	zombie_.setOrigin(zombie_.getGlobalBounds().getCenter());
	zombie_.setPosition({400.f, 200.f});
}

void Zombie::Update(float dt) {
	//TODO
}

void Zombie::Draw(sf::RenderWindow& window) {
	window.draw(zombie_);
}