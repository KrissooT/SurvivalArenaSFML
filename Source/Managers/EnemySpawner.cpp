#include "Managers/EnemySpawner.h"
#include "Enemies/Zombie.h"

void EnemySpawner::Update(std::vector<std::unique_ptr<Enemy>>& enemies) {

	if (spawnTimer_.getElapsedTime().asSeconds() >= spawnInterval_) {

		for (int i = 0; i < zombiesToSpawn_; i++) {
			enemies.push_back(std::make_unique<Zombie>());
		}
		spawnTimer_.restart();
	}
}