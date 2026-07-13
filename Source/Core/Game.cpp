#include "Core/Game.h"

#include <SFML/GpuPreference.hpp>
#include <iostream> //Just for testing

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle),
	state_(GameState::Playing),
	font_("Content/Fonts/Font.ttf")
{
	window_.setFramerateLimit(60);
	upgradePanel.setSize({ 800.f, 250.f });
	upgradePanel.setFillColor(sf::Color(20, 20, 20, 200));
	upgradePanel.setOrigin(upgradePanel.getSize() / 2.f);
	upgradePanel.setPosition({ (float)gConfig.windowSize.x / 2, (float)gConfig.windowSize.y / 2 });
}

bool Game::IsRunning()const {
	return window_.isOpen();
}

void Game::ProcessEvents() {
	while (const std::optional event = window_.pollEvent()) {
		if (event->getIf<sf::Event::Closed>()) {
			window_.close();
		}

		if (state_ == GameState::Leveling)
		{
			if (event->is<sf::Event::MouseButtonPressed>())
			{
				const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

				if (mouseEvent->button == sf::Mouse::Button::Left)
				{
					sf::Vector2f mousePos = window_.mapPixelToCoords(
						sf::Mouse::getPosition(window_));

					for (auto& card : cards_)
					{
						if (card.IsClicked(mousePos))
						{
							card.GetUpgrade().apply_(player_);
							player_.ClearLevelUp();
							state_ = GameState::Playing;
							cards_.clear();
						}
					}
				}
			}

			if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
				if (keyEvent->code == sf::Keyboard::Key::Num1 && currentChoices_.size() > 0) {
					currentChoices_[0].apply_(player_);
					player_.ClearLevelUp();
					state_ = GameState::Playing;
					cards_.clear();
				}
				else if (keyEvent->code == sf::Keyboard::Key::Num2 && currentChoices_.size() > 1) {
					currentChoices_[1].apply_(player_);
					player_.ClearLevelUp();
					state_ = GameState::Playing;
					cards_.clear();
				}
				else if (keyEvent->code == sf::Keyboard::Key::Num3 && currentChoices_.size() > 2) {
					currentChoices_[2].apply_(player_);
					player_.ClearLevelUp();
					state_ = GameState::Playing;
					cards_.clear();
				}
			}
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
		if (cards_.empty())
		{
			currentChoices_ = upgradeManager_.GetRandomUpgrades(3);

			for (int i = 0; i < currentChoices_.size(); i++)
			{
				UpgradeCard card(currentChoices_[i], font_);
				card.SetPosition(200.f + i * 250.f, 300.f);

				cards_.push_back(card);
			}
		}

		sf::Vector2f mousePos = window_.mapPixelToCoords(
			sf::Mouse::getPosition(window_));

		for (auto& card : cards_)
		{
			card.Update(mousePos);
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

	if (state_ == GameState::Leveling)
	{
		window_.draw(upgradePanel);

		for (auto& card : cards_)
		{
			card.Draw(window_);
		}

		window_.display();
		return;
	}

	hud_.Draw(window_);

	window_.display();
}