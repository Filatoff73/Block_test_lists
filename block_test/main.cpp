#include <iostream>
#include "Block_NSO.h"
#include "Block_NM1.h"
#include <string>


using namespace std;

string PRINT_BLOCK_RET(int val)
{
	switch (val)
	{
	case 16: return "BLOCK_RETURN_NONE";
	case 8: return "BLOCK_RETURN_MINUS";
	case 4: return "BLOCK_RETURN_PLUS";
	case 2: return "BLOCK_RETURN_PASS";
	case 1: return "BLOCK_RETURN_FAIL";
	};
}


void test(FILE*& file , Block_NSO& block, RelayArrList*& relayList)
{
	for(int i=0;i<21;i++)
	{
		fprintf(file,"contact number = %d, res = %d, relaylist: ", i, block.getBlockContact(i).work(relayList) );

		if(relayList)
		{
			relayList = relayList->first;

			while(relayList->next!=NULL)
			{
				fprintf(file,"%d, ",relayList->relay);
				relayList = relayList->next;
			}

			RelayArrList::clearRelayList(relayList);
		}
		else
			fprintf(file," NULL" );

		fprintf(file,"\n" );

	}
}

void TestBlock_NSO()
{
	FILE* file;
	Block_NSO block;
	RelayArrList* relayList = new RelayArrList;

	file = new FILE;

	if( (file=fopen("BLOCK_NSO.txt","w") ) == 0 ) { 
		printf("error open file"); }

	relayList=NULL;

	for(int i=0;i<21;i++)
	{
		block.getBlockContact(i).addNeighbour(NULL);
		block.getBlockContact(i).setToMinusNeighbourNum(0);
	}

	fprintf(file,"BLOCK_NSO \n");
	//Первый вариант
	block.setMU(false);
	block.setPU(false);
	fprintf(file,"MU = false, PU = false \n");	
	test(file,block,relayList);

	block.setMU(true);
	block.setPU(false);
	fprintf(file,"\n MU = true, PU = false \n");
	test(file,block,relayList);

	block.setMU(false);
	block.setPU(true);
	fprintf(file,"\n MU = false, PU = true \n");
	test(file,block,relayList);
// 
	block.setMU(true);
	block.setPU(true);
	fprintf(file,"\n MU = true, PU = true \n");
	test(file,block,relayList);

// 	cout<<block.getBlockContact(1).work(relayList)<<endl;
// 
// 	cout<<endl;
// 
// 	if(relayList)
// 	{
// 
// 	relayList = relayList->first;
// 
// 	while(relayList->next!=NULL)
// 	{
// 
// 		cout<<relayList->relay<<endl;
// 		relayList = relayList->next;
// 	}
// 
// 	}
// 
// 	RelayArrList::clearRelayList(relayList);
	cout<<"endtest"<<endl;

	fclose(file);
}


int main()
{

	TestBlock_NSO();

//	int i;
	Block_NSO block;
	Block_NM1 blockNM4;
	Block_NM1 blockNM2;
//	block.contacts[0].neighbour = blockNM4.contact[5];
// 	Block_NSO block;

	//cout<<relayList->first->GetNrelay()<<endl;

// 	cout << PRINT_BLOCK_RET(block.f1(true).leftSideRet) << endl;
// 	cout << PRINT_BLOCK_RET(block.f1(true).rightSideRet) << endl;
// 
// 
// 	bool b = block.f3(false).leftSideRet == BLOCK_RETURN_PASS;
// 	block.g3(false,  b);
// 	cout << block.IsMU() << " "  << block.IsPU() << endl;


	system("pause");

	return 0;
}