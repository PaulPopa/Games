#pragma once

#include "Component.h"
#include "stdincl.h"

class MainMenu : public Component
{
	REGISTER(MainMenu);
public:
	MainMenu(void);
	~MainMenu(void);

	virtual void			Update(float dtime) override;
	virtual void			PostUpdate(float dtime) override;

	void					ChangeProfile(const std::string& name);

private:



};

