#include "MainMenu.h"
#include "App.h"
#include "stdincl.h"
#include "ButtonComponent.h"

REGISTERIMPL(MainMenu);

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Update(float dtime)
{
}

void MainMenu::PostUpdate(float dtime)
{
}

void MainMenu::ChangeProfile(const std::string& name)
{
	auto profileHolder = m_object->FindChild("CurrentProfile");
	assert(profileHolder);

	auto textComp = profileHolder->GetComponent<TextComponent>();
	assert(textComp);

	textComp->SetText(name);
}
