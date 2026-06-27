#include "Managers/EnemySpawner.h"
#include "Enemies/Zombie.h"
#include "Enemies/Skeleton.h"
#include "Enemies/Ghost.h"
#include "Enemies/Boss.h"

void EnemySpawner::Update(std::vector<std::unique_ptr<Enemy>>& enemies, sf::Vector2f playerPos) {

	float elapsed = globalClock_.getElapsedTime().asSeconds();

	if (bossActive_) {
		return;
	}

	if (spawnTimerZombie_.getElapsedTime().asSeconds() >= spawnIntervalZombie_) {

		for (int i = 0; i < zombiesToSpawn_; i++) {
			enemies.push_back(std::make_unique<Zombie>(playerPos));
		}
		spawnTimerZombie_.restart();
	}

	if (elapsed  > 60) {
		if (spawnTimerSkeleton_.getElapsedTime().asSeconds() >= spawnIntervalSkeleton_) {
			for (int i = 0; i < skeletonsToSpawn_; i++) {
				enemies.push_back(std::make_unique<Skeleton>(playerPos));
			}
			spawnTimerSkeleton_.restart();
		}
	}

	if (elapsed > 120) {
		if (spawnTimerGhost_.getElapsedTime().asSeconds() >= spawnIntervalGhost_) {
			for (int i = 0; i < ghostsToSpawn_; i++) {
				enemies.push_back(std::make_unique<Ghost>(playerPos));
			}
			spawnTimerGhost_.restart();
		}
	}

	if (elapsed > 180) {
		enemies.clear();
		enemies.push_back(std::make_unique<Boss>());
		bossActive_ = true;
	}
}

void EnemySpawner::RestartStage() {
	globalClock_.restart();
	bossActive_ = false;
	stage_++;
}

bool EnemySpawner::IsBossActive()const {
	return bossActive_;
}