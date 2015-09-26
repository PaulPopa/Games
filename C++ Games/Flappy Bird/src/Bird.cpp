#include "Bird.h"
#include "App.h"
#include "Obstacle.h"
#include <iostream>
#include <string>

Bird::Bird(Obstacles* obs)
{
	m_birdWidth = 15;
	m_birdHeight = 15;

	grassWidth = 50;

	gameOver = false;

	highScore = 0;

	m_obs = obs;

	m_position = Vector2f(40, 40);
	m_velocity = Vector2f(85, 85);

	bird.setSize(Vector2f(m_birdWidth, m_birdHeight));
	bird.setPosition(m_position);
	bird.setFillColor(sf::Color(159, 28, 29)); 
	bird.setOutlineThickness(2);
	bird.setOutlineColor(sf::Color(51, 0, 0));

	grass.setSize(Vector2f(g_app->APP_WIDTH, grassWidth));
	grass.setPosition(Vector2f(0, g_app->APP_HEIGHT - grassWidth));
	grass.setFillColor(sf::Color(102, 51, 0));
	grass.setOutlineThickness(3);
	grass.setOutlineColor(sf::Color(51, 25, 0));

	font.loadFromFile("arial.ttf");

	scoreText.setFont(font);
	scoreText.setCharacterSize(25U);
	scoreText.setColor(sf::Color::Black);
	scoreText.setString(std::to_string(highScore));
}

Bird::~Bird()
{
}

void Bird::Update(float dtime)
{
	if (!gameOver)
	{
		if (g_input->IsPressed(KeySpace))
		{
			m_velocity.y = -200;
		}
	}

	m_velocity.y += 300 * dtime;
	m_position.y += m_velocity.y * dtime;

	bird.setPosition(m_position);

	//If bird has reached the sky
	if (m_position.y < 0)
	{
		m_position.y = 0;
		gameOver = true;
	}

	//If bird's on grass
	if (m_position.y >=  g_app->APP_HEIGHT - grassWidth - m_birdWidth - 5)
	{
		m_position.y = g_app->APP_HEIGHT - grassWidth - m_birdWidth - 5;
		m_velocity.y = 0;
		gameOver = true;
	}

	//Intersection
	if (m_obs->m_obstacles[0].upperObstacle.getGlobalBounds().intersects(bird.getGlobalBounds()) ||
		m_obs->m_obstacles[0].lowerObstacle.getGlobalBounds().intersects(bird.getGlobalBounds()))
	{
		gameOver = true;
	}
	
	if (m_obs->m_obstacles[0].m_positionUp.x < m_position.x && !m_obs->m_obstacles[0].pointed)
	{
		m_obs->m_obstacles[0].pointed = true;
		highScore++;
		scoreText.setString(std::to_string(highScore));
		
		if (highScore % 3 == 0)
		{
			Obstacle::obstacleFree -= 15;
			m_birdWidth -= 1;
			m_birdHeight -= 1;
			bird.setSize(Vector2f(m_birdWidth, m_birdHeight)); 
		}
	}
}

void Bird::Draw()
{
	g_app->window.draw(bird);
	g_app->window.draw(grass);
	g_app->window.draw(scoreText);
}

bool Bird::PassedObstacle()
{
	if (m_position.x == m_obs->m_obstacles[0].m_positionUp.x)
	{
		return true;
	}
	return false;
}

bool Bird::GameOver()
{
	return gameOver;
}