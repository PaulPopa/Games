#include "Input.h"
#include "App.h"
#include "stdincl.h"

Input* g_input;

Input::Input()
{
	for (int i = 0; i < KEY_NUM; ++i)
	{
		m_lastState[i] = false;
		m_currentState[i] = false;
	}

	g_input = this;
}

Input::~Input()
{
}

void Input::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
	{
		g_app->m_window.close();
	}
	if (event.type == sf::Event::KeyPressed)
	{
		m_wasKeyPressed = true;
		m_keyPressedThisTurn = event.key.code;
	}
}

bool Input::WasPressedThisTurn(uint key)
{
	if ( m_currentState[key] == true && m_lastState[key] == false)
	{
		return true;
	}
	return false;
}

bool Input::WasReleasedThisTurn(uint key)
{
	if (m_currentState[key] == false && m_lastState[key] == true)
	{
		return true;
	}
	return false;
}

bool Input::IsPressed(uint key)
{
	return m_currentState[key];
}

bool Input::WasKeyPressed()
{
	return m_wasKeyPressed;
}

uint Input::KeyPressed()
{
	if (WasKeyPressed())
	{
		return m_keyPressedThisTurn;
	}
	return 1000000;
}

void Input::Update()
{
	for (int i = 0; i < KEY_NUM; ++i)
	{
		m_lastState[i] = m_currentState[i];
		m_currentState[i] = false;
	}
	m_wasKeyPressed = false;
	UpdateCurrentState();

}

void Input::UpdateCurrentState()
{
	m_currentState[KEY_A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	m_currentState[KEY_D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_currentState[KEY_W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	m_currentState[KEY_S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	m_currentState[KEY_Q] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	m_currentState[KEY_P] = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
	m_currentState[KEY_CONSOLE] = sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde);
	m_currentState[KEY_RETURN] = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
	m_currentState[KEY_BACKSPACE] = sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace);
	m_currentState[KEY_TAB] = sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
	m_currentState[KEY_SHIFT] = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	m_currentState[KEY_SHIFT] = sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

	m_currentState[MOUSE_LEFT] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Input::Reset()
{
	for (int i = 0; i < KEY_NUM; ++i)
	{
		m_lastState[i] = false;
		m_currentState[i] = false;
	}
}

Vector2f Input::GetMousePosition()
{
	return (Vector2f)m_mouse.getPosition(g_app->m_window);
}


