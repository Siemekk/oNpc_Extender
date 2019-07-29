#pragma once
const int uAivarSize = 100;
const int NPC_uAIVAR_REGEN_HP = 0; // regeneration HP delay
const int NPC_uAIVAR_REGEN_MP = 1; // regeneration MP delay

class oCNpcEx : public oCNpc
{
public:	
	zCLASS_UNION_DECLARATION(oCNpcEx);
	CTimer timerAI;
	int regenHPLock;
	int regenMPLock;
	int uAivars[uAivarSize]; 
		
	oCNpcEx();
	void Regenerate(); 

	// Process
	virtual void OnDamage(oSDamageDescriptor&);
	virtual void ProcessNpc();

	// Archivers:
	virtual void Archive	(zCArchiver&);
	virtual void Unarchive	(zCArchiver&);

};

