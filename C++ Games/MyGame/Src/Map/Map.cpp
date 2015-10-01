#include "Map.h"
#include "App.h"
#include "Helpers.h"

Vector2f Map::m_mapZero;

Map* g_map;
std::map<std::string, std::pair<int, int> > Map::m_mapIntervals;
std::map<std::string, sf::Sprite> Map::m_squaresSprites;
std::map<std::string, sf::Texture> Map::m_squaresTextures;

Map::Map() :
m_lastPosition(100, 100)
{
	g_map = this;
}

Map::~Map()
{
}

void Map::Create()
{
	TiXmlDocument doc;

	std::string file;
	file.append(XML_FOLDER);
	file.append("Map.xml");

	auto ret = doc.LoadFile(file.c_str());

	TiXmlElement* entry = doc.FirstChildElement();

	for (auto element = entry->FirstChildElement(); element; element = element->NextSiblingElement())
	{
		ParseElement(element);
	}

	InitializeTilesAndDrawingSquares();
}

void Map::InitializeTilesAndDrawingSquares()
{
	m_tiles = std::vector<std::vector<Tile> >(m_rows, std::vector<Tile>(m_columns, Tile()));
	m_drawingSquares = std::vector<std::vector<std::string> >(m_rows - 1, std::vector<std::string>(m_columns - 1, std::string()));
	auto matrixMap = m_generator.Generate(m_rows, m_columns, std::make_pair(-10, 10), 3);

	for (uint i = 0; i < m_rows; ++i)
	{
		for (uint j = 0; j < m_columns; ++j)
		{
			Tile* tile = &m_tiles[i][j];
			tile->SetHeight(matrixMap[i][j]);
			tile->SetPosition(i, j);
			tile->SetType(GetType(tile->GetHeight()));
			tile->SetSize(Vector2f(m_squaresSprites["dddd"].getGlobalBounds().width, m_squaresSprites["dddd"].getGlobalBounds().height));
			if (tile->GetHeight() < 0) tile->SetWalkable(false);
			else tile->SetWalkable(true);
		}
	}

	for (uint i = 0; i < m_rows - 1; ++i)
	{
		for (uint j = 0; j < m_columns - 1; ++j)
		{
			std::string type("abcd");
			type[0] = m_tiles[i][j].GetType().at(0);
			type[1] = m_tiles[i][j + 1].GetType().at(0);
			type[2] = m_tiles[i + 1][j + 1].GetType().at(0);
			type[3] = m_tiles[i + 1][j].GetType().at(0);
			m_drawingSquares[i][j] = type;
		}
	}
}

void Map::ParseElement(const TiXmlElement* element)
{
	if (IsEqual(element->Value(), "Squares"))
	{
		for (auto a = element->FirstAttribute(); a; a = a->Next())
		{
			sf::Texture newTexture;
			std::string file;
			file.append(TEXTURES_FOLDER);
			file.append(a->Value());
			newTexture.loadFromFile(file);
			m_squaresTextures[a->Name()] = newTexture;

			sf::Sprite newSprite;
			newSprite.setTexture(m_squaresTextures[a->Name()]);
			m_squaresSprites[a->Name()] = newSprite;
		}
	}
	else if (IsEqual(element->Value(), "Intervals"))
	{
		for (auto a = element->FirstAttribute(); a; a = a->Next())
		{
			Vector2f v = ParseVector2f(a->Value());
			m_mapIntervals[a->Name()] = std::make_pair((int)v.x, (int)v.y);
		}
	}
	else if (IsEqual(element->Value(), "Size"))
	{
		m_rows = element->FirstAttribute()->UnsignedValue();
		m_columns = element->FirstAttribute()->Next()->UnsignedValue();
	}
	else if (IsEqual(element->Value(), "TileSize"))
	{
		Tile::m_tileSize = ParseVector2f(element->FirstAttribute()->Value());
		m_mapZero = -Tile::m_tileSize / 2.f;
		m_object->SetPos(m_mapZero);
	}

}

std::string Map::GetType(int height)
{
	for (auto& a : m_mapIntervals)
	{
		if (height > a.second.first && height <= a.second.second)
		{
			return a.first;
		}
	}
	return "";
}

Tile Map::GetTile(uint i, uint j)
{
	return m_tiles[i][j];
}

uint Map::GetRows()
{
	return m_rows;
}

uint Map::GetColumns()
{
	return m_columns;
}

void Map::Draw()
{
	if (m_lastPosition.x != m_object->GetPos().x)
	{
		m_inScreenFirstColumn = Max((int)(abs(m_object->GetPos().x) / Tile::m_tileSize.x - 1), 0);
		m_inScreenLastColumn = Min((uint)(m_inScreenFirstColumn + g_app->APP_RESOLUTION_WIDTH / Tile::m_tileSize.x + 3), m_drawingSquares[0].size());
	}

	if (m_lastPosition.y != m_object->GetPos().y)
	{
		m_inScreenFirstRow = Max((int)(abs(m_object->GetPos().y) / Tile::m_tileSize.y - 1), 0);
		m_inScreenLastRow = Min((uint)(m_inScreenFirstRow + g_app->APP_RESOLUTION_HEIGHT / Tile::m_tileSize.y + 3), m_drawingSquares.size());
	}

	m_lastPosition = m_object->GetPos();


	for (uint i = m_inScreenFirstRow; i < m_inScreenLastRow; ++i)
	{
		for (uint j = m_inScreenFirstColumn; j < m_inScreenLastColumn; ++j)
		{
			DrawSquare(i, j);
		}
	}
}

void Map::DrawSquare(uint i, uint j)
{
	g_app->m_window.draw(m_squaresSprites[m_drawingSquares[i][j]], m_object->GetTransform() * m_tiles[i][j].GetDrawingSquareTransform());
}

void Map::SetObject(ObjectRef object)
{
	m_object = object;
}