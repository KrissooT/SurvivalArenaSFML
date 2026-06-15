#include "Config/GameConfig.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <cassert>

GameConfig::GameConfig() {
	std::ifstream file("Content/Config/GameConfig.json");
	assert(file);

	nlohmann::json json = nlohmann::json::parse(file);
	windowSize.x = json["windowSize"][0];
	windowSize.y = json["windowSize"][1];
	windowTitle = json["windowTitle"];

}