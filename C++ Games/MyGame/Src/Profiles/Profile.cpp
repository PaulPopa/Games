#include "Profile.h"
#include "Helpers.h"

Profile::Profile()
{
}

Profile::Profile(const std::string name, uint mapRow, uint mapColumn, uint generationSeed)
{
	m_name = name;
	m_mapRow = mapRow;
	m_mapColumn = mapColumn;
	m_generationSeed = generationSeed;
}

Profile::~Profile()
{
}

void Profile::Register(const std::string filename)
{
	TiXmlDocument doc;
	std::string file;
	file.append(XML_FOLDER);
	file.append(filename);
	doc.LoadFile(file.c_str());

	auto entry = doc.FirstChildElement();

	for (auto element = entry->FirstChildElement(); element; element = element->NextSiblingElement())
	{
		if (IsEqual(element->Value(), m_name.c_str()))
		{
			UpdateExisting(element);
			return;
		}
	}

	TiXmlElement* newProfile = new TiXmlElement(m_name.c_str());

	newProfile->SetAttribute("map_row", std::to_string(m_mapRow).c_str());
	newProfile->SetAttribute("map_column", std::to_string(m_mapColumn).c_str());
	newProfile->SetAttribute("seed", std::to_string(m_generationSeed).c_str());

	entry->InsertEndChild(*newProfile);

	doc.SaveFile();
}

void Profile::UpdateExisting(TiXmlElement* element)
{
	element->SetAttribute("map_row", std::to_string(m_mapRow).c_str());
	element->SetAttribute("map_column", std::to_string(m_mapColumn).c_str());
	element->SetAttribute("seed", std::to_string(m_generationSeed).c_str());
}

std::string Profile::GetName()
{
	return m_name;
}

uint Profile::GetMapRow()
{
	return m_mapRow;
}

uint Profile::GetMapColumn()
{
	return m_mapColumn;
}

uint Profile::GetGenerationSeed()
{
	return m_generationSeed;
}