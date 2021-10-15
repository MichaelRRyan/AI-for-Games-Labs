#include "ArriveBehaviour.h"

float const ArriveBehaviour::m_SAFE_MARGIN{ 48.0f };

///////////////////////////////////////////////////////////////////////////////////////////////////
void ArriveBehaviour::update(Plane* t_self, float t_delta)
{
	if (t_self == nullptr || t_self->getTarget() == nullptr) return;
	
	arrive(t_self, t_self->getTarget()->getPosition(), t_delta);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void ArriveBehaviour::arrive(Plane* t_self, sf::Vector2f const& t_targetPos, float t_delta)
{
	sf::Vector2f toTarget = t_targetPos - t_self->getPosition();
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

///////////////////////////////////////////////////////////////////////////////////////////////////