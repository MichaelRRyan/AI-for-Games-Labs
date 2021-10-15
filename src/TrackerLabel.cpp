#include "TrackerLabel.h"

sf::Font TrackerLabel::m_font;

///////////////////////////////////////////////////////////////////////////////////////////////////
TrackerLabel::TrackerLabel(std::string const& t_string, Plane* t_target, bool t_matchVisibility) :
	m_text(t_string, m_font),
	m_target{ t_target },
	m_matchVisibility{ t_matchVisibility },
	m_visible{ true }
{
	if (m_font.getInfo().family == "") // If the family is blank the font hasn't been loaded.
	{
		if (!m_font.loadFromFile("assets/fonts/arial.ttf"))
			std::cout << "Error loading TrackerLabel font." << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void TrackerLabel::update()
{
	if (m_target)
	{
		m_text.setPosition(m_target->getPosition());

		if (m_matchVisibility)
			m_visible = m_target->getActive();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void TrackerLabel::setString(std::string const& t_string)
{
	m_text.setString(t_string);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void TrackerLabel::setTarget(Plane* t_target)
{
	m_target = t_target;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void TrackerLabel::setMatchVisibility(bool t_matchVisibility)
{
	m_matchVisibility = t_matchVisibility;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void TrackerLabel::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	if (Debug::g_debugMode && m_visible)
		t_target.draw(m_text, t_states);
}

///////////////////////////////////////////////////////////////////////////////////////////////////