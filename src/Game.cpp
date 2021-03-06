#include "Game.h"

bool Debug::g_debugMode{ true };

///////////////////////////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_isRunning{ false },
	m_window{ sf::VideoMode{ static_cast<unsigned>(g_WINDOW_WIDTH), 
							 static_cast<unsigned>(g_WINDOW_HEIGHT), 32u }, "AI Planes" }
{
	setupPlanes();
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
		else if (sf::Event::KeyPressed == newEvent.type)
		{
			// Checks the number keys from 1 to 6.
			if (newEvent.key.code >= 27 && newEvent.key.code <= 32)
			{
				// Toggle on/off the corresponding plane.
				int index = newEvent.key.code - 26;
				Plane* plane = m_planes.at(index);
				plane->setActive(!plane->getActive());
			}
			// Toggles visible vision cones and labels.
			else if (sf::Keyboard::D == newEvent.key.code)
				Debug::g_debugMode = !Debug::g_debugMode;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Game::update(float t_delta)
{
	for (Plane * plane : m_planes)
		plane->update(t_delta);

	for (TrackerLabel & label : m_trackerLabels)
		label.update();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear();
	m_window.draw(m_terrain);

	for (Plane * plane : m_planes)
		m_window.draw(*plane);

	for (TrackerLabel const & label : m_trackerLabels)
		m_window.draw(label);

	m_window.display();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Game::setupPlanes()
{
	m_planes.push_back(new Plane(new UserInputBehaviour(), 25.0f, 0.5f));
	m_planes.push_back(new Plane(new WanderBehaviour(), 25.0f, 3.0f, 125.0f, 45.0f));
	m_planes.push_back(new Plane(new ArriveBehaviour(), 50.0f, 1.0f, 200.0f, 45.0f));
	m_planes.push_back(new Plane(new ArriveBehaviour(), 15.0f, 0.5f, 80.0f, 45.0f));
	m_planes.push_back(new Plane(new SeekBehaviour(), 25.0f, 0.5f, 125.0f, 45.0f));
	m_planes.push_back(new Plane(new PursueBehaviour(), 25.0f, 0.5f, 125.0f, 45.0f));
	m_planes.push_back(new Plane(new FleeBehaviour(), 25.0f, 0.5f, 50.0f, 45.0f));

	m_planes.at(0)->setPlaneType(1);
	m_planes.at(1)->setPlaneType(2);
	m_planes.at(2)->setPlaneType(3);
	m_planes.at(3)->setPlaneType(3);
	m_planes.at(4)->setPlaneType(4);
	m_planes.at(5)->setPlaneType(5);
	m_planes.at(6)->setPlaneType(6);

	m_planes.at(1)->setTarget(m_planes.at(0));
	m_planes.at(2)->setTarget(m_planes.at(0));
	m_planes.at(3)->setTarget(m_planes.at(0));
	m_planes.at(4)->setTarget(m_planes.at(0));
	m_planes.at(5)->setTarget(m_planes.at(0));
	m_planes.at(6)->setTarget(m_planes.at(0));

	m_trackerLabels.emplace_back("1. Wander", m_planes.at(1));
	m_trackerLabels.emplace_back("2. Fast Arrive", m_planes.at(2));
	m_trackerLabels.emplace_back("3. Slow Arrive", m_planes.at(3));
	m_trackerLabels.emplace_back("4. Seek", m_planes.at(4));
	m_trackerLabels.emplace_back("5. Pursue", m_planes.at(5));
	m_trackerLabels.emplace_back("6. Flee", m_planes.at(6));
}

///////////////////////////////////////////////////////////////////////////////////////////////////