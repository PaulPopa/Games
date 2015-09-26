#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

enum keys{ KeyLeft, KeyRight, KeyNum };

class Input
{
public:

	Input();
	~Input();

	void					HandleEvent(sf::Event event);
	void					Update(float dtime);
	bool					IsPressed(unsigned key);

	float					GetMouseX();
	float					GetMouseY();


private:
	std::vector<bool>		keyPressed;
	
	float					mouseX;
	float					mouseY;

};

extern Input* g_input;

