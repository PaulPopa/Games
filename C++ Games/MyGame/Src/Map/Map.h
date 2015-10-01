#pragma once

#include "stdincl.h"
#include "Tile.h"
#include "MapGenerator.h"
#include "Object.h"

class Map
{

public:

	Map();
	~Map();

	void													Create();
	void													ParseElement(const TiXmlElement* element);
	void													InitializeTilesAndDrawingSquares();
	void													Draw();
	void													DrawSquare(uint i, uint j);
	void													SetObject(ObjectRef object);

	std::string												GetType(int height);
	
	Tile													GetTile(uint i, uint j);

	uint													GetRows();
	uint													GetColumns();

	static Vector2f											m_mapZero;
	

private:

	static std::map<std::string, sf::Texture>				m_squaresTextures;
	static std::map<std::string, sf::Sprite>				m_squaresSprites;
	static std::map<std::string, std::pair<int, int> >		m_mapIntervals;
	
	std::vector<std::vector<Tile> >							m_tiles;
	std::vector<std::vector<std::string> >					m_drawingSquares;

	uint													m_rows;
	uint													m_columns;

	MapGenerator											m_generator;

	ObjectRef												m_object;

	Vector2f												m_lastPosition;

	uint													m_inScreenFirstColumn;
	uint													m_inScreenLastColumn;
	uint													m_inScreenFirstRow;
	uint													m_inScreenLastRow;

};

extern Map* g_map;