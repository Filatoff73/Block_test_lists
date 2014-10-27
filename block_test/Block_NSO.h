#ifndef KEA_BLOCK_NSO
#define KEA_BLOCK_NSO

#include "AbstractBlock.h"
#include "BlockContact.h"


//////////////////////////////////////////////////////////////////////////
// Блок НСО - одиночная стрелка
// 2 реле: ПУ и МУ
// Внешние реле отсутствуют
//////////////////////////////////////////////////////////////////////////

class Block_NSO : public AbstractBlock
{
public:
	Block_NSO(void);
	~Block_NSO(void);

	bool f1_11(RelayArrList *& relayList);
	bool f1_13(RelayArrList *& relayList);
	bool f1_14(RelayArrList *& relayList);
	bool f1_15(RelayArrList *& relayList);
	bool f1_17(RelayArrList *& relayList);
	bool f1_18(RelayArrList *& relayList);
	bool f1_8 (RelayArrList *& relayList);
	bool f1_9 (RelayArrList *& relayList);
	bool f1_12(RelayArrList *& relayList);
	bool f1_16(RelayArrList *& relayList);
	bool f1_2 (RelayArrList *& relayList);
	bool f1_20(RelayArrList *& relayList);
	bool f1_22(RelayArrList *& relayList);
	bool f1_21(RelayArrList *& relayList);
	bool f1_6 (RelayArrList *& relayList);
	bool f1_7 (RelayArrList *& relayList);
	bool f1_5 (RelayArrList *& relayList);
	bool f1_19(RelayArrList *& relayList);
	bool f1_4 (RelayArrList *& relayList);
	bool f1_3 (RelayArrList *& relayList);
	bool f1_1 (RelayArrList *& relayList);
// 	block_ret_value f2(bool isMinus);
// 	block_ret_value f3(bool isMinus);
// 	block_ret_value f4(bool isMinus);
// 
// 
// 	void g1();
// 	void g2();
// 	void g3(bool isMinus, bool isGood);
// 	void g4();
// 
// 
// 	block_ret_value f_18_19();
// 	block_ret_value f_112_116();
// 	block_ret_value f_12_120();
// 	block_ret_value f_15_17();
// 	block_ret_value f_16_17();
// 	block_ret_value f_121_122();



	void setPU(bool b)
	{
		PU.SetIsOn(b);
	}

	void setMU(bool b)
	{
		MU.SetIsOn(b);
	}

	bool IsPU()
	{
		return PU.IsOn();
	}


	bool IsMU()
	{
		return MU.IsOn();
	}

	BlockContact& getBlockContact(int num)
	{
		return contacts[num];
	}

private:
	Relay PU, MU;

//	0  	- 1 11
// 	1  	- 1 13
// 	2  	- 1 14
// 	3  	- 1 15
// 	4  	- 1 17
// 	5  	- 1 18
// 	6  	- 1 8
// 	7  	- 1 9
// 	8  	- 1 12
// 	9  	- 1 16
// 	10 	- 1 2
// 	11 	- 1 20
// 	12 	- 1 22
// 	13 	- 1 21
// 	14 	- 1 6
// 	15 	- 1 7
// 	16 	- 1 5
// 	17 	- 1 19
// 	18 	- 1 4
// 	19 	- 1 3
// 	20 	- 1 1

	BlockContact contacts[21];
};



#endif