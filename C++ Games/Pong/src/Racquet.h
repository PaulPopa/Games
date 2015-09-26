#pragma once

#include "App.h"

class Racquet
{
public:

	Racquet();
	~Racquet();

	void					Draw();
	void					Update(float dtime);

	float					GetWidth();
	float					GetHeight();

	Vector2f				GetPosition();
	sf::FloatRect			GetBounds();


private:

	sf::RectangleShape		shape;


	Vector2f				m_position;
	Vector2f				m_velocity;

	float					m_rectWidth;
	float					m_rectHeight;

	bool					mouse;
};

