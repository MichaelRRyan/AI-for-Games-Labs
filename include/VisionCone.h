#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Plane;

class VisionCone : public sf::Drawable
{
public:

	VisionCone(float t_rangeRads = toRadians(90.0f), float t_radius = 128.0f, int t_segments = 20);
	bool update(Plane const & t_self);
	
	void setRange(float t_rangeRads);
	void setRadius(float t_radius);
	void setSegments(int t_segments);

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	void generateCone(sf::Vector2f const& t_position, float t_directionRads);
	bool checkForTarget(Plane const& t_target);

	sf::VertexArray m_vision;
	sf::Vector2f m_position;

	sf::Color m_color;

	// The rotation of the cone in radians.
	float m_rotation;

	// How far the cone extends from side to side in radians.
	float m_range;

	// The radius from the origin of the cone to the centre of the end.
	float m_radius;

	// the number of segments (triangles) used.
	int m_segments;

};

#include "Plane.h"