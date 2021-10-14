#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Plane.h"

class TrackerLabel : public sf::Drawable
{
public:

	TrackerLabel(std::string const & t_string = "", Plane * t_target = nullptr, bool t_matchVisibility = true);

	void update();

	void setString(std::string const & t_string);
	void setTarget(Plane * t_target);
	void setMatchVisibility(bool t_matchVisibility);

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	static sf::Font m_font;
	sf::Text m_text;

	Plane * m_target;
	bool m_matchVisibility;
	bool m_visible;

};

