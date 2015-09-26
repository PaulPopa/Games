#pragma once
#include "App.h"
#include "Obstacle.h"
#include "Obstacles.h"

class Bird
{
public:

	Bird(Obstacles* obs);
	~Bird();

	void						Update(float dtime);
	void						Draw();

	float						grassWidth;
	bool						PassedObstacle();

	bool						GameOver();

private:

	sf::RectangleShape			bird;
	sf::RectangleShape			grass;

	float						m_birdWidth;
	float						m_birdHeight;

	Vector2f					m_position;
	Vector2f					m_velocity;

	Obstacles*					m_obs;

	bool						gameOver;

	unsigned					highScore;

	sf::Text					scoreText;
	sf::Font					font;
};

