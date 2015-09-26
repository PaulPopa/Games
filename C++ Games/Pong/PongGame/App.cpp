#include "App.h"

App* g_app = new App();

App::App()
{
}


App::~App()
{
}

void App::Init()
{
	APP_WIDTH = 600;
	APP_HEIGHT = 400;
	window.create(sf::VideoMode(APP_WIDTH, APP_HEIGHT), "My Game");
}