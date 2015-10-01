#pragma once

#include "Component.h"
#include "stdincl.h"


class InputTextBoxComponent : public Component
{
	REGISTER(InputTextBoxComponent);

public:

	enum STATES { SELECTED, UNSELECTED, NUM_STATES };

	InputTextBoxComponent(void);
	~InputTextBoxComponent(void);

	virtual void					OnAddToObject() override;
	virtual void					Update(float dtime) override;
	virtual void					PostUpdate(float dtime) override;

	void							SetSize(Vector2f size);
	void							SetSelectedTexture(const std::string& texture);
	void							SetUnselectedTexture(const std::string& texture);
	void							SetMaxLength(uint maxLength);
	void							SetFontSize(uint fontSize);
	void							SetFont(const std::string& font);

	void							CreateObjects();

	void							Select();
	void							Unselect();


private:

	virtual void					ParseAttribute(const TiXmlAttribute* attribute) override;

	ObjectRef						m_stateObjects[NUM_STATES];

	bool							m_selected;
	Vector2f						m_size;
	std::string						m_textures[NUM_STATES];

	uint							m_maxLength;
	uint							m_fontSize;

	std::string						m_font;

};		

