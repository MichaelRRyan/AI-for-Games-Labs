#include "Game.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_isRunning{ false },
	m_window{ sf::VideoMode{ static_cast<unsigned>(g_WINDOW_WIDTH), 
							 static_cast<unsigned>(g_WINDOW_HEIGHT), 32u }, "AI Planes" }
{
	m_planes.push_back(new Plane(new UserInputBehaviour()));
	m_planes.push_back(new Plane(new WanderBehaviour(), 50.0f, 0.5f, 250.0f, 45.0f));
	m_planes.push_back(new Plane(new ArriveBehaviour(), 50.0f, 0.5f, 250.0f, 45.0f));
	m_planes.push_back(new Plane(new SeekBehaviour(), 50.0f, 0.5f, 250.0f, 45.0f));
	m_planes.push_back(new Plane(new FleeBehaviour(), 50.0f, 0.5f, 100.0f, 45.0f));

	m_planes.at(0)->setPlaneType(1);
	m_planes.at(1)->setPlaneType(2);
	m_planes.at(2)->setPlaneType(3);
	m_planes.at(3)->setPlaneType(4);
	m_planes.at(4)->setPlaneType(5);

	m_planes.at(1)->setTarget(m_planes.at(0));
	m_planes.at(2)->setTarget(m_planes.at(0));
	m_planes.at(3)->setTarget(m_planes.at(0));
	m_planes.at(4)->setTarget(m_planes.at(0));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////////////////////
void Game::update(float t_delta)
{
	for (Plane * plane : m_planes)
		plane->update(t_delta);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear();
	m_window.draw(m_terrain);

	for (Plane* plane : m_planes)
		m_window.draw(*plane);

	m_window.display();
}

///////////////////////////////////////////////////////////////////////////////////////////////////