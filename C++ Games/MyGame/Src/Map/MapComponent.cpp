#include "MapComponent.h"
#include "App.h"

REGISTERIMPL(MapComponent);

MapComponent::MapComponent()
{
}

MapComponent::~MapComponent()
{
}

void MapComponent::OnAddToObject()
{
	g_map->SetObject(m_object);
	g_map->Create();
}

void MapComponent::Update(float dtime)
{
	if (g_input->IsPressed(KEY_D))
	{
		m_object->SetPos(m_object->GetPos() + Vector2f(-10, 0));
		if (m_object->GetPos().x < Map::m_mapZero.x  - ((g_map->GetColumns() - 1) * Tile::m_tileSize.x - g_app->APP_RESOLUTION_WIDTH))
		{
			m_object->SetPos(Vector2f(Map::m_mapZero.x  - ((g_map->GetColumns() - 1) * Tile::m_tileSize.x - g_app->APP_RESOLUTION_WIDTH), m_object->GetPos().y));
		}
	}
	else if (g_input->IsPressed(KEY_A))
	{
		m_object->SetPos(m_object->GetPos() + Vector2f(10, 0));
		if (m_object->GetPos().x > Map::m_mapZero.x)
		{
			m_object->SetPos(Vector2f(Map::m_mapZero.x, m_object->GetPos().y));
		}
	}
	else if (g_input->IsPressed(KEY_S))
	{
		m_object->SetPos(m_object->GetPos() + Vector2f(0, -10));
		if (m_object->GetPos().y < Map::m_mapZero.y - ((g_map->GetRows() - 1) * Tile::m_tileSize.y - g_app->APP_RESOLUTION_HEIGHT))
		{
			m_object->SetPos(Vector2f(m_object->GetPos().x, Map::m_mapZero.y - ((g_map->GetRows() - 1) * Tile::m_tileSize.y - g_app->APP_RESOLUTION_HEIGHT)));
		}
	}
	else if (g_input->IsPressed(KEY_W))
	{
		m_object->SetPos(m_object->GetPos() + Vector2f(0, 10));
		if (m_object->GetPos().y > Map::m_mapZero.y)
		{
			m_object->SetPos(Vector2f(m_object->GetPos().x, Map::m_mapZero.y));
		}
	}
}

void MapComponent::Draw()
{
	g_map->Draw();
}