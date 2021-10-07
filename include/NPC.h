#pragma once

#include <SFML/Graphics.hpp>
#include "Plane.h"
#include "Behaviour.h"
#include "WanderBehaviour.h"

class NPC : public Plane
{
public:

	NPC();
	~NPC();
	void update(float t_delta);

private:

	Behaviour * m_behaviour;

};

