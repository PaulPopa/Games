#include "Ball.h"
typedef sf::Vector2f Vector2f;

Ball::Ball(Racquet* racquet)
{
	m_radius = 7.5f;

	m_velocity = Vector2f(175, 150);
	m_position = Vector2f(100, 100);

	m_racquet = racquet;

	shape.setFillColor(sf::Color(139, 0, 0));
	shape.setRadius(m_radius);
	shape.setPosition(Vector2f(m_position.x, m_position.y));
}


Ball::~Ball()
{
}

void Ball::Draw()
{
	g_app->window.draw(shape);
}

void Ball::Update(float dtime)
{
	m_position += m_velocity * dtime;

	if (m_position.x <= 0)
	{
		m_position.x = 1;
		m_velocity.x *= -1;
	}

	if (m_position.x >= g_app->APP_WIDTH - m_radius)
	{
		m_position.x = g_app->APP_WIDTH - m_radius - 1;
		m_velocity.x *= -1;
	}

	if (m_position.y <= 0)
	{
		m_position.y = 1;
		m_velocity.y *= -1;
	}

	if (m_position.y >= g_app->APP_HEIGHT - m_radius)
	{
		m_position.y = g_app->APP_HEIGHT - m_radius - 1;
		m_velocity.y *= -1;
	}

	if (this->shape.getGlobalBounds().intersects(m_racquet->GetBounds()))
	{
		m_position.y = g_app->APP_HEIGHT - 65;
		m_velocity.y *= -1;

		float percentage = ((m_position.x + m_radius) - (m_racquet->GetPosition().x + m_racquet->GetWidth() / 2.f)) / (m_racquet->GetWidth() / 2.f);
		m_velocity.x = percentage * 200;
	}

	shape.setPosition(Vector2f(m_position.x, m_position.y));
}
