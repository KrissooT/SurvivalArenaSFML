#pragma once

#include "Entities/Enemy.h"

#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>

class EnemySpawner {

	private:
		sf::Clock globalClock_;

		sf::Clock spawnTimerZombie_;
		float spawnIntervalZombie_ = 2.f;
		int zombiesToSpawn_ = 2;

		sf::Clock spawnTimerSkeleton_;
		float spawnIntervalSkeleton_ = 3.f;
		int skeletonsToSpawn_ = 2;

	public:
		void Update(std::vector<std::unique_ptr<Enemy>>& enemies);

};