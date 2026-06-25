#pragma once

#include "Entities/Entity.h"

#include <SFML/System/Clock.hpp>

class LivingEntity : public Entity{

	protected:
		sf::Clock damageClock_;
		float damageCooldown_;

		float health_;
		float damage_;
		float speed_;

	public:
		//Constructor
		LivingEntity(float health, float damage, float speed, float damageCooldown);

		//Core
		void TakeDamage(float damage);
		bool IsDead()const;

		//Getters
		float GetHealth()const;
		float GetDamage()const;
		float GetSpeed()const;
};