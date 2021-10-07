#pragma once

#include <SFML/Graphics.hpp>
#include "Plane.h"

struct SteeringInput
{
	Plane * me{ nullptr };
	Plane * target{ nullptr };
};

struct SteeringOutput
{
	sf::Vector2f linear;
	float angular;
};

class Behaviour
{
public:
	Behaviour() = default;
	virtual ~Behaviour() { }
	virtual SteeringOutput getSteering(SteeringInput t_input, float t_delta) = 0;
};

