#include "Enemies/Boss.h"

Boss::Boss() : Enemy(400.f, 30.f, 125.f, 0.3f)
{
	boss_.setSize({75.f, 75.f});
	boss_.setFillColor(sf::Color(255, 165, 0));
	boss_.setOrigin(boss_.getGlobalBounds().getCenter());

	sf::Vector2f bossPos = { gConfig.windowSize.x / 2.f, gConfig.windowSize.y / 2.f + 100.f };

	boss_.setPosition({bossPos});
}

void Boss::Update(float dt, sf::Vector2f playerPos) {
	MoveToPlayer(dt, playerPos, boss_);
}

void Boss::Draw(sf::RenderWindow& window) {
	window.draw(boss_);
}

sf::Vector2f Boss::GetPosition()const {
	return boss_.getPosition();
}

sf::FloatRect Boss::GetBounds()const {
	return boss_.getGlobalBounds();
}