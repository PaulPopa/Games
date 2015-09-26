#include "Input.h"
#include "App.h"

Input* g_input;

Input::Input()
{
	keyPressed = std::vector<bool>(KeyNum, false);
	g_input = this;
}


Input::~Input()
{
}

void Input::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
	{
		g_app->window.close();
	}

	else if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			keyPressed[KeyLeft] = true;
		}

		else if (event.key.code == sf::Keyboard::Right)
		{
			keyPressed[KeyRight] = true;
		}
	}

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			keyPressed[KeyLeft] = false;
		}

		else if (event.key.code == sf::Keyboard::Right)
		{
			keyPressed[KeyRight] = false;
		}
	}

	else if (event.type == sf::Event::MouseMoved)
	{
		mouseX = event.mouseMove.x;
		mouseY = event.mouseMove.y;
	}
}

void Input::Update(float dtime)
{
}

bool Input::IsPressed(unsigned key)
{
	return keyPressed[key];
}

float Input::GetMouseX()
{
	return mouseX;
}

float Input::GetMouseY()
{
	return mouseY;
}

