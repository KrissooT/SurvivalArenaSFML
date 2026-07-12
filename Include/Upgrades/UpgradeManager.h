#pragma once

#include "Upgrades/Upgrade.h"

#include <vector>

class UpgradeManager {

	private:

		std::vector<Upgrade> allUpgrades_;

	public:
		//Constructor
		UpgradeManager();

		//Core
		void InitializeUpgrades();

		std::vector<Upgrade> GetRandomUpgrades(int count);
};