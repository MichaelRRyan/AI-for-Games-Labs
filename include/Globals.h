#pragma once

#include <SFML/Graphics.hpp>

const float g_WINDOW_WIDTH{ 800.0f };
const float g_WINDOW_HEIGHT{ 600.0f };

const float g_SCALE{ 2.5f };

// Has to be wrapped in a class to avoid "multiply defined symbols" error.
class Debug
{
public:
	static bool g_debugMode; // Toggles visible vision cones and labels.
};

///////////////////////////////////////////////////////////////////////////////////////////////////
static sf::Vector2f vectorRotateBy(sf::Vector2f const& t_vector, float t_angleRadians);
static sf::Vector2f normalise(sf::Vector2f const& t_vector);
static float const angleBetween(sf::Vector2f const& t_a, sf::Vector2f const& t_b);
static float const signedAngleBetween(sf::Vector2f const& t_a, sf::Vector2f const& t_b);
static float const dotProduct(sf::Vector2f const& t_a, sf::Vector2f const& t_b);
static float const crossProduct(sf::Vector2f const& t_a, sf::Vector2f const& t_b);
static float const magnitude(sf::Vector2f const& t_a);
static float const toDegrees(float const t_angleRads);
static float const toRadians(float const t_angleDegs);
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f vectorRotateBy(sf::Vector2f const & t_vector, float t_angleRadians)
{
	return sf::Vector2f(
		t_vector.x * cosf(t_angleRadians) - t_vector.y * sinf(t_angleRadians),
		t_vector.x * sinf(t_angleRadians) + t_vector.y * cosf(t_angleRadians));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f normalise(sf::Vector2f const& t_vector)
{
	return t_vector / magnitude(t_vector);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const angleBetween(sf::Vector2f const & t_a, sf::Vector2f const & t_b)
{
	return acosf(dotProduct(t_a, t_b) / (magnitude(t_a) * magnitude(t_b)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const signedAngleBetween(sf::Vector2f const& t_a, sf::Vector2f const& t_b)
{
	return atan2f(t_a.x * t_b.y - t_a.y * t_b.x, t_a.x * t_b.x + t_a.y * t_b.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const dotProduct(sf::Vector2f const& t_a, sf::Vector2f const& t_b)
{
	return t_a.x * t_b.x + t_a.y * t_b.y;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const crossProduct(sf::Vector2f const& t_a, sf::Vector2f const& t_b)
{
	return (t_a.x * t_b.y) - (t_a.y * t_b.x);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const magnitude(sf::Vector2f const& t_a)
{
	return sqrtf(t_a.x * t_a.x + t_a.y * t_a.y);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const toDegrees(float const t_angleRads)
{
	return t_angleRads * (180.0f / 3.14f);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
float const toRadians(float const t_angleDegs)
{
	return t_angleDegs * (3.14f / 180.0f);
}

///////////////////////////////////////////////////////////////////////////////////////////////////