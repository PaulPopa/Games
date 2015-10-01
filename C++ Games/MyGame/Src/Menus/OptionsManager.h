#pragma once

#include "stdincl.h"

class OptionsManager
{

public:

	OptionsManager(void);
	~OptionsManager(void);

	void						Load();
	void						Unload();
	void						RefreshWindow();

	bool						m_fullscreen;

private:

};

extern OptionsManager* g_optionsManager;