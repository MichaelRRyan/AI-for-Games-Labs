#pragma once

#include "Behaviour.h"

class UserInputBehaviour : public Behaviour
{
public:
	UserInputBehaviour() = default;
	void update(Plane * t_self, float t_delta) override;
};