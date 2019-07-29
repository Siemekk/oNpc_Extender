#pragma once
class oCObjectFactoryEx : public oCObjectFactory
{
	zCLASS_UNION_DECLARATION(oCObjectFactoryEx);
public:
	virtual oCNpc* CreateNpc(int index); // new oCNpc constructor (new vftable)
};

