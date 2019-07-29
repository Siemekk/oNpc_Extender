#include "UnionAfx.h"
#include "oCNpcEx.h"
#include "zCFactoryEx.h"
zCLASS_UNION_DEFINITION(oCObjectFactoryEx, oCObjectFactory, 0, 0);

oCNpc* oCObjectFactoryEx::CreateNpc(int index)
{
	oCNpc* npc = new oCNpcEx();
	if(index != zPAR_INDEX_UNDEF)
		npc->InitByScript(index, 0);

	return npc;
}
