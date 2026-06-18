#include "Entities/Enemy.h"
#include "Config/GameConfig.h"

#include <random>

Enemy::Enemy(float health, float damage, float speed, float damageCooldown) :
	LivingEntity(health, damage, speed, damageCooldown)
{
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