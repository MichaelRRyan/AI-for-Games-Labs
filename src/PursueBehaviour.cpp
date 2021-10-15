#include "PursueBehaviour.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
PursueBehaviour::PursueBehaviour(float t_maxTimePrediction) : 
	m_maxTimePrediction{ t_maxTimePrediction }
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void PursueBehaviour::update(Plane* t_self, float t_delta)
{
	Plane * target = t_self->getTarget();
	if (target == nullptr) return;

	sf::Vector2f toTarget = target->getPosition() - t_self->getPosition();
	float distance = magnitude(toTarget);
	float speed = t_self->getSpeed();

	float timePrediction = (speed <= distance / m_maxTimePrediction) ?
		m_maxTimePrediction : distance / speed;

	sf::Vector2f targetPosition = target->getPosition() + target->getVelocity() * timePrediction;

	ArriveBehaviour::arrive(t_self, targetPosition, t_delta);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void PursueBehaviour::setMaxTimePrediction(float t_maxTimePrediction)
{
	m_maxTimePrediction = t_maxTimePrediction;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float PursueBehaviour::getMaxTimePrediction() const
{
	return m_maxTimePrediction;
}

///////////////////////////////////////////////////////////////////////////////////////////////////