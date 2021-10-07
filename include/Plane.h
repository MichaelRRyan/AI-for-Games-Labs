#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Globals.h"

class Plane : public sf::Drawable
{
public:

	Plane(float t_acceleration = 50.0f, float t_rotationSpeed = 0.2f, 
		  float t_speed = 0.0f, float t_rotation = 0.0f);

	virtual void update(float t_delta);

protected:

	void setPlaneType(int t_type);
	void setPosition(sf::Vector2f t_position);
	void setRotation(float t_rotation);
	void setMaxSpeed(float t_maxSpeed);

	void accelerate(float t_delta);
	void decelerate(float t_delta);
	void rotateLeft(float t_delta);
	void rotateRight(float t_delta);

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	void handleScreenBoundaries();

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_direction;
	float m_speed;
	float m_acceleration;
	float m_rotationSpeed;
	float m_maxSpeed;
};