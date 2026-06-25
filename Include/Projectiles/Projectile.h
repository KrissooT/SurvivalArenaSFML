#pragma once

#include "Entities/Entity.h"

#include <SFML/Graphics.hpp>

class Projectile : public Entity {

	protected:
		float damage_;
		float speed_;

		bool destroy_ = false;

	public:
		//Constructor
		Projectile(float damage, float speed);

		void Destroy();

		//Getters
		float GetDamage()const;
		float GetSpeed()const;
		bool IsDestroy()const;

};