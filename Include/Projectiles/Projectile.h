#pragma once

#include "Entities/Entity.h"

#include <SFML/Graphics.hpp>

class Camera;

class Projectile : public Entity {

	protected:

		float damage_;
		float speed_;

		bool destroy_ = false;

		bool IsOutOfBounds(sf::Vector2f position, sf::FloatRect cameraBounds)const;

	public:
		//Constructor
		Projectile(float damage, float speed);

		void Update(float dt) override {}
		virtual void Update(float dt, Camera camera) = 0;

		void Destroy();

		//Getters
		float GetDamage()const;
		float GetSpeed()const;
		bool IsDestroyed()const;

};