#include "Terrain.h"

Terrain::Terrain() :
	m_TILE_SIZE{ 16.0f }
{
	prerenderTerrain();
}

void Terrain::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_terrainSprite, t_states);
}

void Terrain::prerenderTerrain()
{
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			m_tileSprite.setPosition(x * m_TILE_SIZE, y * m_TILE_SIZE);
		}
	}
}