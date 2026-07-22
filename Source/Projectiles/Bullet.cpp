#include "Projectiles/Bullet.h"
#include "Camera/Camera.h"


Bullet::Bullet(sf::Vector2f startPos, sf::Vector2f direction, float damage) : 
	Projectile(damage, 300.f),
	direction_(direction)
{
	bullet_.setRadius(8.f);
	bullet_.setFillColor(sf::Color::Yellow);
	bullet_.setOrigin(bullet_.getGlobalBounds().getCenter());
	bullet_.setPosition(startPos);
}

void Bullet::Update(float dt, Camera camera) {
	bullet_.move({direction_ * speed_ * dt});

	if (IsOutOfBounds(bullet_.getPosition(), camera.GetBounds())) {
		Destroy();
	}

}

void Bullet::Draw(sf::RenderWindow& window) {
	window.draw(bullet_);
}

sf::Vector2f Bullet::GetPosition()const {
	return bullet_.getPosition();
}

sf::FloatRect Bullet::GetBounds()const {
	return bullet_.getGlobalBounds();
}