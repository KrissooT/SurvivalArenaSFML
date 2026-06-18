#include "Core/Game.h"

#include <SFML/GpuPreference.hpp>

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle)
{
	enemies_.push_back(std::make_unique<Zombie>());
	enemies_.push_back(std::make_unique<Zombie>());
	enemies_.push_back(std::make_unique<Zombie>());

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
	for (auto& enemy : enemies_) {
		enemy->Update(dt, player_.GetPosition());
		

		if (player_.GetBounds().findIntersection(enemy->GetBounds())) {
			player_.TakeDamage(enemy->GetDamage());
		}
	}
}

void Game::Render() {
	window_.clear();

	player_.Draw(window_);
	for (auto& enemy : enemies_) {
		enemy->Draw(window_);
	}

	window_.display();
}