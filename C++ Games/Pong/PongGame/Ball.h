#pragma once
#include "App.h"
#include "Racquet.h"

typedef sf::Vector2f Vector2f;

class Ball
{
public:

	Ball(Racquet* racquet);
	~Ball();

	void						Draw();
	void						Update(float dtime);

private:

	sf::CircleShape				shape;

	float						m_radius;

	Vector2f					m_velocity;
	Vector2f					m_position;

	Racquet*					m_racquet;

};

