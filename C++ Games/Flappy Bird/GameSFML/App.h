#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"

typedef sf::Vector2f Vector2f;

class App
{
public:

	App();
	~App();

	void				Init();
	sf::RenderWindow	window;

	float				APP_WIDTH;
	float				APP_HEIGHT;
	
private:

	Input				m_input;
};

extern App* g_app;
