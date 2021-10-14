#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

#include "Terrain.h"
#include "TrackerLabel.h"

#include "UserInputBehaviour.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "ArriveBehaviour.h"
#include "FleeBehaviour.h"

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

	Terrain m_terrain;
	std::vector<Plane *> m_planes;
	std::vector<TrackerLabel> m_trackerLabels;

};