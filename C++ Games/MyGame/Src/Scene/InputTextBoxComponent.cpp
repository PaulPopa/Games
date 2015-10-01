#include "InputTextBoxComponent.h"
#include "App.h"
#include "Helpers.h"
#include "stdincl.h"
#include "Input.h"
#include "SpriteComponent.h"

REGISTERIMPL(InputTextBoxComponent);

InputTextBoxComponent::InputTextBoxComponent()
{
}

InputTextBoxComponent::~InputTextBoxComponent()
{
}

void InputTextBoxComponent::OnAddToObject()
{
	CreateObjects();
}

void InputTextBoxComponent::Update(float dtime)
{

}

void InputTextBoxComponent::PostUpdate(float dtime)
{
}

void InputTextBoxComponent::SetSize(Vector2f size)
{
	m_size = size;
}

void InputTextBoxComponent::SetSelectedTexture(const std::string& texture)
{
	m_textures[SELECTED] = texture;
}

void InputTextBoxComponent::SetUnselectedTexture(const std::string& texture)
{
	m_textures[UNSELECTED] = texture;
}

void InputTextBoxComponent::SetMaxLength(uint maxLength)
{
	m_maxLength = maxLength;
}

void InputTextBoxComponent::SetFontSize(uint fontSize)
{
	m_fontSize = fontSize;
}

void InputTextBoxComponent::SetFont(const std::string& font)
{
	m_font = font;
}

void InputTextBoxComponent::CreateObjects()
{
	auto selectedObject = Object::Create();
	auto unselectedObject = Object::Create();
	auto infoObject = Object::Create();

	infoObject->SetPos(Vector2f(0, -50));

	auto selectedSpriteComp = selectedObject->AddComponent<SpriteComponent>();
	auto unselectedSpriteComp = unselectedObject->AddComponent<SpriteComponent>();
	auto infoTextComp = infoObject->AddComponent<TextComponent>();

	selectedSpriteComp->SetTexture(m_textures[SELECTED]);
	unselectedSpriteComp->SetTexture(m_textures[UNSELECTED]);

	infoTextComp->SetFont(m_font);
	infoTextComp->SetFontSize(m_fontSize);
	infoTextComp->SetText("Insert Profile Name here(Max " + std::to_string(m_maxLength) + " characters)");

	selectedSpriteComp->SetSize(m_size);
	unselectedSpriteComp->SetSize(m_size);

	m_stateObjects[SELECTED] = selectedObject.get();
	m_stateObjects[UNSELECTED] = unselectedObject.get();

	m_object->AddChild(std::move(selectedObject));
	m_object->AddChild(std::move(unselectedObject));
	m_object->AddChild(std::move(infoObject));

	m_stateObjects[SELECTED]->Disable();
}

void InputTextBoxComponent::Select()
{
	if (!m_selected)
	{
		m_stateObjects[SELECTED]->Enable();
		m_stateObjects[UNSELECTED]->Disable();
		m_selected = true;
	}
}

void InputTextBoxComponent::Unselect()
{
	if (m_selected)
	{
		m_stateObjects[UNSELECTED]->Enable();
		m_stateObjects[SELECTED]->Disable();
		m_selected = false;
	}
}

void InputTextBoxComponent::ParseAttribute(const TiXmlAttribute* attribute)
{
	Component::ParseAttribute(attribute);
	if (IsEqual(attribute->Name(), "size"))
	{
		SetSize(ParseVector2f(attribute->Value()));
	}
	else if (IsEqual(attribute->Name(), "texture_selected"))
	{
		SetSelectedTexture(attribute->Value());
	}
	else if (IsEqual(attribute->Name(), "texture_unselected"))
	{
		SetUnselectedTexture(attribute->Value());
	}
	else if (IsEqual(attribute->Name(), "max_length"))
	{
		SetMaxLength(attribute->UnsignedValue());
	}
	else if (IsEqual(attribute->Name(), "font_size"))
	{
		SetFontSize(attribute->UnsignedValue());
	}
	else if (IsEqual(attribute->Name(), "font"))
	{
		SetFont(attribute->Value());
	}
}
