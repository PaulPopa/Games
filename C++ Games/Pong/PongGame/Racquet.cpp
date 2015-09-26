#include "Racquet.h"
#include "App.h"

Racquet::Racquet()
{
	m_rectWidth = 100;
	m_rectHeight = 10;

	mouse = false;

	m_position = Vector2f(100, g_app->APP_HEIGHT - 50);
	m_velocity = Vector2f(176, 150);

	shape.setFillColor(sf::Color::Black);
	shape.setSize(Vector2f(m_rectWidth, m_rectHeight));
	shape.setPosition(m_position);
}


Racquet::~Racquet()
{
}

void Racquet::Update(float dtime)
{
	
	if (!mouse)
	{
		if (g_input->IsPressed(KeyLeft))
		{
			m_position.x -= m_velocity.x * dtime;
		}

		if (g_input->IsPressed(KeyRight))
		{
			m_position.x += m_velocity.x * dtime;
		}

		if (m_position.x <= 0)
		{
			m_position.x = 0;
		}

		if (m_position.x >= g_app->APP_WIDTH - m_rectWidth)
		{
			m_position.x = g_app->APP_WIDTH - m_rectWidth;
		}
	}

	else
	{
		m_position.x = g_input->GetMouseX();
	}

	shape.setPosition(m_position);
}

void Racquet::Draw()
{
	g_app->window.draw(shape);
}

Vector2f Racquet::GetPosition()
{
	return m_position;
}

sf::FloatRect Racquet::GetBounds()
{
	return shape.getGlobalBounds();
}

float Racquet::GetWidth()
{
	return m_rectWidth;
}

float Racquet::GetHeight()
{
	return m_rectHeight;
}