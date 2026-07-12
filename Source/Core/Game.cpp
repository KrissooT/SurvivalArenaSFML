#include "Core/Game.h"

#include <SFML/GpuPreference.hpp>
#include <iostream> //Just for testing

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle),
	state_(GameState::Playing)
{
	window_.setFramerateLimit(60);

	//Upgrades

	allUpgrades_.push_back({
		"Damage Increase",
		"Increase Player's damage by 15",
		[](Player& player) {player.IncreaseDamage(15.f); }
		});

	allUpgrades_.push_back({
		"Movement Speed Increase",
		"Increase Player's movement speed by 50",
		[](Player& player) {player.IncreaseSpeed(50.f); }
		});

	allUpgrades_.push_back({
		"Max Health Increase",
		"Increase Player's maximum health by 25",
		[](Player& player) {player.IncreaseMaxHealth(25.f); }
		});
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

	//sf::Vector2i mousePos = sf::Mouse::getPosition(window_);
	//std::cout << mousePos.x << "X, " << mousePos.y << " Y\n"; //Just for testing

	if (player_.IsLevelUpPending()) {
		state_ = GameState::Leveling;
	}

	switch(state_) {
	case GameState::Playing:
		player_.Update(dt);

		if (player_.IsDead()) {
			window_.close();
			return;
		}

		enemySpawner_.Update(enemies_, player_.GetPosition());

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
					if (enemy->IsDead()) {
						pickups_.push_back(std::make_unique<XpOrb>(enemy->GetPosition(), enemy->GetXp(), player_));
					}
					break;
				}
			}
		}

		for (auto& pickup : pickups_) {
			pickup->Update(dt, player_);

			if (pickup->GetBounds().findIntersection(player_.GetBounds())) {
				pickup->OnPickup(player_);
				pickup->Collect();
			}

		}

		std::erase_if(pickups_,
			[](const std::unique_ptr<Pickup>& pickup) {
				return pickup->IsCollected();
			});

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

		if (enemySpawner_.IsBossActive() && enemies_.empty()) {
			enemySpawner_.RestartStage();
		}

		hud_.Update(player_);
		break;
	case GameState::Leveling:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
			allUpgrades_[0].apply_(player_);
			player_.ClearLevelUp();
			state_ = GameState::Playing;
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
			allUpgrades_[1].apply_(player_);
			player_.ClearLevelUp();
			state_ = GameState::Playing;
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
			allUpgrades_[2].apply_(player_);
			player_.ClearLevelUp();
			state_ = GameState::Playing;
		}

		break;
	}
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

	for (auto& pickup : pickups_) {
		pickup->Draw(window_);
	}

	hud_.Draw(window_);

	window_.display();
}