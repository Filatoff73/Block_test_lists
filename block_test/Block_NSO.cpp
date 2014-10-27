#include "Block_NSO.h"
#include "AbstractBlock.h"
#include "Polus.h"

#include <iostream>
using namespace std;


Block_NSO::Block_NSO(void) : AbstractBlock()
{
	PU.SetIsOn(false);
	MU.SetIsOn(false);

	contacts[0].setAbsBlock(this);
	contacts[0].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_11);

	contacts[1].setAbsBlock(this);
	contacts[1].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_13);

	contacts[2].setAbsBlock(this);
	contacts[2].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_14);

	contacts[3].setAbsBlock(this);
	contacts[3].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_15);

	contacts[4].setAbsBlock(this);
	contacts[4].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_17);
 
	contacts[5].setAbsBlock(this);
	contacts[5].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_18);

	contacts[6].setAbsBlock(this);
	contacts[6].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_8);

	contacts[7].setAbsBlock(this);
	contacts[7].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_9);

	contacts[8].setAbsBlock(this);
	contacts[8].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_12);

	contacts[9].setAbsBlock(this);
	contacts[9].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_16);

	contacts[10].setAbsBlock(this);
	contacts[10].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_2);

	contacts[11].setAbsBlock(this);
	contacts[11].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_20);

	contacts[12].setAbsBlock(this);
	contacts[12].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_22);

	contacts[13].setAbsBlock(this);
	contacts[13].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_21);

	contacts[14].setAbsBlock(this);
	contacts[14].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_6);

	contacts[15].setAbsBlock(this);
	contacts[15].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_7);

	contacts[16].setAbsBlock(this);
	contacts[16].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_5);

	contacts[17].setAbsBlock(this);
	contacts[17].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_19);

	contacts[18].setAbsBlock(this);
	contacts[18].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_4);

	contacts[19].setAbsBlock(this);
	contacts[19].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_3);

	contacts[20].setAbsBlock(this);
	contacts[20].check = (bool(AbstractBlock::*)(RelayArrList*&))(&Block_NSO::f1_1);

}
//Полюс и контакт одно и тоже для возврата

Block_NSO::~Block_NSO(void)
{

}



//Частично, полюс не готов
bool Block_NSO::f1_11(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;


	//cout<<PU.IsOn()<<endl<<MU.IsOn()<<endl;

	if(!PU.IsOn() && !MU.IsOn())
	{
		if (Polus::IsPolusM())
			res = true;//isPolusM

		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[3].execNeighbours(tmpRList[0]);  //1 15
		tmpRet[1] = contacts[20].execNeighbours(tmpRList[1]); //1 1

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}


	if(PU.IsOn() && !MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[20].execNeighbours(tmpRList[0]);//1 1

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}


	if(!PU.IsOn() && MU.IsOn())
	{
		if (Polus::IsPolusM())
			res = true;//isPolusM
	}

//  	if(PU.IsOn() && MU.IsOn())
//  	{
// 		cout<<"sdf";
//  	}

	return res;
}
//Готово
bool Block_NSO::f1_13(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;


	if(!PU.IsOn() && !MU.IsOn())
	{
		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[19].execNeighbours(tmpRList[0]);  //1 3
		tmpRet[1] = contacts[4].execNeighbours(tmpRList[1]); //1 17

		//Включение реле ПУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &PU);
		}
		//Включение реле ПУ и МУ
		if(tmpRet[1])
		{
			RelayArrList::addRelay(tmpRList[1], &PU);
			RelayArrList::addRelay(tmpRList[1], &MU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);



	}


	if(PU.IsOn() && !MU.IsOn())
	{
		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[19].execNeighbours(tmpRList[0]);//1 3

		//Включение реле ПУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &PU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!PU.IsOn() && MU.IsOn())
// 	{
// 	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_14(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	
	if(PU.IsOn())
	{
		
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[18].execNeighbours(tmpRList[0]);//1 4

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!PU.IsOn())
// 	{
// 	}

	return res;
}
//Частично, полюс не готов
bool Block_NSO::f1_15(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;



	if(!PU.IsOn() && !MU.IsOn())
	{
		if (Polus::IsPolusM())
			res = true;//isPolusM

		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[0].execNeighbours(tmpRList[0]);  //1 11
		tmpRet[1] = contacts[20].execNeighbours(tmpRList[1]); //1 1

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(PU.IsOn() && !MU.IsOn())
	{
		if (Polus::IsPolusM())
			res = true;//isPolusM
	}
	if(!PU.IsOn() && MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[20].execNeighbours(tmpRList[0]);//1 1

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_17(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;


	if(!PU.IsOn() && !MU.IsOn())
	{
		int num = 4;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[19].execNeighbours(tmpRList[0]);  //1 3
		tmpRet[1] = contacts[1].execNeighbours(tmpRList[1]); //1 13

		//Включение реле МУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &MU);
		}
		//Включение реле ПУ и МУ
		if(tmpRet[1])
		{
			RelayArrList::addRelay(tmpRList[1], &MU);
			RelayArrList::addRelay(tmpRList[1], &PU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(!PU.IsOn() && MU.IsOn())
	{
		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[19].execNeighbours(tmpRList[0]);//1 3

		//Включение реле МУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &MU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}
// 	if(PU.IsOn() && !MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_18(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[17].execNeighbours(tmpRList[0]);//1 19

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_8 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;


	if(!PU.IsOn() && !MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[7].execNeighbours(tmpRList[0]);//1 9

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}
// 	if(PU.IsOn() && !MU.IsOn())
// 	{
// 	}
// 	if(!PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_9 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(!PU.IsOn() && !MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[6].execNeighbours(tmpRList[0]);//1 8

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}
// 	if(PU.IsOn() && !MU.IsOn())
// 	{
// 	}
// 	if(!PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_12(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(PU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[5].execNeighbours(tmpRList[0]);//1 16

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!PU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_16(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;


	if(PU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[8].execNeighbours(tmpRList[0]);//1 12

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_2 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[11].execNeighbours(tmpRList[0]);//1 20

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_20(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;
		
	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[10].execNeighbours(tmpRList[0]);//1 2

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_22(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[13].execNeighbours(tmpRList[0]);//1 21

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_21(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[12].execNeighbours(tmpRList[0]);//1 22

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}

bool Block_NSO::f1_6 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(PU.IsOn() && MU.IsOn())
	{
	}
	if(!PU.IsOn() && MU.IsOn())
	{
	}
// 	if(PU.IsOn() && !MU.IsOn())
// 	{
// 	}
// 	if(!PU.IsOn() && !MU.IsOn())
// 	{
// 	}

	return res;
}

bool Block_NSO::f1_7 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(PU.IsOn() && MU.IsOn())
	{
	}
	if(PU.IsOn() && !MU.IsOn())
	{
	}
	if(!PU.IsOn() && MU.IsOn())
	{
	}
// 	if(!PU.IsOn() && !MU.IsOn())
// 	{
// 	}

	return res;
}

bool Block_NSO::f1_5 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(PU.IsOn() && MU.IsOn())
	{
	}
	if(PU.IsOn() && !MU.IsOn())
	{
	}
// 	if(!PU.IsOn() && MU.IsOn())
// 	{
// 	}
// 	if(!PU.IsOn() && !MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_19(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[5].execNeighbours(tmpRList[0]);//1 18

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(!MU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_4 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(PU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);
		
		tmpRet[0] = contacts[2].execNeighbours(tmpRList[0]);//1 14

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	// 	if(!PU.IsOn())
// 	{
// 	}

	return res;
}
//Готово
bool Block_NSO::f1_3 (RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;

	if(!PU.IsOn() && !MU.IsOn())
	{
		int num = 4;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[1].execNeighbours(tmpRList[0]);  //1 13
		tmpRet[1] = contacts[4].execNeighbours(tmpRList[1]); //1 17

		//Включение реле ПУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &PU);
		}
		//Включение реле МУ
		if(tmpRet[1])
		{
			RelayArrList::addRelay(tmpRList[1], &MU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(PU.IsOn() && !MU.IsOn())
	{
		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[1].execNeighbours(tmpRList[0]);  //1 13

		//Включение реле ПУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &PU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(!PU.IsOn() && MU.IsOn())
	{
		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[4].execNeighbours(tmpRList[0]);  //1 17

		//Включение реле МУ
		if(tmpRet[0])
		{
			RelayArrList::addRelay(tmpRList[0], &MU);
		}

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}
//Частично, полюс не готов
bool Block_NSO::f1_1(RelayArrList *& relayList)
{
	bool res = false;
	relayList = NULL;
	
	if(!PU.IsOn() && !MU.IsOn())
	{
		if (Polus::IsPolusM())
			res = true;//isPolusM

		int num = 2;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[3].execNeighbours(tmpRList[0]);  //1 15
		tmpRet[1] = contacts[0].execNeighbours(tmpRList[1]); //1 11

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(PU.IsOn() && !MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[0].execNeighbours(tmpRList[0]); //1 11

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
	if(!PU.IsOn() && MU.IsOn())
	{
		int num = 1;
		RelayArrList** tmpRList = new RelayArrList *[num];
		bool * tmpRet = new bool [num];
		BlockContact::initRelayArrays(tmpRList, tmpRet, num);

		tmpRet[0] = contacts[3].execNeighbours(tmpRList[0]); //1 15

		RelayArrList::clearRelayList(relayList);
		relayList = new RelayArrList;

		res |= RelayArrList::joinRelays(tmpRList, tmpRet, num, relayList);
	}
// 	if(PU.IsOn() && MU.IsOn())
// 	{
// 	}

	return res;
}

