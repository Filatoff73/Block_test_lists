#include "RelayArrList.h"


RelayArrList::RelayArrList(void)
{
	relay=NULL;
	next=NULL;
	first = this;
	n=0;
}


void RelayArrList::ToEndList(RelayArrList*&  relayList)
{
	while(relayList->next!=NULL)
	{
		relayList = relayList->next;
	}

}

void RelayArrList::addRelay(RelayArrList*&  relayList, Relay* relay1)
{
	ToEndList(relayList);
	relayList->relay=relay1;

	relayList->next = new RelayArrList;

	relayList->next->next=NULL;
	relayList->next->relay=NULL;
	relayList->next->first=relayList->first;

	relayList = relayList->next;

	int k=relayList->first->GetNrelay();
	k++;
	relayList->first->SetNrelay(k);

}

 void RelayArrList::clearRelayList(RelayArrList*&  relayList)
 {
	 
	 if(relayList)
	 {
		 //��������� � ������
		 relayList=relayList->first;

		RelayArrList *tmp = NULL;	
		while ((relayList->next)!=NULL) 
		{
			tmp = relayList->next;
			delete relayList;
			relayList = tmp;
		}

		delete relayList;
	 }

 }


 bool RelayArrList::joinRelays(RelayArrList**& relayArr, bool *& retArr, int size, RelayArrList*& relayList)
 {
	 bool res = false;

	 for (int i = 0; i < size; i++)
	 {
		 res |= retArr[i];
	 }

	 //����������� � ���������
	 if(res)
	 {
		 for (int i = 0; i < size; i++)
		 {
			 if(retArr[i] && relayArr[i])
			 {
				 relayArr[i] = relayArr[i]->first;

				 while(relayArr[i]->next!=NULL)
				 {
					 if (relayArr[i]->relay!=NULL)
					 {
						 addRelay(relayList,relayArr[i]->relay);
						 relayArr[i] = relayArr[i]->next;
					 }
				 }


			 }
		 }
	 }

	 //������������ ��������

	 if(relayArr)
	 {
		 for (int i = 0; i < size; i++)
		 {
			 if(relayArr[i])
			 {
				 clearRelayList(relayArr[i]);
			 }

		 }
		 delete []relayArr;
	 }


	 if(retArr) 
		 delete[] retArr;
	 retArr = 0;


	 return res;

 }


RelayArrList::~RelayArrList(void)
{

}
