#pragma once

#include <SFML/System/Vector2.hpp>

#include <string>

struct GameConfig {
	std::string windowTitle;
	sf::Vector2u windowSize;

	GameConfig();
};

inline GameConfig gConfig;