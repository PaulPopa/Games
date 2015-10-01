#pragma once

#include "stdincl.h"

enum KEYS { MOUSE_LEFT, KEY_SHIFT, KEY_A, KEY_D, KEY_W, KEY_S, KEY_Q, KEY_P, KEY_CONSOLE, KEY_RETURN, KEY_BACKSPACE, KEY_TAB, KEY_NUM };

class Input 
{

public:
	Input(void);
	~Input(void);

	void						HandleEvent(sf::Event event);
	bool						WasPressedThisTurn(uint key);
	bool						WasReleasedThisTurn(uint key);
	bool						IsPressed(uint key);
	bool						WasKeyPressed();

	uint						KeyPressed();

	void						Update();
	void						UpdateCurrentState();
	void						Reset();
	Vector2f					GetMousePosition();

private:

	bool						m_lastState[KEY_NUM];
	bool						m_currentState[KEY_NUM];

	bool						m_wasKeyPressed;

	sf::Mouse					m_mouse;
	uint						m_keyPressedThisTurn;

};

extern Input* g_input;
