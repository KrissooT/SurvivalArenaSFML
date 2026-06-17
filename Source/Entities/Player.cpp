#include "Entities/Player.h"

#include <cmath>

Player::Player() : LivingEntity(100.f, 10.f, 200.f)
{
	player_.setSize({ 100.f,50.f });
	player_.setFillColor(sf::Color::Green);
	player_.setOrigin(player_.getGlobalBounds().getCenter());
	player_.setPosition({ 400.f,400.f });
}

void Player::Update(float dt) {

	sf::Vector2f direction(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) direction.y -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) direction.y += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) direction.x += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) direction.x -= 1.f;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0.f) {
		direction /= length;
	}

	player_.move({ direction * speed_ * dt });

}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(player_);
}

sf::Vector2f Player::GetPosition()const {
	return player_.getPosition();
}

sf::FloatRect Player::GetBounds()const {
	return player_.getGlobalBounds();
}