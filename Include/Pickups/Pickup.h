#pragma once

#include "Entities/Entity.h"
#include "Entities/Player.h"

class Pickup : public Entity {

	protected:
		void MoveToPlayer(float dt, sf::Vector2f playerPos, sf::Shape& itemShape);

		bool collected_ = false;

		float attractionRadius_;
		float attractionSpeed_;

	public:
		//Constructor
		Pickup(float attractionRadius, float attractionSpeed);

		//Core
		virtual void Update(float dt, Player& player) = 0;
		virtual void OnPickup(Player& player) = 0;

		void Collect();

		//Getters
		bool IsCollected()const;
};