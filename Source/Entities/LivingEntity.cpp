#include "Entities/LivingEntity.h"

LivingEntity::LivingEntity(float health, float damage, float speed) :
	health_(health),
	damage_(damage),
	speed_(speed)
{
}

void LivingEntity::TakeDamage(float damage) {
	health_ -= damage;
}

bool LivingEntity::IsDead()const {
	if (health_ <= 0) {
		return true;
	}
	return false;
}

float LivingEntity::GetHealth()const {
	return health_;
}

float LivingEntity::GetDamage()const {
	return damage_;
}

float LivingEntity::GetSpeed()const {
	return speed_;
}