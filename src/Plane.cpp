#include "Plane.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
Plane::Plane(Behaviour* t_behaviour, 
		     float t_acceleration, float t_rotationSpeed, 
		     float t_speed, float t_rotation) :
	m_velocity{ t_speed, 0.0f },
	m_acceleration{ t_acceleration },
	m_rotationSpeed{ t_rotationSpeed },
	m_maxSpeed{ 500.0f },
	m_target{ nullptr },
	m_behaviour{ t_behaviour },
	m_active{ true },
	m_angularVelocity{ 0.0f },
	m_angularFriction{ 0.7f }
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
Plane::~Plane()
{
	if (m_behaviour) delete m_behaviour;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::update(float t_delta)
{
	if (m_active)
	{
		if (m_behaviour) m_behaviour->update(this, t_delta);

		updateRotation(t_delta);
		updatePosition(t_delta);

		m_visionCone.update(*this);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::updateRotation(float t_delta)
{
	setRotation(m_sprite.getRotation() + m_angularVelocity * t_delta);
	m_angularVelocity -= m_angularVelocity * m_angularFriction * t_delta;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::updatePosition(float t_delta)
{
	// Apply the forward movement.
	m_sprite.move(m_velocity * t_delta);

	handleScreenBoundaries();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::handleScreenBoundaries()
{
	// Take reference to the rect and position.
	sf::FloatRect rect = m_sprite.getGlobalBounds();
	sf::Vector2f pos = m_sprite.getPosition();

	if (pos.y < -rect.height) pos.y = g_WINDOW_HEIGHT; // Top.
	if (pos.y > g_WINDOW_HEIGHT) pos.y = -rect.height; // Bottom.
	if (pos.x < -rect.width) pos.x = g_WINDOW_WIDTH; // Left.
	if (pos.x > g_WINDOW_WIDTH) pos.x = -rect.width; // Right.

	m_sprite.setPosition(pos.x, pos.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::accelerate(float t_delta)
{
	m_velocity += getDirection() * m_acceleration * t_delta;

	// Restrict movement to a max speed.
	if (getSpeed() > m_maxSpeed)
		m_velocity = getDirection() * m_maxSpeed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::decelerate(float t_delta)
{
	float decel = m_acceleration * t_delta;

	if (getSpeed() >= decel)
		m_velocity -= getDirection() * decel;
	else
		m_velocity = { 0.0f, 0.0f };
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::rotateLeft(float t_delta)
{
	m_angularVelocity -= getSpeed() * m_rotationSpeed * t_delta;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::rotateRight(float t_delta)
{
	m_angularVelocity += getSpeed() * m_rotationSpeed * t_delta;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Plane* Plane::getTarget() const
{
	return m_target;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f const& Plane::getPosition() const
{
	return m_sprite.getPosition();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f const& Plane::getVelocity() const
{
	return m_velocity;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f const Plane::getDirection() const
{
	if (getSpeed() != 0)
		return normalise(m_velocity);
	else
	{
		return sf::Vector2f{
			cosf(toRadians(m_sprite.getRotation())),
			sinf(toRadians(m_sprite.getRotation()))
		};
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const Plane::getRotation() const
{
	return m_sprite.getRotation();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const Plane::getAcceleration() const
{
	return m_acceleration;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const Plane::getSpeed() const
{
	return magnitude(m_velocity);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool Plane::getActive() const
{
	return m_active;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setTarget(Plane* t_target)
{
	m_target = t_target;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setPosition(sf::Vector2f const & t_position)
{
	m_sprite.setPosition(t_position);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setRotation(float t_rotation)
{
	float speed = getSpeed();
	m_velocity.x = cosf(toRadians(t_rotation));
	m_velocity.y = sinf(toRadians(t_rotation));
	m_velocity *= speed;
	m_sprite.setRotation(t_rotation);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setMaxSpeed(float t_maxSpeed)
{
	m_maxSpeed = t_maxSpeed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setActive(bool t_active)
{
	m_active = t_active;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::setPlaneType(int t_type)
{
	if (t_type > 0 && t_type < 8)
		m_sprite.setTextureRect({ 0, t_type * 32, 32, 32 });
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Plane::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	if (m_active)
	{
		t_target.draw(m_visionCone, t_states);
		t_target.draw(m_sprite, t_states);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////