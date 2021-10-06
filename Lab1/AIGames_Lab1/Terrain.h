#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

class Terrain : public sf::Drawable
{
public:

	Terrain();

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	void prerenderTerrain();

	const float m_TILE_SIZE;

	sf::Texture m_tileTexture;
	sf::RenderTexture m_terrainTexture;

	sf::Sprite m_tileSprite;
	sf::Sprite m_terrainSprite;

	int m_width;
	int m_height;

	std::vector<std::vector<int>> m_tiles;
	std::vector<sf::Vector2i> m_tileRects;

};

