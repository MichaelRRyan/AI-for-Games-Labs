#pragma once

#include "Behaviour.h"

class FleeBehaviour : public Behaviour
{
public:
	FleeBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
};

