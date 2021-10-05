#pragma once

#include <SFML/Graphics.hpp>

#include "Plane.h"

class Player : public Plane
{
public:

	Player();
	virtual void update(float t_delta) override;

};