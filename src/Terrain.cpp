#include "Terrain.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
Terrain::Terrain() :
	m_TILE_SIZE{ 16.0f }
{
	if (m_tileTexture.loadFromFile("assets/images/tiles.png"))
		m_tileSprite.setTexture(m_tileTexture);

	m_terrainSprite.setScale(g_SCALE, g_SCALE);

	m_tileRects = {
		{ 32, 144 },
		{ 0, 64 },
		{ 0, 80 },
		{ 0, 96 },
	};

	m_tiles = { 
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	m_width = m_tiles.at(0).size();
	m_height = m_tiles.size();

	prerenderTerrain();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Terrain::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_terrainSprite, t_states);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Terrain::prerenderTerrain()
{
	int tileSize = static_cast<int>(m_TILE_SIZE);

	m_terrainTexture.create(m_width * tileSize, m_height * tileSize);

	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			m_tileSprite.setPosition(static_cast<float>(x) * m_TILE_SIZE, 
									 static_cast<float>(y) * m_TILE_SIZE);

			sf::Vector2i tile = m_tileRects.at(m_tiles.at(y).at(x));
			m_tileSprite.setTextureRect({ tile.x, tile.y,
				tileSize, tileSize });

			m_terrainTexture.draw(m_tileSprite);
		}
	}

	m_terrainTexture.display();
	m_terrainSprite.setTexture(m_terrainTexture.getTexture());
}

///////////////////////////////////////////////////////////////////////////////////////////////////