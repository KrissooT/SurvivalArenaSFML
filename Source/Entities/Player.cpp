#include "Entities/Player.h"

Player::Player() {
	player_.setSize({ 100,50 });
	player_.setFillColor(sf::Color::Green);
	player_.setPosition({ 400,400 });
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

	player_.move({ direction * 200.f * dt });

}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(player_);
}