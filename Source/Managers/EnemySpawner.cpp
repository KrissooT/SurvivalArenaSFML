#include "Managers/EnemySpawner.h"
#include "Enemies/Zombie.h"
#include "Enemies/Skeleton.h"
#include "Enemies/Ghost.h"

void EnemySpawner::Update(std::vector<std::unique_ptr<Enemy>>& enemies) {

	float elapsed = globalClock_.getElapsedTime().asSeconds();

	if (spawnTimerZombie_.getElapsedTime().asSeconds() >= spawnIntervalZombie_) {

		for (int i = 0; i < zombiesToSpawn_; i++) {
			enemies.push_back(std::make_unique<Zombie>());
		}
		spawnTimerZombie_.restart();
	}

	if (elapsed  > 60) {
		if (spawnTimerSkeleton_.getElapsedTime().asSeconds() >= spawnIntervalSkeleton_) {
			for (int i = 0; i < skeletonsToSpawn_; i++) {
				enemies.push_back(std::make_unique<Skeleton>());
			}
			spawnTimerSkeleton_.restart();
		}
	}

	if (elapsed > 120) {
		if (spawnTimerGhost_.getElapsedTime().asSeconds() >= spawnIntervalGhost_) {
			for (int i = 0; i < ghostsToSpawn_; i++) {
				enemies.push_back(std::make_unique<Ghost>());
			}
			spawnTimerGhost_.restart();
		}
	}
}