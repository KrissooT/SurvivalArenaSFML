#include "Pickups/Pickup.h"

Pickup::Pickup(float attractionRadius) :
	attractionRadius_(attractionRadius)
{
}

void Pickup::MoveToPlayer(float dt, sf::Vector2f playerPos, sf::Shape& itemShape) {

	sf::Vector2f position = itemShape.getPosition();
	sf::Vector2f direction = playerPos - position;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length != 0.f) {
		direction /= length;
	}
	itemShape.move({ direction * attractionSpeed * dt });

}