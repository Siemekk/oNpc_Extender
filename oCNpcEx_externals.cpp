#include "UnionAfx.h"
#include "oCNpcEx.h"
#ifndef castTo
#define castTo(par, cast) ((zCVob*)par->GetInstance())->CastTo<cast>()
#endif

static zBOOL uSetAivar()
{
	zCParser* par = zCParser::GetParser();
	oCNpcEx*  pSelf; 
	int offset;
	int value;

	par->GetParameter(value);
	par->GetParameter(offset);
	pSelf = castTo(par, oCNpcEx);

	if(pSelf) 
	{
		if(offset < 0)				offset = 0;
		if(offset >= uAivarSize)	offset = uAivarSize - 1;
		
		pSelf->uAivars[offset] = value;
	}
	return FALSE;
}

static zBOOL uGetAivar()
{
	zCParser* par = zCParser::GetParser();
	oCNpcEx*  pSelf; 
	int offset;

	par->GetParameter(offset);
	pSelf = castTo(par, oCNpcEx);

	if(pSelf) 
	{
		if(offset < 0)				offset = 0;
		if(offset >= uAivarSize)	offset = uAivarSize - 1;
		
		par->SetReturn(pSelf->uAivars[offset]);
	}
	return FALSE;
}

void uExtender_DefineExternals()
{
	// void Npc_SetAivar (oCNpc self, int offset, int value);
	parser->DefineExternal("Npc_SetAivar", uSetAivar, zPAR_TYPE_VOID, zPAR_TYPE_INSTANCE, zPAR_TYPE_INT, zPAR_TYPE_INT, 0); 

	// int Npc_GetAivar (oCNpc self, int offset);
	parser->DefineExternal("Npc_GetAivar", uGetAivar, zPAR_TYPE_INT, zPAR_TYPE_INSTANCE, zPAR_TYPE_INT, 0);


}