#pragma once

#include "tp_constant.h"
#include "Relay.h"
#include "RelayArrList.h"

class BlockContact;

class AbstractBlock
{
public:
	AbstractBlock(void);

	~AbstractBlock(void);

	int getIdBlock()
	{
		return idBlock;
	}

	void setIdBlock(int a)
	{
		 idBlock = a;
	}

	virtual BlockContact& getBlockContact(int num) = 0;



protected:
	int idBlock;
};

