#include "NPC.h"

NPC::NPC() :
	m_speed{ 0.0f },
	m_acceleration{ 50.0f },
	m_rotationSpeed{ 0.2f }
{
}

void NPC::update(float t_delta)
{
}

void NPC::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
}

void NPC::handleScreenBoundaries()
{
}

void NPC::setRotation(float t_rotation)
{
}
