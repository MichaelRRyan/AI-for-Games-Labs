#pragma once

#include "Behaviour.h"

class WanderBehaviour : public Behaviour
{
public:
	WanderBehaviour() = default;
	SteeringOutput getSteering(SteeringInput t_input, float t_delta) override;
};

