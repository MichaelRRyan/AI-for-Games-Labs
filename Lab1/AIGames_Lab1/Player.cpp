#include "Player.h"

Player::Player() :
	m_speed{ 0.0f },
	m_acceleration{ 50.0f },
	m_rotationSpeed{ 0.2f }
{
	if (m_texture.loadFromFile("assets/images/player_ship.png"))
		m_sprite.setTexture(m_texture);
	m_sprite.setPosition(250.0f, 250.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0f,
					   m_sprite.getGlobalBounds().height / 2.0f);
	m_sprite.setScale(2.5f, 2.5f);

	setRotation(20.0f);
}

void Player::update(float t_delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_speed += m_acceleration * t_delta;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_speed -= m_acceleration * t_delta;
		if (m_speed < 0.0f) m_speed = 0; // Restrict movement to forward only.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		setRotation(m_sprite.getRotation() - m_speed * m_rotationSpeed * t_delta);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		setRotation(m_sprite.getRotation() + m_speed * m_rotationSpeed * t_delta);

	m_sprite.setPosition(m_sprite.getPosition() + m_direction * m_speed * t_delta);
	handleScreenBoundaries();
}

void Player::draw(sf::RenderTarget & t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_sprite, t_states);
}

void Player::handleScreenBoundaries()
{
	sf::FloatRect rect = m_sprite.getGlobalBounds();
	sf::Vector2f pos = m_sprite.getPosition();
	if (pos.y < -rect.height) pos.y = Game::s_WINDOW_HEIGHT; // Top.
	if (pos.y > Game::s_WINDOW_HEIGHT) pos.y = -rect.height; // Bottom.
	if (pos.x < -rect.width) pos.x = Game::s_WINDOW_WIDTH; // Left.
	if (pos.x > Game::s_WINDOW_WIDTH) pos.x = -rect.width; // Right.
	m_sprite.setPosition(pos.x, pos.y);
}

void Player::setRotation(float t_rotation)
{
	m_direction.x = cosf(t_rotation * (3.14f / 180.0f));
	m_direction.y = sinf(t_rotation * (3.14f / 180.0f));
	m_sprite.setRotation(t_rotation);
}
