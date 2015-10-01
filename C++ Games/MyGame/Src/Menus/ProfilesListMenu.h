#pragma once

#include "Component.h"
#include "Profile.h"
#include "stdincl.h"

#define NO_BUTTON 100

class ProfilesListMenu : public Component
{
	REGISTER(ProfilesListMenu);

public:

	ProfilesListMenu(void);
	~ProfilesListMenu(void);

	virtual void								OnAddToObject() override;
	virtual void								OnStart() override;
	virtual void								OnActivate() override;
	virtual void								Update(float dtime) override;

	void										ReloadList();
	void										CheckList();
	void										CheckProfileChanging();
	void										ClearList();

private:

	virtual void								ParseAttribute(const TiXmlAttribute* attribute);

	ObjectRef									m_changeProfileButtonHolder;

	std::vector<ObjectRef>						m_profilesBoxes;
	std::vector<Profile>						m_profiles;


	Vector2f									m_startingPosition;
	Vector2f									m_boxSize;

	uint										m_pressedIndex;

};

