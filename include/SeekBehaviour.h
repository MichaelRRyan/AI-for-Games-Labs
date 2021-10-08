#pragma once

#include "Behaviour.h"

class SeekBehaviour : public Behaviour
{
public:
	SeekBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
};

