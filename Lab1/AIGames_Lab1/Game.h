#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

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

};

