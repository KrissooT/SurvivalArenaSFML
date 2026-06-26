#include "Core/Game.h"

#include <SFML/GpuPreference.hpp>

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle)
{
	window_.setFramerateLimit(60);
}

bool Game::IsRunning()const {
	return window_.isOpen();
}

void Game::ProcessEvents() {
	while (const std::optional event = window_.pollEvent()) {
		if (event->getIf<sf::Event::Closed>()) {
			window_.close();
		}
	}
}

void Game::Update(float dt) {
	//TODO
	player_.Update(dt);

	if (player_.IsDead()) {
		window_.close();
		return;
	}

	enemySpawner_.Update(enemies_);

	for (auto& enemy : enemies_) {
		enemy->Update(dt, player_.GetPosition());
		

		if (player_.GetBounds().findIntersection(enemy->GetBounds())) {
			player_.TakeDamage(enemy->GetDamage());
		}
	}

	player_.Shoot(projectiles_, enemies_);

	for (auto& projectile : projectiles_) {
		projectile->Update(dt);
	}

	for (auto& projectile : projectiles_) {
		for (auto& enemy : enemies_) {
			if (projectile->GetBounds().findIntersection(enemy->GetBounds())) {
				enemy->TakeDamage(projectile->GetDamage());
				projectile->Destroy();
				break;
			}
		}
	}

	std::erase_if(projectiles_,
		[](const std::unique_ptr<Projectile>& projectile)
		{
			return projectile->IsDestroyed();
		});

	std::erase_if(enemies_,
		[](const std::unique_ptr<Enemy>& enemy)
		{
			return enemy->IsDead();
		});

	hud_.Update(player_);
}

void Game::Render() {
	window_.clear();

	player_.Draw(window_);

	for (auto& projectile : projectiles_) {
		projectile->Draw(window_);
	}

	for (auto& enemy : enemies_) {
		enemy->Draw(window_);
	}

	hud_.Draw(window_);

	window_.display();
}