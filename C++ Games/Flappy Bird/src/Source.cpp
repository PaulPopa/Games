#include <SFML/Graphics.hpp>
#include <iostream>
#include "App.h"  
#include "Bird.h"
#include "Obstacles.h"


int main()
{
	g_app->Init();

	Obstacles obstacles;
	Bird bird(&obstacles);

	sf::Clock clock;


	while (g_app->window.isOpen())
	{
	
		sf::Event event;
		while (g_app->window.pollEvent(event))
		{
			g_input->HandleEvent(event);
		}
		

		sf::Time elapsed = clock.restart();

		g_app->window.clear(sf::Color(95, 158, 160));

		bird.Update(elapsed.asSeconds());

		if (!bird.GameOver())
		{
			obstacles.Update(elapsed.asSeconds());
		}

		bird.Draw();
		obstacles.Draw();
		g_input->Reset();

		g_app->window.display();
	}

	return 0;
}