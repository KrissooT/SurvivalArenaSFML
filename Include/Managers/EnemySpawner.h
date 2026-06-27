#pragma once

#include "Entities/Enemy.h"

#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>

class EnemySpawner {

	private:
		sf::Clock globalClock_;
		int stage_ = 1; // This will scale emeies hp, dmg and speed later;

		sf::Clock spawnTimerZombie_;
		float spawnIntervalZombie_ = 2.f;
		int zombiesToSpawn_ = 2;

		sf::Clock spawnTimerSkeleton_;
		float spawnIntervalSkeleton_ = 3.f;
		int skeletonsToSpawn_ = 2;

		sf::Clock spawnTimerGhost_;
		float spawnIntervalGhost_ = 4.f;
		int ghostsToSpawn_ = 2;

		sf::Clock spawnTimerBoss_;
		int bossToSpawn_ = 1;
		bool bossActive_ = false;

	public:
		void Update(std::vector<std::unique_ptr<Enemy>>& enemies, sf::Vector2f playerPos);
		void RestartStage();

		bool IsBossActive()const;


};