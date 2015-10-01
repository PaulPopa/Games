#pragma once

#include "Component.h"
#include "stdincl.h"

#define IDLE_ANIMATION -1

enum ACTIONS {MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN, SPELL_ATTACK_LEFT, SPELL_ATTACK_RIGHT, SPELL_ATTACK_UP, SPELL_ATTACK_DOWN, NUM_ACTIONS};

class PlayerMovementComponent : public Component
{
	REGISTER(PlayerMovementComponent);

public:

	PlayerMovementComponent(void);
	~PlayerMovementComponent(void);

	virtual void						OnAddToObject() override;
	virtual void						Update(float dtime) override;
	virtual void						PostUpdate(float dtime) override;

	uint								GetAction(const std::string& action);

	void								SetTexture(const std::string& filename);
	void								SetFrameRate(uint frameRate);
	void								SetLinesNumber(uint linesNumber);
	void								SetColumnsNumber(uint columnsNumber);

	void								SetActionLine(uint action, uint line);
	void								SetActionLineSize(uint action, uint size);
		
private:

	void								CheckInput();
	virtual void						ParseAttribute(const TiXmlAttribute* attribute) override;

	uint								m_actionsLines[NUM_ACTIONS];
	uint								m_actionsLinesSizes[NUM_ACTIONS];

	bool								m_actions[NUM_ACTIONS];

	uint								m_frameRate;
	uint								m_linesNumber;
	uint								m_columnsNumber;

	int									m_currentAction;

	ObjectRef							m_spriteSheetObject;

	std::string							m_texture;

};

