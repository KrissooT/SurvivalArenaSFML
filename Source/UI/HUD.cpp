#include "UI/HUD.h"

#include <algorithm>
#include <iostream>

HUD::HUD() :
	font_("Content/Fonts/Font.ttf"),
	healthDisplay_(font_),
	healthBarBackgroundTexture_("Content/Backgrounds/HealthBarBackground.png"),
	healthBarBackgroundSprite_(healthBarBackgroundTexture_),
	maxHealthBarWidth_(243.5f),
	xpBarBackgroundTexture_("Content/Backgrounds/XpBarBackground.png"),
	xpBarBackgroundSprite_(xpBarBackgroundTexture_),
	maxXpBarWidth_(735.f),
	heartIconTexture_("Content/Backgrounds/Heart.png"),
	heartIconSprite_(heartIconTexture_)

{
	//Health
	healthBar_.setSize({ maxHealthBarWidth_,24.f });
	healthBar_.setFillColor(sf::Color::Red);
	healthBar_.setOrigin(healthBar_.getGlobalBounds().getCenter());
	healthBar_.setPosition({ 184.f, 80.f });

	healthBarBackgroundSprite_.setScale({ 1.f,1.f });
	healthBarBackgroundSprite_.setOrigin(healthBarBackgroundSprite_.getGlobalBounds().getCenter());
	healthBarBackgroundSprite_.setPosition({ 184.f, 75.f });

	heartIconSprite_.setScale({ 0.9f, 0.9f });
	heartIconSprite_.setOrigin(heartIconSprite_.getGlobalBounds().getCenter());
	heartIconSprite_.setPosition({ 26.f, 80.f });

	healthDisplay_.setCharacterSize(15);
	healthDisplay_.setFillColor(sf::Color::White);
	healthDisplay_.setPosition({ 160.f, 67.f });

	//Xp
	xpBar_.setSize({ maxXpBarWidth_, 20.f });
	xpBar_.setFillColor(sf::Color(119, 196, 254));
	xpBar_.setOrigin({0.f, 0.f});
	xpBar_.setPosition({ 65.f, 29.f });

	xpBarBackgroundSprite_.setScale({ 1.f, .5f });
	xpBarBackgroundSprite_.setOrigin(xpBarBackgroundSprite_.getGlobalBounds().getCenter());
	xpBarBackgroundSprite_.setPosition({ 433.f, 30.f });

	//auto bounds = xpBarBackgroundSprite_.getGlobalBounds();

	//std::cout << "Width: " << bounds.size.x << '\n';
	//std::cout << "Height: " << bounds.size.y << '\n';  //For testing sizes
}

void HUD::Update(const Player& player, Camera& camera) {
	healthDisplay_.setString("HP: " + std::to_string((int)player.GetHealth()));

	//Health
	float healthPercentage = player.GetHealth() / player.GetMaxHealth();
	healthPercentage = std::clamp(healthPercentage, 0.f, 1.f);

	healthBar_.setSize({
		maxHealthBarWidth_ * healthPercentage,
		15.f
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
	window.draw(heartIconSprite_);

	//Xp
	window.draw(xpBarBackgroundSprite_);
	window.draw(xpBar_);
}