#include "PlayerMovementComponent.h"
#include "App.h"
#include "Helpers.h"
#include "stdincl.h"
#include "SpriteSheetComponent.h"
#include "Input.h"

REGISTERIMPL(PlayerMovementComponent);

PlayerMovementComponent::PlayerMovementComponent()
{
}

PlayerMovementComponent::~PlayerMovementComponent()
{
}

void PlayerMovementComponent::OnAddToObject()
{
	auto spriteSheetObject = Object::Create();
	auto spriteSheetComp = std::make_unique<SpriteSheetComponent>();

	spriteSheetComp->SetFrameRate(m_frameRate);
	spriteSheetComp->SetTexture(m_texture);
	spriteSheetComp->SetLinesNumber(m_linesNumber);
	spriteSheetComp->SetColumnsNumber(m_columnsNumber);
	spriteSheetComp->SetLineSize(10);

	spriteSheetObject->AddComponent(std::move(spriteSheetComp));
	m_spriteSheetObject = spriteSheetObject.get();
	m_object->AddChild(std::move(spriteSheetObject));
}

void PlayerMovementComponent::Update(float dtime)
{
	CheckInput();
}

void PlayerMovementComponent::PostUpdate(float dtime)
{

}

uint PlayerMovementComponent::GetAction(const std::string& action)
{
	if (IsEqual(action.c_str(), "action_move_left"))
	{
		return MOVE_LEFT;
	}
	else if (IsEqual(action.c_str(), "action_move_right"))
	{
		return MOVE_RIGHT;
	}
	else if (IsEqual(action.c_str(), "action_move_up"))
	{
		return MOVE_UP;
	}
	else if (IsEqual(action.c_str(), "action_move_down"))
	{
		return MOVE_DOWN;
	}
	else if (IsEqual(action.c_str(), "action_spell_attack_left"))
	{
		return SPELL_ATTACK_LEFT;
	}
	else if (IsEqual(action.c_str(), "action_spell_attack_right"))
	{
		return SPELL_ATTACK_RIGHT;
	}
	else if (IsEqual(action.c_str(), "action_spell_attack_up"))
	{
		return SPELL_ATTACK_UP;
	}
	else if (IsEqual(action.c_str(), "action_spell_attack_down"))
	{
		return SPELL_ATTACK_DOWN;
	}
	assert(0);
	return 10000;
}

void PlayerMovementComponent::SetTexture(const std::string& filename)
{
	m_texture = filename;
}

void PlayerMovementComponent::SetFrameRate(uint frameRate)
{
	m_frameRate = frameRate;
}

void PlayerMovementComponent::SetLinesNumber(uint linesNumber)
{
	m_linesNumber = linesNumber;
}

void PlayerMovementComponent::SetColumnsNumber(uint columnsNumber)
{
	m_columnsNumber = columnsNumber;
}

void PlayerMovementComponent::SetActionLine(uint action, uint line)
{
	m_actionsLines[action] = line;
}

void PlayerMovementComponent::SetActionLineSize(uint action, uint size)
{
	m_actionsLinesSizes[action] = size;
}

void PlayerMovementComponent::CheckInput()
{

	auto spriteSheetComp = m_spriteSheetObject->GetComponent<SpriteSheetComponent>();
	assert(spriteSheetComp);

	if (g_input->WasPressedThisTurn(KEY_A))
	{
		m_currentAction = MOVE_LEFT;
	}
	else if (g_input->WasPressedThisTurn(KEY_D))
	{
		m_currentAction = MOVE_RIGHT;
	}
	else if (g_input->WasPressedThisTurn(KEY_W))
	{
		m_currentAction = MOVE_UP;
	}
	else if (g_input->WasPressedThisTurn(KEY_S))
	{
		m_currentAction = MOVE_DOWN;
	}
	else if (g_input->WasPressedThisTurn(KEY_Q))
	{
		m_currentAction += 4;
		if (m_currentAction >= NUM_ACTIONS)
		{
			m_currentAction -= 4;
		}
	}
	else if (!g_input->IsPressed(KEY_A) && !g_input->IsPressed(KEY_D) && !g_input->IsPressed(KEY_W) && !g_input->IsPressed(KEY_S) && !g_input->IsPressed(KEY_Q))
	{
		spriteSheetComp->SetCurrentColumn(IDLE_ANIMATION);
	}

	spriteSheetComp->SetCurrentLine(m_actionsLines[m_currentAction]);
	spriteSheetComp->SetLineSize(m_actionsLinesSizes[m_currentAction]);
}

void PlayerMovementComponent::ParseAttribute(const TiXmlAttribute* attribute)
{
	Component::ParseAttribute(attribute);
	if (IsEqual(attribute->Name(), "texture"))
	{
		SetTexture(attribute->Value());
	}
	else if (IsEqual(attribute->Name(), "frame_rate"))
	{
		SetFrameRate(attribute->UnsignedValue());
	}
	else if (IsEqual(attribute->Name(), "lines_number"))
	{
		SetLinesNumber(attribute->UnsignedValue());
	}
	else if (IsEqual(attribute->Name(), "columns_number"))
	{
		SetColumnsNumber(attribute->UnsignedValue());
	}
	else if (StringStartsWith("action", attribute->Name()))
	{
		Vector2f v = ParseVector2f(attribute->Value());
		SetActionLine(GetAction(attribute->Name()), (uint)v.x);
		SetActionLineSize(GetAction(attribute->Name()), (uint)v.y);
	}
}