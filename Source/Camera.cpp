#include "Camera/Camera.h"

Camera::Camera() {
	camera_.setSize({ 1280.f, 720.f });
}

void Camera::Update(sf::Vector2f playerPos) {
	camera_.setCenter(playerPos);
}

void Camera::Draw(sf::RenderWindow& window) {
	window.setView(camera_);
}

void Camera::CalculateBounds() {


	sf::Vector2f center = camera_.getCenter();
	sf::Vector2f size = camera_.getSize();
	cameraBounds_ = sf::FloatRect(
		{ center.x - size.x / 2.f, center.y - size.y / 2.f },
		{ size.x, size.y }
	);
}

sf::FloatRect Camera::GetBounds() {
	CalculateBounds();
	return cameraBounds_;
}