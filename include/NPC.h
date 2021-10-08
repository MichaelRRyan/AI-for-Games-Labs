#pragma once

#include <SFML/Graphics.hpp>
#include "Plane.h"
#include "Behaviour.h"
#include "SeekBehaviour.h"

class NPC : public Plane
{
public:

	NPC(Behaviour * t_behaviour = new SeekBehaviour());
	~NPC();
	void update(float t_delta);

private:

	Behaviour * m_behaviour;

};

