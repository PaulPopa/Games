#include "MenuHandler.h"
#include "App.h"
#include "stdincl.h"
#include "Helpers.h"

MenuHandler* g_menuHandler;

const char* MenuHandler::m_menusFiles[] =
{
	"MainMenu.xml",
	"MainGame.xml",
	"OptionsMenu.xml",
	"GamePausedMenu.xml",
	"ProfileCreationMenu.xml",
	"ProfilesListMenu.xml"
};

MenuHandler::MenuHandler()
{
	g_menuHandler = this;
}

MenuHandler::~MenuHandler()
{
}

void MenuHandler::OnStart()
{
	for (uint i = 0; i < NUM_MENUS; ++i)
	{
		std::string file;
		file.append(XML_FOLDER);
		file.append(m_menusFiles[i]);

		auto menuObjPtr = Object::CreateFromFile(file);
		auto menuObjRef = menuObjPtr.get();

		g_scene->GetRoot()->InsertChild(std::move(menuObjPtr), 0);
		m_menuList.push_back(menuObjRef);
		menuObjRef->Disable();
	}

	m_currentMenu = FIRST_MENU;

	m_menuList[m_currentMenu]->Enable();
}

void MenuHandler::SwitchMenu(uint menu)
{
	m_menuList[m_currentMenu]->Disable();
	m_menuList[menu]->Enable();

	m_currentMenu = menu;
}

uint MenuHandler::GetIndex(const std::string &menu)
{
	if (IsEqual(menu.c_str(), "MainMenu"))
	{
		return 0;
	}
	else if (IsEqual(menu.c_str(), "GameMenu"))
	{
		return 1;
	}
	else if (IsEqual(menu.c_str(), "OptionsMenu"))
	{
		return 2;
	}
	else if (IsEqual(menu.c_str(), "GamePausedMenu"))
	{
		return 3;
	}
	else if (IsEqual(menu.c_str(), "ProfileCreationMenu"))
	{
		return 4;
	}
	else if (IsEqual(menu.c_str(), "ProfilesListMenu"))
	{
		return 5;
	}
	assert(nullptr);
	return 100;
}

ObjectRef MenuHandler::GetMenuObject(uint menu)
{
	return m_menuList[menu];
}