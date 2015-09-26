#include "Input.h"
#include "App.h"

Input* g_input;

Input::Input()
{
	keyPressed = std::vector<bool> (KeyNum, false);
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

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			keyPressed[KeySpace] = true;
		}
	}
}

void Input::Update(float dtime)
{
}

void Input::Reset()
{
	for (unsigned i = 0; i < KeyNum; ++i)
	{
		keyPressed[i] = false;
	}
}

bool Input::IsPressed(unsigned key)
{
	return keyPressed[key];
}
