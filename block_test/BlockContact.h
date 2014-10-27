#ifndef KEA_BLOCK_CONTACT
#define KEA_BLOCK_CONTACT


#include "tp_constant.h"
#include "Relay.h"
#include "RelayArrList.h"
#include "AbstractBlock.h"

class BlockContact
{
public:
	BlockContact(void);
	~BlockContact(void);

	bool(AbstractBlock::* check)(RelayArrList*& relayList);
	
	static void initRelayArrays(RelayArrList** relayArr, bool * retArr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			relayArr[i] = new RelayArrList;
			retArr[i] = false;
			
		}

	}


	bool blankMinus(RelayArrList*& relayList)
	{
		return true;
	}

	bool blankPlus(RelayArrList*& relayList)
	{
		return false;
	}

	void setToMinusNeighbourNum(int num)
	{
		neighbours[num] = new BlockContact;
		neighbours[num]->check = (bool(AbstractBlock::*)(RelayArrList*&))(&BlockContact::blankMinus);
	}

	void setToPlusNeighbourNum(int num)
	{
		neighbours[num] = new BlockContact;
		neighbours[num]->check = (bool(AbstractBlock::*)(RelayArrList*&))(&BlockContact::blankPlus);
	}


	bool work (RelayArrList*& relayList)
	{
		return (absBlock->*check)(relayList);
	}
	
	bool execNeighbours(RelayArrList * &relayList)
	{

		RelayArrList ** relayArr = new RelayArrList * [nNeighbours];
		bool* retArr = new bool[nNeighbours];

		initRelayArrays(relayArr,retArr,nNeighbours);

		bool res = false;

		for (int i = 0; i < nNeighbours; i++)
		{

			if(neighbours[i]) 
			{
				retArr[i] = neighbours[i]->work(relayArr[i]);
			}

			if(retArr[i])
			{
				res = true;
			}
			
		}

		if(!res)
		{
			for (int i = 0; i < nNeighbours; i++)
			{
				if(relayArr[i])
					RelayArrList::clearRelayList(relayArr[i]);
			}
			delete [] retArr;
			delete [] relayArr;
			return false;
		}


		//relayList = new RelayArrList;

		RelayArrList::joinRelays(relayArr,retArr,nNeighbours,relayList);
		return true;
	}


	void setAbsBlock(AbstractBlock * absBlock)
	{
		this->absBlock = absBlock;
	}






	int getNneighbours()
	{
		return nNeighbours;
	}

	void setNneighbours(int a)
	{
		deleteNeigboursArr();
		nNeighbours=a;
		neighbours = new BlockContact *[nNeighbours];
		for(int i=0;i<nNeighbours;i++)
		{
			neighbours[i] = NULL;
		}
	}

	void addNeighbour(BlockContact * bc)
	{
		if(nNeighbours==0)
		{
			neighbours = new BlockContact *[nNeighbours+1];
				neighbours[nNeighbours] = bc;
		}

		if(nNeighbours>0)
		{
			BlockContact** temp = new BlockContact*[nNeighbours];

			for(int i=0;i<nNeighbours;i++)
			{
				temp[i] = neighbours[i];
			}

			delete []neighbours;
			neighbours = new BlockContact *[nNeighbours+1];

			for(int i=0;i<nNeighbours;i++)
			{
				neighbours[i] = temp[i];
			}

			neighbours[nNeighbours] = bc;

			delete []temp;

		}


		nNeighbours++;

	}

	void deleteNeigboursArr()
	{
		if(neighbours)
		{
			for(int i=0;i<nNeighbours;i++)
			{
				if(neighbours[i] && ( (neighbours[i]->check == (bool(AbstractBlock::*)(RelayArrList*&))(&BlockContact::blankMinus)) || (neighbours[i]->check == (bool(AbstractBlock::*)(RelayArrList*&))(&BlockContact::blankPlus))  ) )
				{
					delete neighbours[i];
					neighbours[i]=NULL;
				}
			}

			delete [] neighbours;
			neighbours=NULL;
			nNeighbours=0;
		}

	}

	BlockContact* getNeighboursToNum(int num)
	{
		return neighbours[num];
	}

	void setNeighbourToNum(BlockContact * bc, int num)
	{
		neighbours[num] = bc;
	}
	

private:
	static const int LIST_MAX_SIZE = 10;



	bool turnOnList[LIST_MAX_SIZE];
	bool turnOffList[LIST_MAX_SIZE];

	int nNeighbours;
	BlockContact ** neighbours;
	block_ret_value ret_val;

	AbstractBlock * absBlock;
};

#endif