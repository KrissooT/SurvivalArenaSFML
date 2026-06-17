#pragma once

#include "Entities/LivingEntity.h"

class Enemy : public LivingEntity {

	public:
		//Constructor
		Enemy(float health, float damage, float speed);

		//Core
		virtual void Update(float dt, sf::Vector2f playerPos) = 0;
		void Update(float dt) override {} // made it empty on purpose, keep it for now!
};