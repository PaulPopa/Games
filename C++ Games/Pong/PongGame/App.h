#pragma once
#include <SFML\Graphics.hpp>
#include "Input.h"

typedef sf::Vector2f Vector2f;
class App
{
public:
	App();
	~App();

	float				APP_WIDTH;
	float				APP_HEIGHT;

	sf::RenderWindow	window;
	Input				m_input;

	void				Init();
};

extern App* g_app;

