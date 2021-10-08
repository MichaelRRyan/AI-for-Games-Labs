#include "SeekBehaviour.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////////////////
void SeekBehaviour::update(Plane * t_self, float t_delta)
{
	if (t_self && t_self->getTarget())
	{
		sf::Vector2f toTarget = t_self->getTarget()->getPosition() - t_self->getPosition();

		float angle = crossProduct(t_self->getDirection(), toTarget);

		if (angle < 0.0f)
			t_self->rotateLeft(t_delta);
		else
			t_self->rotateRight(t_delta);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////