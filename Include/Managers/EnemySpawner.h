#pragma once

#include "Entities/Enemy.h"

#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>

class EnemySpawner {

	private:
		sf::Clock spawnTimer_;
		float spawnInterval_ = 2.f;

		int zombiesToSpawn_ = 2;

	public:
		void Update(std::vector<std::unique_ptr<Enemy>>& enemies);

};