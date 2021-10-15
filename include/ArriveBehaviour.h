#pragma once

#include "Behaviour.h"

class ArriveBehaviour : public Behaviour
{
public:
	ArriveBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
	static void arrive(Plane* t_self, sf::Vector2f const & t_targetPos, float t_delta);
private:
	static float const m_SAFE_MARGIN;
};

