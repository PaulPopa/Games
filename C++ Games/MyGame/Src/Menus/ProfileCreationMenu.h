#pragma once

#include "Component.h"
#include "stdincl.h"

class ProfileCreationMenu : public Component
{
	REGISTER(ProfileCreationMenu);

public:

	ProfileCreationMenu(void);
	~ProfileCreationMenu(void);

	virtual void								OnAddToObject();
	virtual void								Update(float dtime) override;

	bool										CreatePressed();
	bool										CancelPressed();

	void										RegisterMessage(const std::string& messageName, const std::string& messageValue);


private:

	virtual void								ParseAttribute(const TiXmlAttribute* attribute);

	ObjectRef									m_infoHolder;
	std::map<std::string, std::string>			m_messagesMap;
};

