#include "ProfilesManager.h"
#include "Map.h"
#include "Helpers.h"
#include "MenuHandler.h"
#include "TextComponent.h"
#include "ProfilesListMenu.h"


ProfilesManager* g_profilesManager;

ProfilesManager::ProfilesManager()
{
	g_profilesManager = this;
}

ProfilesManager::~ProfilesManager()
{
}

void ProfilesManager::CreateProfile(const std::string& name)
{
	uint row, column;
	bool found = false;
	for (uint i = 1; i < g_map->GetRows(); ++i)
	{
		for (uint j = 1; j < g_map->GetColumns(); ++j)
		{
			if (g_map->GetTile(i, j).IsWalkable())
			{
				found = true;
				row = i;
				column = j;
			}

			if (found) break;
		}
		if (found) break;
	}

	Profile p(name, row, column, (uint)time(NULL));
	SetCurrentProfile(p);


}

bool ProfilesManager::ProfileAvailable(const std::string& name)
{
	TiXmlDocument doc;
	std::string file;
	file.append(XML_FOLDER);
	file.append("Profiles.xml");
	doc.LoadFile(file.c_str());

	auto entry = doc.FirstChildElement();

	for (auto element = entry->FirstChildElement(); element; element = element->NextSiblingElement())
	{
		if (IsEqual(element->Value(), name.c_str()))
		{
			return false;
		}
	}

	return true;
}

void ProfilesManager::UnloadCurrentProfile()
{
	m_currentProfile.Register("Profiles.xml");
}

Profile* ProfilesManager::GetCurrentProfile()
{
	return &m_currentProfile;
}

void ProfilesManager::SetCurrentProfile(const Profile& profile)
{
	m_currentProfile = profile;

	auto profileHolder = g_menuHandler->GetMenuObject(MAIN_MENU)->FindChild("CurrentProfile");
	assert(profileHolder);

	auto textComp = profileHolder->GetComponent<TextComponent>();
	assert(textComp);

	textComp->SetText(m_currentProfile.GetName());
}

void ProfilesManager::GetProfiles(std::vector<Profile>& profiles)
{
	TiXmlDocument doc;
	std::string file;
	file.append(XML_FOLDER);
	file.append("Profiles.xml");
	doc.LoadFile(file.c_str());

	auto entry = doc.FirstChildElement();

	for (auto element = entry->FirstChildElement(); element; element = element->NextSiblingElement())
	{
		uint map_row = 0, map_column = 0, seed = 0;
		for (auto attribute = element->FirstAttribute(); attribute; attribute = attribute->Next())
		{
			if (IsEqual(attribute->Name(), "map_row"))
			{
				map_row = attribute->UnsignedValue();
			}
			else if (IsEqual(attribute->Name(), "map_column"))
			{
				map_row = attribute->UnsignedValue();
			}
			else if (IsEqual(attribute->Name(), "seed"))
			{
				map_row = attribute->UnsignedValue();
			}
		}
		profiles.push_back(Profile(element->Value(), map_row, map_column, seed));
	}
}