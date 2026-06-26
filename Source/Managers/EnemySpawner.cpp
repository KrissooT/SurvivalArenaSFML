#include "Managers/EnemySpawner.h"
#include "Enemies/Zombie.h"
#include "Enemies/Skeleton.h"

void EnemySpawner::Update(std::vector<std::unique_ptr<Enemy>>& enemies) {

	if (globalClock_.getElapsedTime().asSeconds() <= 60) {
		if (spawnTimerZombie_.getElapsedTime().asSeconds() >= spawnIntervalZombie_) {

			for (int i = 0; i < zombiesToSpawn_; i++) {
				enemies.push_back(std::make_unique<Zombie>());
			}
			spawnTimerZombie_.restart();
		}
	}
	else if (globalClock_.getElapsedTime().asSeconds() > 60 &&
		     globalClock_.getElapsedTime().asSeconds() <= 120) 
	{
		if (spawnTimerZombie_.getElapsedTime().asSeconds() >= spawnIntervalZombie_) {

			for (int i = 0; i < zombiesToSpawn_; i++) {
				enemies.push_back(std::make_unique<Zombie>());
			}
			spawnTimerZombie_.restart();
		}

		if (spawnTimerSkeleton_.getElapsedTime().asSeconds() >= spawnIntervalSkeleton_) {
			for (int i = 0; i < skeletonsToSpawn_; i++) {
				enemies.push_back(std::make_unique<Skeleton>());
			}
			spawnTimerSkeleton_.restart();
		}
	}


}