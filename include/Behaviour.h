#pragma once

#include <SFML/Graphics.hpp>

class Plane;

class Behaviour
{
public:
	Behaviour() = default;
	virtual ~Behaviour() { }
	virtual void update(Plane * t_self, float t_delta) = 0;
};

#include "Plane.h"