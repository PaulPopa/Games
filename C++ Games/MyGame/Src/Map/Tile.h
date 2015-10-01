#pragma once

#include "stdincl.h"

class Tile 
{

public:

	Tile();
	~Tile();

	void				SetPosition(uint row, uint column);
	void				SetHeight(uint height);
	void				SetType(const std::string& type);
	void				SetSize(Vector2f originalSize);
	void				SetWalkable(bool walkable);

	int					GetHeight();
	std::string			GetType();
	sf::Transform		GetDrawingSquareTransform();
	Vector2f			GetPosition();

	bool				IsWalkable();

	static Vector2f		m_tileSize;

private:

	int					m_height;
	std::string			m_type;
	sf::Transformable	m_transformable;

	uint				m_row;
	uint				m_column;

	Vector2f			m_position;

	bool				m_walkable;
};