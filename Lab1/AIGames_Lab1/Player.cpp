#include "Player.h"

Player::Player() :
	m_acceleration{ -50.0f }
{
	if (m_texture.loadFromFile("assets/images/player_ship.png"))
		m_sprite.setTexture(m_texture);
	m_sprite.setScale(2.5f, 2.5f);
	m_sprite.setPosition(250.0f, 250.0f);
}

void Player::update(float t_delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_acceleration -= 50.0f * t_delta;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_acceleration += 50.0f * t_delta;
	}

	sf::Vector2f position = m_sprite.getPosition();
	position.y += m_acceleration * t_delta;
	if (position.y < -m_sprite.getGlobalBounds().height) position.y = 600.0f;
	if (position.y > 600.0f) position.y = -m_sprite.getGlobalBounds().height;
	m_sprite.setPosition(position);
}

void Player::draw(sf::RenderTarget & t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_sprite, t_states);
}
