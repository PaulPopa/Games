#include <SFML\Graphics.hpp>
#include "App.h"
#include "Ball.h"
#include "Input.h"

int main()
{
	g_app->Init();
	Racquet racquet;
	Ball ball(&racquet);

	sf::Clock clock;

	while (g_app->window.isOpen())
	{
		sf::Event event;
		while (g_app->window.pollEvent(event))
		{
			g_input->HandleEvent(event);
		}

		sf::Time elapsed = clock.restart();

		ball.Update(elapsed.asSeconds());
		racquet.Update(elapsed.asSeconds());

		g_app->window.clear(sf::Color(220, 220, 220));

		ball.Draw();
		racquet.Draw();

		g_app->window.display();
	}

	return 0;
}