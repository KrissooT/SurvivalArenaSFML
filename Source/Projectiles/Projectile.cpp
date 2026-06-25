#include "Projectiles/Projectile.h"

Projectile::Projectile(float damage, float speed) :
	damage_(damage),
	speed_(speed)
{

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

bool Projectile::IsDestroy()const {
	return destroy_;
}