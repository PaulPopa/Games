#pragma once

#include "Component.h"
#include "stdincl.h"

class MainGame : public Component
{
	REGISTER(MainGame);

public:

	MainGame(void);
	~MainGame(void);

	virtual void			Update(float dtime) override;
	virtual void			PostUpdate(float dtime) override;


private:

};

