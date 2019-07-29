#include "UnionAfx.h"
#include "oCNpcEx.h"
zCLASS_UNION_DEFINITION(oCNpcEx, oCNpc, 0, 0);

// Constructor
oCNpcEx::oCNpcEx() : oCNpc()
{
	// Aivars:
	memset(uAivars, 0, sizeof(uAivars));

	// Regeneration
	regenHPLock = 0;
	regenMPLock = 0;
}

// Regeneration:
void oCNpcEx::Regenerate()
{
	static const uint RegenHPID = 1;
	static const uint RegenMPID = 2;
	static const uint UnlockID	= 3;
	zBOOL bSuspendTimer = ogame->singleStep;

	timerAI.Suspend(RegenHPID,	bSuspendTimer);
	timerAI.Suspend(RegenMPID,	bSuspendTimer);
	timerAI.Suspend(UnlockID,	bSuspendTimer);

	// HP process...
	if(!regenHPLock  && uAivars[NPC_uAIVAR_REGEN_HP] && attribute[NPC_ATR_HITPOINTS] < attribute[NPC_ATR_HITPOINTSMAX])
		if(timerAI(RegenHPID, uAivars[NPC_uAIVAR_REGEN_HP]))
			attribute[NPC_ATR_HITPOINTS]++;
		
	// MP process...
	if(!regenMPLock && uAivars[NPC_uAIVAR_REGEN_MP] && attribute[NPC_ATR_MANA] < attribute[NPC_ATR_MANAMAX])
		if(timerAI(RegenMPID, uAivars[NPC_uAIVAR_REGEN_MP]))
			attribute[NPC_ATR_HITPOINTS]++; 
	
	// Unlocking:
	if(timerAI(UnlockID, 1000))
	{
		if(regenHPLock) regenHPLock--;
		if(regenMPLock) regenMPLock--;
	}

}

void oCNpcEx::OnDamage(oSDamageDescriptor& damage) 
{
    oCNpc::OnDamage(damage);
    regenHPLock		= 5;
    regenMPLock		= 2;
  }

void oCNpcEx::ProcessNpc()
{
	oCNpc::ProcessNpc();

	timerAI.Attach();
	Regenerate();
}

void oCNpcEx::Archive(zCArchiver& ar)
{
	oCNpc::Archive(ar);	
	CString nName;		// hlp_value for concatenation

	// Aivars: 
	ar.WriteRaw("uAivars", &uAivars, sizeof(uAivars));

	// Regeneration:
	ar.WriteInt("regenLockTime0", regenHPLock);
	ar.WriteInt("regenLockTime1", regenMPLock);
	
}

void oCNpcEx::Unarchive(zCArchiver& ar)
{
	oCNpc::Unarchive(ar);
	// Aivars:
	ar.ReadRaw("uAivars", &uAivars, sizeof(uAivars));

	// Regeneration:
	ar.ReadInt("regenLockTime0", regenHPLock);
	ar.ReadInt("regenLockTime1", regenMPLock);
}