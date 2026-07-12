#include "Entities/Player.h"
#include "Projectiles/Bullet.h"

#include <cmath>

Player::Player() : LivingEntity(100.f, 50.f, 200.f, 1.f)
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

	projectiles.push_back(std::make_unique<Bullet>(GetPosition(), direction, GetDamage()));

	shootClock_.restart();
}

void Player::AddXp(int amount) {
	currentXp_ += amount;

	while (currentXp_ >= xpToNextLevel_)
	{
		currentXp_ -= xpToNextLevel_;
		level_++;
		levelUpPending_ = true;
		xpToNextLevel_ += 250; // Hardcode for now, later mby add a system to scale;
	}
}

void Player::ClearLevelUp() {
	levelUpPending_ = false;
}

void Player::IncreaseDamage(float amount) {
	damage_ += amount;
}

void Player::IncreaseMaxHealth(float amount) {
	maxHealth_ += amount;
}

void Player::Heal(float amount) {

	if (health_ + amount >= maxHealth_) {
		health_ = maxHealth_;
		return;
	}

	health_ += amount;
}

void Player::DecreaseShootInterval(float amount) {
	if (shootInterval_ <= 0.4f) {
		return;
	}
	shootInterval_ -= amount;
}

void Player::IncreaseSpeed(float amount) {
	speed_ += amount;
}

void Player::IncreaseAttackRange(float amount) {
	attackRange_ += amount;
}

void Player::IncreaseAttractionRange(float amount) {
	attractionBonus_ += amount;
}

sf::Vector2f Player::GetPosition()const {
	return player_.getPosition();
}

sf::FloatRect Player::GetBounds()const {
	return player_.getGlobalBounds();
}

float Player::GetAttractionBonus()const {
	return attractionBonus_;
}

int Player::GetCurrentXp()const {
	return currentXp_;
}

int Player::GetXpToNextLevel()const {
	return xpToNextLevel_;
}

int Player::GetLevel()const {
	return level_;
}

bool Player::IsLevelUpPending()const {
	return levelUpPending_;
}