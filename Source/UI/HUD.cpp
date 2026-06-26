#include "UI/HUD.h"

#include <algorithm>

HUD::HUD() :
	font_("Content/Fonts/Font.ttf"),
	healthDisplay_(font_),
	healthBarBackgroundTexture_("Content/Backgrounds/HealthBarBackground.png"),
	healthBarBackgroundSprite_(healthBarBackgroundTexture_),
	maxHealthBarWidth_(180.f)
{
	healthBar_.setSize({maxHealthBarWidth_, 20.f});
	healthBar_.setFillColor(sf::Color::Red);
	healthBar_.setPosition({ 23.f, 29.f });

	healthBarBackgroundSprite_.setScale({ 0.142f,0.22f });
	healthBarBackgroundSprite_.setOrigin(healthBarBackgroundSprite_.getGlobalBounds().size / 2.f);
	healthBarBackgroundSprite_.setPosition({ 20.f, -33.f });

	healthDisplay_.setCharacterSize(20);
	healthDisplay_.setFillColor(sf::Color::White);
	healthDisplay_.setPosition({90.f, 28.f});

}

void HUD::Update(const Player& player) {
	healthDisplay_.setString("HP: " + std::to_string((int)player.GetHealth()));

	float percentage = player.GetHealth() / player.GetMaxHealth();
	percentage = std::clamp(percentage, 0.f, 1.f);

	healthBar_.setSize({
		maxHealthBarWidth_ * percentage,
		20.f
		});

}

void HUD::Draw(sf::RenderWindow& window) {
	window.draw(healthBarBackgroundSprite_);
	window.draw(healthBar_);
	window.draw(healthDisplay_);
}