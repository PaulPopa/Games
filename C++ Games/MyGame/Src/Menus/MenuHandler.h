#pragma once

#include "Component.h"
#include "stdincl.h"
#define FIRST_MENU 0

enum MENUS {MAIN_MENU, MAIN_GAME, OPTION_MENU, GAME_PAUSED_MENU, PROFILE_CREATION_MENU, PROFILES_LIST_MENU, NUM_MENUS};

class MenuHandler 
{

public:

	MenuHandler(void);
	~MenuHandler(void);

	virtual void							OnStart();	

	virtual void							SwitchMenu(uint menu);
	uint									GetIndex(const std::string &menu);

	ObjectRef								GetMenuObject(uint menu);

private:

	static const char*						m_menusFiles[];

	std::vector<ObjectRef>					m_menuList;
	
	uint									m_currentMenu;

};


extern MenuHandler* g_menuHandler;
