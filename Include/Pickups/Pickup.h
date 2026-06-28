#pragma once

#include "Entities/Entity.h"
#include "Entities/Player.h"

class Pickup : public Entity {

	protected:
		void MoveToPlayer(float dt, sf::Vector2f playerPos, sf::Shape& itemShape);

		float attractionRadius_;
		float attractionSpeed = 250.f;

	public:
		//Constructor
		Pickup(float attractionRadius);

		//Core
		virtual void Update(float dt, Player& player) = 0;

		//Getters
};