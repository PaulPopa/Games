#pragma once
#include "App.h"
#include "Obstacle.h"
#include <vector>

class Obstacles
{

public:

	Obstacles();
	~Obstacles();

	std::vector<Obstacle>			m_obstacles;

	void							Update(float dtime);
	void							Draw();
};

