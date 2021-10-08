#include "Plane.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
Plane::Plane(float t_acceleration, float t_rotationSpeed, float t_speed, float t_rotation) :
	m_acceleration{ t_acceleration },
	m_rotationSpeed{ t_rotationSpeed },
	m_speed{ t_speed },
	m_maxSpeed{ 500.0f },
	m_target{ nullptr }
{
	if (m_texture.loadFromFile("assets/images/planes.png"))
		m_sprite.setTexture(m_texture);

	m_sprite.setTextureRect({ 0, 0, 32, 32 });
	m_sprite.setPosition(250.0f, 250.0f);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0f,
		m_sprite.getGlobalBounds().height / 2.0f);

	m_sprite.setScale(g_SCALE, g_SCALE);

	setRotation(t_rotation);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setPlaneType(int t_type)
{
	if (t_type > 0 && t_type < 8) 
		m_sprite.setTextureRect({ 0, t_type * 32, 32, 32 });
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setPosition(sf::Vector2f t_position)
{
	m_sprite.setPosition(t_position);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::update(float t_delta)
{
	// Apply the forward movement.
	m_sprite.setPosition(m_sprite.getPosition() + m_direction * m_speed * t_delta);

	handleScreenBoundaries();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_sprite, t_states);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::handleScreenBoundaries()
{
	// Take reference to the rect and position.
	sf::FloatRect rect = m_sprite.getGlobalBounds();
	sf::Vector2f pos = m_sprite.getPosition();

	if (pos.y < -rect.height) pos.y = static_cast<float>(g_WINDOW_HEIGHT); // Top.
	if (pos.y > g_WINDOW_HEIGHT) pos.y = -rect.height; // Bottom.
	if (pos.x < -rect.width) pos.x = static_cast<float>(g_WINDOW_WIDTH); // Left.
	if (pos.x > g_WINDOW_WIDTH) pos.x = -rect.width; // Right.
	m_sprite.setPosition(pos.x, pos.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setRotation(float t_rotation)
{
	m_direction.x = cosf(t_rotation * (3.14f / 180.0f));
	m_direction.y = sinf(t_rotation * (3.14f / 180.0f));
	m_sprite.setRotation(t_rotation);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setMaxSpeed(float t_maxSpeed)
{
	m_maxSpeed = t_maxSpeed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::accelerate(float t_delta)
{
	m_speed += m_acceleration * t_delta;

	// Restrict movement to a max speed.
	if (m_speed > m_maxSpeed) m_speed = m_maxSpeed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::decelerate(float t_delta)
{
	m_speed -= m_acceleration * t_delta;

	// Restrict movement to forward only.
	if (m_speed < 0.0f) m_speed = 0.0f;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::rotateLeft(float t_delta)
{
	setRotation(m_sprite.getRotation() - m_speed * m_rotationSpeed * t_delta);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::rotateRight(float t_delta)
{
	setRotation(m_sprite.getRotation() + m_speed * m_rotationSpeed * t_delta);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f const& Plane::getPosition() const
{
	return m_sprite.getPosition();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f const& Plane::getDirection() const
{
	return m_direction;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setTarget(Plane* t_target)
{
	m_target = t_target;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Plane* Plane::getTarget() const
{
	return m_target;
}

///////////////////////////////////////////////////////////////////////////////////////////////////