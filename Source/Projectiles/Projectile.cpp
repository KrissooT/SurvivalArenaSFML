#include "Projectiles/Projectile.h"
#include "Camera/Camera.h"

Projectile::Projectile(float damage, float speed) :
	damage_(damage),
	speed_(speed)
{

}

bool Projectile::IsOutOfBounds(sf::Vector2f position, sf::FloatRect cameraBounds)const {

	return !cameraBounds.contains(position);
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