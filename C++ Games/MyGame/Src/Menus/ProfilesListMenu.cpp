#include "ProfilesListMenu.h"
#include "App.h"
#include "stdincl.h"
#include "Helpers.h"
#include "ProfilesManager.h"
#include "ButtonComponent.h"

REGISTERIMPL(ProfilesListMenu);

ProfilesListMenu::ProfilesListMenu() :
m_pressedIndex(NO_BUTTON)
{
}

ProfilesListMenu::~ProfilesListMenu()
{
}

void ProfilesListMenu::OnAddToObject()
{
	m_startingPosition = Vector2f(600, 250);
	ReloadList();
}

void ProfilesListMenu::OnStart()
{
	m_changeProfileButtonHolder = m_object->FindChild("SelectProfile");
}

void ProfilesListMenu::OnActivate()
{
	ClearList();
	ReloadList();
}

void ProfilesListMenu::Update(float dtime)
{
	CheckList();
	CheckProfileChanging();
}

void ProfilesListMenu::ReloadList()
{
	g_profilesManager->GetProfiles(m_profiles);

	for (uint i = 0; i < m_profiles.size(); ++i)
	{
		std::string file;
		file.append(XML_FOLDER);
		file.append("ProfileButton.xml");
		auto profileObj = Object::CreateFromFile(file);
		auto buttonComp = profileObj->GetComponent<ButtonComponent>();

		buttonComp->SetText(m_profiles[i].GetName());

		profileObj->SetPos(m_startingPosition + Vector2f(0.f, buttonComp->GetSize().y * 2 * i));
		m_profilesBoxes.push_back(profileObj.get());
		m_object->AddChild(std::move(profileObj));
	}
}

void ProfilesListMenu::CheckList()
{
	for (uint i = 0; i < m_profilesBoxes.size(); ++i)
	{
		auto buttonComp = m_profilesBoxes[i]->GetComponent<ButtonComponent>();
		assert(buttonComp);

		if (buttonComp->WasPressed())
		{
			buttonComp->SetPressed(false);

			if (m_pressedIndex == i)
			{
				m_pressedIndex = NO_BUTTON;
			}
			else
			{
				if (m_pressedIndex != NO_BUTTON)
				{
					auto lastButtonComp = m_profilesBoxes[m_pressedIndex]->GetComponent<ButtonComponent>();
					assert(lastButtonComp);

					lastButtonComp->UnDeepen();
				}

				m_pressedIndex = i;
			}
		}
	}
}

void ProfilesListMenu::CheckProfileChanging()
{
	if (m_pressedIndex != NO_BUTTON)
	{
		if (!m_changeProfileButtonHolder->IsEnabled())
		{
			m_changeProfileButtonHolder->Enable();
		}
		auto buttonComp = m_changeProfileButtonHolder->GetComponent<ButtonComponent>();
		assert(buttonComp);

		if (buttonComp->WasPressed())
		{
			g_profilesManager->SetCurrentProfile(m_profiles[m_pressedIndex]);
			g_menuHandler->SwitchMenu(MAIN_MENU);

		}
	}
	else
	{
		if (m_changeProfileButtonHolder->IsEnabled())
		{
			m_changeProfileButtonHolder->Disable();
		}
	}
}

void ProfilesListMenu::ClearList()
{
	for (uint i = 0; i < m_profilesBoxes.size(); ++i)
	{
		m_profilesBoxes[i]->Trash();
	}
	m_profiles.clear();
	m_profilesBoxes.clear();
	m_pressedIndex = NO_BUTTON;
}

void ProfilesListMenu::ParseAttribute(const TiXmlAttribute* attribute)
{
}