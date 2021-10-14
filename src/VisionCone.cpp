#include "VisionCone.h"

///////////////////////////////////////////////////////////////////////////////
VisionCone::VisionCone(float t_rangeRads, float t_radius, int t_segments) :
	m_vision{ sf::TriangleFan },
	m_position{ 0.0f, 0.0f },
	m_rotation{ 0.0f },
	m_range{ t_rangeRads },
	m_radius{ t_radius },
	m_segments{ t_segments },
	m_color{ sf::Color::Transparent }
{
}

///////////////////////////////////////////////////////////////////////////////
bool VisionCone::update(Plane const& t_self)
{
	generateCone(t_self.getPosition(), toRadians(t_self.getRotation()));

	return (t_self.getTarget()) ? checkForTarget(*t_self.getTarget()) : false;
}

///////////////////////////////////////////////////////////////////////////////
void VisionCone::setRange(float t_rangeRads)
{
	m_range = t_rangeRads;
}

///////////////////////////////////////////////////////////////////////////////
void VisionCone::setRadius(float t_radius)
{
	m_radius = t_radius;
}

///////////////////////////////////////////////////////////////////////////////
void VisionCone::setSegments(int t_segments)
{
	m_segments = t_segments;
}

///////////////////////////////////////////////////////////////////////////////
void VisionCone::generateCone(sf::Vector2f const& t_position, float t_rotationRads)
{
	m_rotation = t_rotationRads;
	m_position = t_position;

	m_vision.clear();
	m_vision.append({ m_position, m_color });

	float increments = m_range / static_cast<float>(m_segments);
	float maxAngle = m_rotation + m_range / 2.0f;
	float theta = m_rotation - m_range / 2.0f;

	for (int step = 0; step <= m_segments; step++, theta += increments)
	{
		sf::Vector2f unitDirection{ cosf(theta), sinf(theta) };
		m_vision.append({ m_position + unitDirection * m_radius, m_color });
	}
}

///////////////////////////////////////////////////////////////////////////////
bool VisionCone::checkForTarget(Plane const& t_target)
{
	float tempPlaneRadius = 32.0f;

	// Gets the vector between the entity and the vision cone position.
	sf::Vector2f distance = t_target.getPosition() - m_position;

	// Checks that the target is within range of the vision cone.
	if (magnitude(distance) < m_radius + tempPlaneRadius)
	{
		sf::Vector2f directionVec{ cos(m_rotation), sin(m_rotation) };

		// Gets the axis perpendicular to the vector from the cone to the target.
		sf::Vector2f axis = normalise({ -distance.y, distance.x });

		// Finds the min and max points of the target along the axis.
		sf::Vector2f p1 = t_target.getPosition() + axis * tempPlaneRadius;
		sf::Vector2f p2 = t_target.getPosition() - axis * tempPlaneRadius;

		// Finds the angle from the centre line to each of the edge points.
		float angleToP1 = signedAngleBetween(directionVec, p1 - m_position);
		float angleToP2 = signedAngleBetween(directionVec, p2 - m_position);

		float viewRange = m_range / 2.0f;

		// Checks if the smallest of the two angles is inside the view radius.
		if (fminf(fabsf(angleToP1), fabsf(angleToP2)) < viewRange)
		{
			m_color = sf::Color{ 255, 0, 0, 100 };
			return true;
		}
	}

	m_color = sf::Color{ 0, 0, 255, 100 };
	return false;
}

///////////////////////////////////////////////////////////////////////////////
void VisionCone::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_vision, t_states);
}

///////////////////////////////////////////////////////////////////////////////