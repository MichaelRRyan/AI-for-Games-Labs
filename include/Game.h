#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

#include "Player.h"
#include "NPC.h"
#include "Terrain.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"

class Game
{
public:

	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update(float t_delta);
	void render();

	bool m_isRunning;

	sf::RenderWindow m_window;

	std::vector<Plane *> m_planes;
	Terrain m_terrain;

};