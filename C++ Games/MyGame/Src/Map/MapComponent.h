#pragma once

#include "stdincl.h"
#include "Component.h"
#include "MapGenerator.h"


class MapComponent : public Component
{
	REGISTER(MapComponent);

public: 

	MapComponent();
	~MapComponent();

	virtual void									OnAddToObject() override;
	virtual void									Update(float dtime) override;
	virtual void									Draw() override;

private:
};

