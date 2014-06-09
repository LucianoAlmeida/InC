#include "menu.h"

Menu::Menu(const string& path) : SecondLayer(path)
{
	m_mouse = {400,300,1,1};
	m_selection = 0;
	m_mouseSelect = false;
	m_mouseCollision = false;
	m_select = false;
	SDL_ShowCursor(1);
}

Menu::~Menu()
{}

bool
Menu::isSelected()
{
	if(((m_mouseSelect) && (m_mouseCollision)) || (m_select))
	{
		loop("[MainMenu] MouseOver + MouseSelect or Keyboard Select = True.");
		return true;
	}
	else
	{
		loop("[MainMenu] If not Selected, reset the MouseSelect and return False.");
		m_mouseSelect = false;
		return false;
	}
}

bool
Menu::checkCollision(int selection, SDL_Rect targetPosition)
{
	if(ifCollided(0,m_mouse,targetPosition))
	{
		loop("[MainMenu] Returning true, Mouse collided with some Option Rect.");
		m_selection = selection;
		return true;
	}
	else
		return false;
}