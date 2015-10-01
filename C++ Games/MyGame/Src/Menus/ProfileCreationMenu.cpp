#include "ProfileCreationMenu.h"
#include "App.h"
#include "stdincl.h"
#include "CheckboxComponent.h"
#include "ButtonComponent.h"
#include "EditableTextBox.h"
#include "Helpers.h"

REGISTERIMPL(ProfileCreationMenu);

ProfileCreationMenu::ProfileCreationMenu()
{
}

ProfileCreationMenu::~ProfileCreationMenu()
{
}

void ProfileCreationMenu::OnAddToObject()
{
	m_infoHolder = m_object->FindChild("InfoText");
	assert(m_infoHolder);
}

void ProfileCreationMenu::Update(float dtime)
{
	if (CreatePressed())
	{
		auto boxObj = m_object->FindChild("ProfileTextBox");
		assert(boxObj);

		auto boxComp = boxObj->GetComponent<EditableTextBox>();
		assert(boxComp);

		if (IsEqual(boxComp->GetText().c_str(), ""))
		{
			auto infoText = m_infoHolder->GetComponent<TextComponent>();
			assert(infoText);

			infoText->SetText(m_messagesMap["message_no_characters"]);
		}
		else if (g_profilesManager->ProfileAvailable(boxComp->GetText()))
		{
			g_profilesManager->CreateProfile(boxComp->GetText());
			g_profilesManager->UnloadCurrentProfile();
			boxComp->ClearText();
			g_menuHandler->SwitchMenu(MAIN_MENU);
		}
		else
		{
			auto infoText = m_infoHolder->GetComponent<TextComponent>();
			assert(infoText);

			infoText->SetText(m_messagesMap["message_unavailable_profile"]);
		}
	}
	else if (CancelPressed())
	{
		auto boxObj = m_object->FindChild("ProfileTextBox");
		assert(boxObj);

		auto boxComp = boxObj->GetComponent<EditableTextBox>();
		assert(boxComp);

		boxComp->ClearText();
		g_menuHandler->SwitchMenu(MAIN_MENU);
	}
}

bool ProfileCreationMenu::CreatePressed()
{
	auto createButtonObj = m_object->FindChild("CreateButton");
	assert(createButtonObj);

	auto buttonComp = createButtonObj->GetComponent<ButtonComponent>();
	assert(buttonComp);

	return buttonComp->WasPressed();
}

bool ProfileCreationMenu::CancelPressed()
{
	auto cancelButtonObj = m_object->FindChild("CancelButton");
	assert(cancelButtonObj);

	auto buttonComp = cancelButtonObj->GetComponent<ButtonComponent>();
	assert(buttonComp);

	return buttonComp->WasPressed();
}

void ProfileCreationMenu::RegisterMessage(const std::string& messageName, const std::string& messageValue)
{
	m_messagesMap.insert(std::make_pair(messageName, messageValue));
}

void ProfileCreationMenu::ParseAttribute(const TiXmlAttribute* attribute)
{
	if (StringStartsWith("message", attribute->Name()))
	{
		RegisterMessage(attribute->Name(), attribute->Value());
	}
}