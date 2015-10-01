#include "OptionsManager.h"
#include "App.h"
#include "stdincl.h"
#include "Helpers.h"

OptionsManager* g_optionsManager;

OptionsManager::OptionsManager()
{
	g_optionsManager = this;
}

OptionsManager::~OptionsManager()
{
}


void OptionsManager::Load()
{
	TiXmlDocument doc;
	std::string file;

	file.append(XML_FOLDER);
	file.append("Options.xml");

	int ret = doc.LoadFile(file.c_str());
	assert(ret != 0);

	TiXmlElement* optionsElement = doc.FirstChildElement();
	for (auto a = optionsElement->FirstAttribute(); a; a = a->Next())
	{
		if (IsEqual(a->Name(), "fullscreen"))
		{
			m_fullscreen = a->BoolValue();
		}
	}
}

void OptionsManager::Unload()
{
	TiXmlDocument doc;
	std::string file;

	file.append(XML_FOLDER);
	file.append("Options.xml");

	int ret = doc.LoadFile(file.c_str());
	assert(ret != 0);

	TiXmlElement* optionsElement = doc.FirstChildElement();
	for (auto a = optionsElement->FirstAttribute(); a; a = a->Next())
	{
		if (IsEqual(a->Name(), "fullscreen"))
		{
			a->SetValue(std::to_string(m_fullscreen).c_str());
		}
	}
	doc.SaveFile();
}

void OptionsManager::RefreshWindow()
{
	if (m_fullscreen)
	{
		g_app->m_window.create(sf::VideoMode(g_app->APP_RESOLUTION_WIDTH, g_app->APP_RESOLUTION_HEIGHT), "Game", sf::Style::Fullscreen);
	}
	else
	{
		g_app->m_window.create(sf::VideoMode(g_app->APP_RESOLUTION_WIDTH, g_app->APP_RESOLUTION_HEIGHT), "Game");
	}
	g_app->m_window.setFramerateLimit(60);
}


