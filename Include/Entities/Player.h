#pragma once

#include "Entities/LivingEntity.h"
#include "Projectiles/Projectile.h"
#include "Entities/Enemy.h"

#include <vector>
#include <memory>

class Player : public LivingEntity {
	private:
		sf::RectangleShape player_; //Just for now, testing

		//Attack
		sf::Clock shootClock_;
		float shootInterval_ = 1.f;
		float attackRange_ = 250.f;

		//XP & Leveling

		bool levelUpPending_ = false;

		float attractionBonus_ = 0.f;

		int currentXp_ = 0;
		int xpToNextLevel_ = 50;
		int level_ = 1;

	public:
		//Constructor
		Player();

		//Core
		void Update(float dt) override;
		void Draw(sf::RenderWindow& window) override;

		void Shoot(std::vector<std::unique_ptr<Projectile>>& projectiles, 
			       const std::vector<std::unique_ptr<Enemy>>& enemies);

		void AddXp(int amount);

		void ClearLevelUp();

		//Upgrades(Attributes)
		void IncreaseDamage(float amount);
		void IncreaseMaxHealth(float amount);
		void Heal(float amount);
		void DecreaseShootInterval(float amount);
		void IncreaseSpeed(float amount);
		void IncreaseAttackRange(float amount);
		void IncreaseAttractionRange(float amount);

		//Getters
		sf::Vector2f GetPosition()const override;
		sf::FloatRect GetBounds()const override;

		float GetAttractionBonus()const;
		
		int GetCurrentXp()const;
		int GetXpToNextLevel()const;
		int GetLevel()const;

		bool IsLevelUpPending()const;
};