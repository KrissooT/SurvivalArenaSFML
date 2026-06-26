#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "UI/HUD.h"
#include "Projectiles/Projectile.h"
#include "Entities/Enemy.h"
#include "Managers/EnemySpawner.h"
#include "Enemies/Zombie.h"
#include "Entities/Player.h"

class Game {

	private:

		sf::RenderWindow window_;
		Player player_;
		EnemySpawner enemySpawner_;
		std::vector<std::unique_ptr<Enemy>> enemies_;
		std::vector<std::unique_ptr<Projectile>> projectiles_;
		HUD hud_;

	public:

		//Constructor
		Game();

		//Core
		bool IsRunning()const;

		void ProcessEvents();
		void Update(float dt);
		void Render();
};