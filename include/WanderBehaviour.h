#pragma once

#include "Behaviour.h"

class WanderBehaviour : public Behaviour
{
public:
	WanderBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
};

