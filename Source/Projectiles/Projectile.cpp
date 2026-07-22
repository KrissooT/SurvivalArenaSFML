#include "Projectiles/Projectile.h"
#include "Camera/Camera.h"

Projectile::Projectile(float damage, float speed) :
	damage_(damage),
	speed_(speed)
{

}

bool Projectile::IsOutOfBounds(sf::Vector2f position, sf::FloatRect cameraBounds)const {

	//sf::Vector2f diff = playerPos - bulletPosition;

	//ako poziciqta na patrona e izvun camerata da se iztriie

	return !cameraBounds.contains(position);

	//return position.x != cameraBounds.position.x || position.y != cameraBounds.position.y;

	/*return position.x < 0.f || position.y < 0.f ||
		   position.x > gConfig.windowSize.x || position.y > gConfig.windowSize.y;*/

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