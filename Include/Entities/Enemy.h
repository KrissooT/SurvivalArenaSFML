#pragma once

#include "Entities/LivingEntity.h"

class Camera;

class Enemy : public LivingEntity {

	protected:

		void MoveToPlayer(float dt, sf::Vector2f playerPos, sf::Shape& monsterShape);

		int xp_;

	public:
		//Constructor
		Enemy(float health, float damage, float speed, float damageCooldown, int xp);

		//Core
		virtual void Update(float dt, sf::Vector2f playerPos) = 0;
		void Update(float dt) override {} // made it empty on purpose, keep it for now!

		sf::Vector2f RandomPosition(sf::Vector2f playerPos)const;

		//Getters
		int GetXp()const;
};