#include "Player.h"

Player::Player() :
	Plane()
{
	setTexture("assets/images/player_ship.png");
	setRotation(20.0f);
}

void Player::update(float t_delta) 
{
	// Handle key pressed.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Move forward.
		accelerate(t_delta);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Move backwards.
		decelerate(t_delta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Anti-clockwise rotation.
		rotateLeft(t_delta);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Clockwise rotation.
		rotateRight(t_delta);

	Plane::update(t_delta);
}