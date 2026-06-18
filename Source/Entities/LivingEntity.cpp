#include "Entities/LivingEntity.h"
//#include <iostream> //Testing

LivingEntity::LivingEntity(float health, float damage, float speed, float damageCooldown) :
	damageCooldown_(damageCooldown),
	health_(health),
	damage_(damage),
	speed_(speed)
{
}

void LivingEntity::TakeDamage(float damage) {

	if (damageClock_.getElapsedTime().asSeconds() < damageCooldown_) {
		return;
	}

	health_ -= damage;
	damageClock_.restart();
	//std::cout << health_ << '\n'; //Testing
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