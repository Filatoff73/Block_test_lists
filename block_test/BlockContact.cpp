#include "BlockContact.h"


BlockContact::BlockContact(void)
{
	neighbours = 0;
	nNeighbours = 0;
	absBlock=NULL;
	
}


BlockContact::~BlockContact(void)
{
	deleteNeigboursArr();
}
