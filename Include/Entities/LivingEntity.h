#pragma once

#include "Entities/Entity.h"

class LivingEntity : public Entity{

	protected:
		sf::Clock damageClock_;
		float damageCooldown_;

		float health_;
		float damage_;
		float speed_;

	public:
		//Constructor
		LivingEntity(float health, float damage, float speed);

		//Core
		void TakeDamage(float damage);
		bool IsDead()const;

		//Getters
		float GetHealth()const;
		float GetDamage()const;
		float GetSpeed()const;
};