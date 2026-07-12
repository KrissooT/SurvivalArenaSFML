#include "Upgrades/UpgradeManager.h"
#include "Entities/Player.h"

#include <random>
#include <algorithm>

UpgradeManager::UpgradeManager() {
	InitializeUpgrades();
}

void UpgradeManager::InitializeUpgrades() {

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

	allUpgrades_.push_back({
		"Basic Attack Speed Increase",
		"Increase Player's basic attack speed by 0.2",
		[](Player& player) {player.DecreaseShootInterval(0.2f); }
		});

	allUpgrades_.push_back({
		"Heal",
		"Restore Player's health by 25",
		[](Player& player) {player.Heal(25); }
		});

	allUpgrades_.push_back({
		"Magnet",
		"Increase Player's attraction radius by 10",
		[](Player& player) {player.IncreaseAttractionRange(10.f); }
		});

	allUpgrades_.push_back({
		"Atack Range",
		"Increase Player's attack range by 25",
		[](Player& player) {player.IncreaseAttackRange(25.f); }
		});
}

std::vector<Upgrade> UpgradeManager::GetRandomUpgrades(int amount) {

	std::vector<Upgrade> result;

	std::vector<Upgrade> temp = allUpgrades_;

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(temp.begin(), temp.end(), g);

	for (int i = 0; i < amount && i < temp.size(); i++) {
		result.push_back(temp[i]);
	}

	return result;
}