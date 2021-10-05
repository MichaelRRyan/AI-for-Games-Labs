#pragma once

#include <SFML/Graphics.hpp>

class Game;

class Player : public sf::Drawable
{
public:

	Player();
	void update(float t_delta);

private:

	virtual void draw(sf::RenderTarget & t_target, sf::RenderStates t_states) const;

	void handleScreenBoundaries();
	void setRotation(float t_rotation);

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_direction;
	float m_speed;
	float m_acceleration;
	float m_rotationSpeed;

};

#include "Game.h"