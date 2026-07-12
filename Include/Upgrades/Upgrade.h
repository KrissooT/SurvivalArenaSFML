#pragma once

#include "Entities/Player.h"

#include <string>
#include <functional>

struct Upgrade {

	std::string name_;
	std::string description_;
	std::function<void(Player&)> apply_;
};