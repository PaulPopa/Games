#include "Obstacles.h"
#include "App.h"

Obstacles::Obstacles()
{
	m_obstacles.push_back(Obstacle());
}

Obstacles::~Obstacles()
{
}

void Obstacles::Update(float dtime)
{
	for (unsigned i = 0; i < m_obstacles.size(); ++i)
	{
		m_obstacles[i].Update(dtime);
	}

	if (m_obstacles[m_obstacles.size() - 1].RequireNewObstacle())
	{
		m_obstacles.push_back(Obstacle());
	}

	if (m_obstacles[0].RequireDelete())
	{
		m_obstacles.erase(m_obstacles.begin());
	}
}

void Obstacles::Draw()
{
	for (unsigned i = 0; i < m_obstacles.size(); ++i)
	{
		m_obstacles[i].Draw();
	}
}
