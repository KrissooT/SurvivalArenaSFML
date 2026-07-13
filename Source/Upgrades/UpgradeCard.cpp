#include "Upgrades/UpgradeCard.h"

UpgradeCard::UpgradeCard(const Upgrade& upgrade, const sf::Font& font) :
    nameText_(font),
    descriptionText_(font)
{
    Initialize(upgrade,font);
}

void UpgradeCard::Initialize(const Upgrade& upgrade, const sf::Font& font) {

	upgrade_ = upgrade;

    cardBox_.setSize({ 200.f, 120.f });
    cardBox_.setFillColor(sf::Color::Black);
    cardBox_.setOutlineThickness(2.f);
    cardBox_.setOutlineColor(sf::Color::White);


    nameText_.setCharacterSize(18);
    nameText_.setString(upgrade.name_);


    descriptionText_.setCharacterSize(14);
    descriptionText_.setString(upgrade.description_);

}

void UpgradeCard::SetPosition(float x, float y)
{
    cardBox_.setPosition({ x, y });
    nameText_.setPosition({ x + 10.f, y + 10.f });
    descriptionText_.setPosition({ x + 10.f, y + 50.f });
}

void UpgradeCard::Update(const sf::Vector2f& mousePos)
{
    isHovered_ = cardBox_.getGlobalBounds().contains(mousePos);

    if (isHovered_)
    {
        cardBox_.setScale({ 1.05f, 1.05f });
        cardBox_.setFillColor(sf::Color(80, 80, 80));
    }
    else
    {
        cardBox_.setScale({ 1.f, 1.f });
        cardBox_.setFillColor(sf::Color::Black);
    }
}

bool UpgradeCard::IsClicked(const sf::Vector2f& mousePos) const
{
    return cardBox_.getGlobalBounds().contains(mousePos);
}

const Upgrade& UpgradeCard::GetUpgrade() const
{
    return upgrade_;
}

void UpgradeCard::Draw(sf::RenderWindow& window)
{
    window.draw(cardBox_);
    window.draw(nameText_);
    window.draw(descriptionText_);
}
