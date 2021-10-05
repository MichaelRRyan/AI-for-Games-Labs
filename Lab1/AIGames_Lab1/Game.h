#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

#include "Player.h"
#include "NPC.h"

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

	Player m_player;
	NPC m_npc;

};