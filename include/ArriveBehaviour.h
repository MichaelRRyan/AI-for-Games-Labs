#pragma once

#include "Behaviour.h"

class ArriveBehaviour : public Behaviour
{
public:
	ArriveBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
private:
	static float const m_SAFE_MARGIN;
};

