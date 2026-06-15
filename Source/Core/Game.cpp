#include "Core/Game.h"

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(800,800)), "Survival Arena")
{

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

void Game::Update() {
	//TODO
}

void Game::Render() {
	window_.clear();
	window_.display();
}