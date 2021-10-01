#include "Game.h"

Game::Game() :
	m_isRunning{ false },
	m_window{ sf::VideoMode{ 800u, 600u, 32u }, "Lab 1" }
{
}

Game::~Game()
{
}

void Game::run()
{
	m_isRunning = true;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_isRunning)
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame.asSeconds()); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_isRunning = false;
			m_window.close();
		}
	}
}

void Game::update(float t_delta)
{
}

void Game::render()
{
	m_window.clear();
	m_window.display();
}
