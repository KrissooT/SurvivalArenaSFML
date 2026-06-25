#include "Entities/Player.h"
#include "Projectiles/Bullet.h"

#include <cmath>

Player::Player() : LivingEntity(100.f, 10.f, 200.f, 1.f)
{
	player_.setSize({ 50.f,50.f });
	player_.setFillColor(sf::Color::Green);
	player_.setOrigin(player_.getGlobalBounds().getCenter());

	sf::Vector2f playerPos = { gConfig.windowSize.x / 2.f, gConfig.windowSize.y / 2.f };

	player_.setPosition({playerPos});
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

void Player::Shoot
(std::vector<std::unique_ptr<Projectile>>& projectiles,
const std::vector<std::unique_ptr<Enemy>>& enemies) 
{
	if (shootClock_.getElapsedTime().asSeconds() < shootInterval_) {
		return;
	}

	Enemy* closestEnemy = nullptr;
	float closestDistance = attackRange_;

	for (const auto& enemy : enemies) {
		sf::Vector2f difference = enemy->GetPosition() - GetPosition();

		float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);

		if (distance < closestDistance) {
			closestDistance = distance;
			closestEnemy = enemy.get();
		}
	}

	if (closestEnemy == nullptr) {
		return;
	}

	sf::Vector2f direction = closestEnemy->GetPosition() - GetPosition();

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length != 0) {
		direction /= length;
	}

	projectiles.push_back(std::make_unique<Bullet>(GetPosition(), direction));

	shootClock_.restart();
}

sf::Vector2f Player::GetPosition()const {
	return player_.getPosition();
}

sf::FloatRect Player::GetBounds()const {
	return player_.getGlobalBounds();
}