#include "UI/HUD.h"

#include <algorithm>
#include <iostream>

HUD::HUD() :
	font_("Content/Fonts/Font.ttf"),
	healthDisplay_(font_),
	healthBarBackgroundTexture_("Content/Backgrounds/HealthBarBackground.png"),
	healthBarBackgroundSprite_(healthBarBackgroundTexture_),
	maxHealthBarWidth_(180.f),
	xpBarBackgroundTexture_("Content/Backgrounds/XpBarBackground.png"),
	xpBarBackgroundSprite_(xpBarBackgroundTexture_),
	maxXpBarWidth_(610.f)
{
	//Health
	healthBar_.setSize({ maxHealthBarWidth_, 20.f });
	healthBar_.setFillColor(sf::Color::Red);
	healthBar_.setOrigin(healthBar_.getGlobalBounds().getCenter());
	healthBar_.setPosition({ 114.f, 39.f });

	healthBarBackgroundSprite_.setScale({ 0.142f,0.22f });
	healthBarBackgroundSprite_.setOrigin(healthBarBackgroundSprite_.getGlobalBounds().getCenter());
	healthBarBackgroundSprite_.setPosition({ 20.f, -33.f });

	healthDisplay_.setCharacterSize(20);
	healthDisplay_.setFillColor(sf::Color::White);
	healthDisplay_.setPosition({ 90.f, 28.f });

	//Xp
	xpBar_.setSize({ maxXpBarWidth_, 20.f });
	xpBar_.setFillColor(sf::Color(119, 196, 254));
	xpBar_.setOrigin({0.f, 0.f});
	xpBar_.setPosition({ 237.f, 29.f });

	xpBarBackgroundSprite_.setScale({ 0.1f,0.05f });
	xpBarBackgroundSprite_.setOrigin(xpBarBackgroundSprite_.getGlobalBounds().getCenter());
	xpBarBackgroundSprite_.setPosition({250.f, 25.f});

}

void HUD::Update(const Player& player) {
	healthDisplay_.setString("HP: " + std::to_string((int)player.GetHealth()));

	//Health
	float healthPercentage = player.GetHealth() / player.GetMaxHealth();
	healthPercentage = std::clamp(healthPercentage, 0.f, 1.f);

	healthBar_.setSize({
		maxHealthBarWidth_ * healthPercentage,
		20.f
		});

	//Xp
	float xpPercentage = (float)player.GetCurrentXp() / (float)player.GetXpToNextLevel();

	xpPercentage = std::clamp(xpPercentage, 0.f, 1.f);

	xpBar_.setSize({
		maxXpBarWidth_ * xpPercentage,
		20.f
		});
}

void HUD::Draw(sf::RenderWindow& window) {
	//Health
	window.draw(healthBarBackgroundSprite_);
	window.draw(healthBar_);
	window.draw(healthDisplay_);

	//Xp
	window.draw(xpBarBackgroundSprite_);
	window.draw(xpBar_);
}