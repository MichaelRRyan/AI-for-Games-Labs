#include "ArriveBehaviour.h"

float const ArriveBehaviour::m_SAFE_MARGIN{ 48.0f };

///////////////////////////////////////////////////////////////////////////////////////////////////
void ArriveBehaviour::update(Plane* t_self, float t_delta)
{
	if (t_self && t_self->getTarget())
	{
		sf::Vector2f toTarget = t_self->getTarget()->getPosition() - t_self->getPosition();
		float angle = crossProduct(t_self->getDirection(), toTarget);

		if (angle < 0.0f)
			t_self->rotateLeft(t_delta);
		else
			t_self->rotateRight(t_delta);

		float const distanceToStop = powf(t_self->getSpeed(), 2.0f) / (2.0f * t_self->getAcceleration()) + m_SAFE_MARGIN;
		float const distanceToTarget = magnitude(toTarget);

		if (distanceToTarget <= distanceToStop)
			t_self->decelerate(t_delta);
		else
			t_self->accelerate(t_delta);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////