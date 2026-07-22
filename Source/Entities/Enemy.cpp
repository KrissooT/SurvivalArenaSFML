#include "Entities/Enemy.h"
#include "Config/GameConfig.h"
#include "Camera/Camera.h"

#include <random>
#include <cmath>

Enemy::Enemy(float health, float damage, float speed, float damageCooldown, int xp) :
	LivingEntity(health, damage, speed, damageCooldown),
	xp_(xp)
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

	const float cameraHalfW = 640.f; //hardcode for now
	const float cameraHalfH = 360.f; // hardcode for now
	const float margin = 50.f; //hardcode for now

	float top = playerPos.y - cameraHalfH - margin;
	float bottom = playerPos.y + cameraHalfH + margin;
	float left = playerPos.x - cameraHalfW - margin;
	float right = playerPos.x + cameraHalfW + margin;

	std::uniform_int_distribution<int> sideDist(0, 3);
	std::uniform_real_distribution<float> xDist(left, right);
	std::uniform_real_distribution<float> yDist(top, bottom);

	int side = sideDist(gen);
	switch (side) {
	case 0: return { xDist(gen), top };
	case 1: return { xDist(gen), bottom };
	case 2: return { left,  yDist(gen) };
	default: return { right, yDist(gen) };
	}
}

int Enemy::GetXp()const {
	return xp_;
}