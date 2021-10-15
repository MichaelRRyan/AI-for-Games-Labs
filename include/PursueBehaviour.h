#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"
#include "ArriveBehaviour.h"
#include "Globals.h"

class PursueBehaviour : public Behaviour
{
public:

	PursueBehaviour(float t_maxTimePrediction = 3.0f);

	void update(Plane * t_self, float t_delta) override;

	void setMaxTimePrediction(float t_maxTimePrediction);
	float getMaxTimePrediction() const;

private:

	float m_maxTimePrediction;

};

