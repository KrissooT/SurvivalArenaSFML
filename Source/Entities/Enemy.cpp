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

sf::Vector2f Enemy::RandomPosition(sf::Vector2f playerPos)const {

	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_real_distribution<float> xDist(0.f, static_cast<float>(gConfig.windowSize.x));
	std::uniform_real_distribution<float> yDist(0.f, static_cast<float>(gConfig.windowSize.y));

	constexpr float minDistanceToSpawn = 150.f;

	sf::Vector2f pos;
	float dist = 0.f;

	do {
		pos = { xDist(gen), yDist(gen) };

		sf::Vector2f dif = pos - playerPos;
		dist = std::sqrt(dif.x * dif.x + dif.y * dif.y);
	} while (dist < minDistanceToSpawn);

	return pos;
}