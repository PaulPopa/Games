#pragma once
#include "App.h"

class Obstacle
{

public:

	Obstacle();
	~Obstacle();

	void						Update(float dtime);
	void						Draw();

	bool						RequireDelete();
	bool						RequireNewObstacle();

	bool						pointed;

	sf::RectangleShape			upperObstacle;
	sf::RectangleShape			lowerObstacle;

	Vector2f					m_positionUp;
	Vector2f					m_positionDown;

	Vector2f					m_velocity;

	static float				obstacleFree;

private:

	float						freeZone;





};

