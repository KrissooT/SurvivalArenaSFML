#include "Entities/Enemy.h"
#include "Config/GameConfig.h"

#include <random>
#include <cmath>

Enemy::Enemy(float health, float damage, float speed, float damageCooldown) :
	LivingEntity(health, damage, speed, damageCooldown)
{
}

void Enemy::MoveToPlayer(float dt, sf::Vector2f playerPos, sf::Shape& monsterShape) {

	sf::Vector2f monsterPos = monsterShape.getPosition();
	sf::Vector2f direction = playerPos - monsterPos;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length != 0.f) {
		direction /= length;
	}
	monsterShape.move({ direction * speed_ * dt });
}

sf::Vector2f Enemy::RandomPosition()const {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> xDist(0.f, (float)gConfig.windowSize.x);
	std::uniform_real_distribution<float> yDist(0.f, (float)gConfig.windowSize.y);

	float x = xDist(gen);
	float y = yDist(gen);

	return { x, y };
}