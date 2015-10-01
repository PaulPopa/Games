#pragma once
#include "stdincl.h"

class Profile
{
public:
	Profile();
	Profile(const std::string name, uint mapRow, uint mapColumn, uint generationSeed);
	~Profile();

	void			Register(const std::string filename);
	void			UpdateExisting(TiXmlElement* element);

	std::string		GetName();
	uint			GetMapRow();
	uint			GetMapColumn();
	uint			GetGenerationSeed();

private:

	std::string		m_name;

	uint			m_mapRow;
	uint			m_mapColumn;

	uint			m_generationSeed;
};
