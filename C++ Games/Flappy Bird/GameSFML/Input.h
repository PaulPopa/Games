#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

enum keys{ KeyLeft, KeyRight, KeySpace, KeyNum };

class Input
{
public:

	Input();
	~Input();

	void					HandleEvent(sf::Event event);
	void					Update(float dtime);
	void					Reset();

	bool					IsPressed(unsigned key);


private:
	std::vector<bool>		keyPressed;

};

extern Input* g_input;

