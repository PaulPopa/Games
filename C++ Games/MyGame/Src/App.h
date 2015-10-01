#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "MenuHandler.h"
#include "Input.h"
#include "ConsoleComponent.h"
#include "OptionsManager.h"
#include "Map.h"
#include "STAT.h"
#include "ProfilesManager.h"

class App
{
public:
	App();
	~App();

	void				Init();
	void				Draw();
	void				Run();

	int					APP_RESOLUTION_WIDTH;
	int					APP_RESOLUTION_HEIGHT;

	sf::RenderWindow	m_window;
	ConsoleComponent*	m_console;

	ObjectRef			m_fpsObject;

private:

	void				AddConsole();

	Input				m_input;
	MenuHandler			m_menuHandler;
	Scene				m_scene;
	OptionsManager		m_optionsManager;
	Map					m_map;
	STAT				m_STAT;
	ProfilesManager		m_profilesManager;

	float				m_timeAccumulator;

	void				Update(float dtime);
	void				SetFpsObject();

};

extern App* g_app;
