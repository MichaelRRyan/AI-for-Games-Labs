#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Globals.h"

class Behaviour;

class Plane : public sf::Drawable
{
public:

	Plane(Behaviour * t_behaviour,
		  float t_acceleration = 50.0f, float t_rotationSpeed = 0.2f,
		  float t_speed = 0.0f, float t_rotation = 0.0f);

	virtual ~Plane();

	virtual void update(float t_delta);

	void accelerate(float t_delta);
	void decelerate(float t_delta);
	void rotateLeft(float t_delta);
	void rotateRight(float t_delta);

	sf::Vector2f const & getPosition() const;
	sf::Vector2f const getDirection() const;
	float const getAcceleration() const;
	float const getSpeed() const;

	void setTarget(Plane* t_target);
	Plane * getTarget() const;

	void setPlaneType(int t_type);

protected:

	void setPosition(sf::Vector2f t_position);
	void setRotation(float t_rotation);
	void setMaxSpeed(float t_maxSpeed);

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	void handleScreenBoundaries();

	Behaviour * m_behaviour;
	Plane* m_target;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_velocity;

	float m_acceleration;
	float m_rotationSpeed;
	float m_maxSpeed;

};

#include "Behaviour.h"