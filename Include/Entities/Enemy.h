#pragma once

#include "Entities/Entity.h"

class Enemy : public Entity {

	protected:
		float health_;
		float damage_;
		float speed_;

	public:

		virtual void Update(float dt, sf::Vector2f playerPos) = 0;
		void Update(float dt) override {} // made it empty on purpose, keep it for now!
};