#include "UserInputBehaviour.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void UserInputBehaviour::update(Plane* t_self, float t_delta)
{
	if (t_self)
	{
		// Handle key pressed.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Move forward.
			t_self->accelerate(t_delta);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Move backwards.
			t_self->decelerate(t_delta);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Anti-clockwise rotation.
			t_self->rotateLeft(t_delta);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Clockwise rotation.
			t_self->rotateRight(t_delta);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////