#include "Projectiles/Projectile.h"

Projectile::Projectile(float damage, float speed) :
	damage_(damage),
	speed_(speed)
{

}

bool Projectile::IsOutOfBounds(sf::Vector2f position)const {

	return position.x < 0.f || position.y < 0.f ||
		   position.x > gConfig.windowSize.x || position.y > gConfig.windowSize.y;

}

void Projectile::Destroy() {
	destroy_ = true;
}

float Projectile::GetDamage()const {
	return damage_;
}

float Projectile::GetSpeed()const {
	return speed_;
}

bool Projectile::IsDestroyed()const {
	return destroy_;
}