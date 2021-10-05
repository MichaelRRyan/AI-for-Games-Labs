#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
public:

	Game();
	~Game();

	void run();

	static const unsigned s_WINDOW_WIDTH;
	static const unsigned s_WINDOW_HEIGHT;

private:

	void processEvents();
	void update(float t_delta);
	void render();

	bool m_isRunning;

	sf::RenderWindow m_window;

	Player m_player;

};

