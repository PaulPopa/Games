#include <cstdlib>
#include <iostream>
#include "Obstacle.h"
#include "App.h"


const float obstacleWidth = 30.f;
const float spaceBetweenObstacles = 200.f;

float Obstacle::obstacleFree = 200.f;

Obstacle::Obstacle()
{
	freeZone = rand() % (int)(g_app->APP_HEIGHT - obstacleFree - 80) + 40;
	pointed = false;

	m_positionUp = Vector2f(g_app->APP_WIDTH , 0);
	m_positionDown = Vector2f(g_app->APP_WIDTH , freeZone + obstacleFree - 50 - 3);

	upperObstacle.setSize(Vector2f(obstacleWidth, freeZone));
	upperObstacle.setPosition(m_positionUp);
	upperObstacle.setFillColor(sf::Color(0, 102, 0));
	upperObstacle.setOutlineThickness(2);
	upperObstacle.setOutlineColor(sf::Color(0, 51, 0));

	lowerObstacle.setSize(Vector2f(obstacleWidth, g_app->APP_HEIGHT - freeZone - obstacleFree));
	lowerObstacle.setPosition(m_positionDown);
	lowerObstacle.setFillColor(sf::Color(0, 102, 0));
	lowerObstacle.setOutlineThickness(2);
	lowerObstacle.setOutlineColor(sf::Color(0, 51, 0));
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float dtime)
{
	m_positionUp.x -= 150 * dtime;
	m_positionDown.x -= 150 * dtime;

	upperObstacle.setPosition(m_positionUp);
	lowerObstacle.setPosition(m_positionDown);
}

void Obstacle::Draw()
{
	g_app->window.draw(upperObstacle);
	g_app->window.draw(lowerObstacle);
}

bool Obstacle::RequireNewObstacle()
{
	if (m_positionUp.x <= g_app->APP_WIDTH - obstacleWidth - spaceBetweenObstacles)
	{
		return true;
	}
	return false;
}

bool Obstacle::RequireDelete()
{
	if (m_positionUp.x <= -obstacleWidth)
	{
		return true;
	}
	return false;
}


