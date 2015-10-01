#include "Tile.h"
#include "App.h"

Vector2f Tile::m_tileSize;

Tile::Tile() :
m_walkable(false)
{
}

Tile::~Tile()
{
}

void Tile::SetPosition(uint row, uint column)
{
	m_row = row;
	m_column = column;
	m_position = Vector2f(column * m_tileSize.x, row * m_tileSize.y);
	m_transformable.setPosition(m_position + m_tileSize / 2.f);
}

void Tile::SetType(const std::string& type)
{
	m_type = type;
}

void Tile::SetHeight(uint height)
{
	m_height = height;
}

void Tile::SetSize(Vector2f originalSize)
{
	m_transformable.setScale(m_tileSize.x / originalSize.x, m_tileSize.y / originalSize.y);
}

void Tile::SetWalkable(bool walkable)
{
	m_walkable = walkable;
}

int Tile::GetHeight()
{
	return m_height;
}

std::string Tile::GetType()
{
	return m_type;
}

sf::Transform Tile::GetDrawingSquareTransform()
{
	return m_transformable.getTransform();
}

Vector2f Tile::GetPosition()
{
	return m_position;
}

bool Tile::IsWalkable()
{
	return m_walkable;
}