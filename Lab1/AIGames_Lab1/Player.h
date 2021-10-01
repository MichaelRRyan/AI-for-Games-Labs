#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:

	Player();
	void update(float t_delta);

private:

	virtual void draw(sf::RenderTarget & t_target, sf::RenderStates t_states) const;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_acceleration;

};

