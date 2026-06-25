#pragma once

#include "Entities/LivingEntity.h"
#include "Projectiles/Projectile.h"
#include "Entities/Enemy.h"

#include <vector>
#include <memory>

class Player : public LivingEntity {
	private:
		sf::RectangleShape player_; //Just for now, testing

		sf::Clock shootClock_;
		float shootInterval_ = 1.f;
		float attackRange_ = 250.f;

	public:
		//Constructor
		Player();

		//Core
		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;

		void Shoot(std::vector<std::unique_ptr<Projectile>>& projectiles, 
			       const std::vector<std::unique_ptr<Enemy>>& enemies);

		//Getters
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;
};