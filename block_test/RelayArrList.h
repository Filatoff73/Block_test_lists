#pragma once
#include "Relay.h"
#define NULL 0
class RelayArrList
{
public:
	RelayArrList(void);
	~RelayArrList(void);

	 static void ToEndList(RelayArrList*&  relayList);
	 static void clearRelayList(RelayArrList*&  relayList);
	 static void addRelay(RelayArrList*&  relayList, Relay* relay1);
	 static bool joinRelays(RelayArrList**& relayArr, bool *& retArr, int size, RelayArrList*& relayList); 


	 int GetNrelay()
	 {
		return n;
	 }

	 void SetNrelay(int k)
	 {
		 n=k;
	 }

	 


	Relay* relay;
	class RelayArrList* next;
	class RelayArrList* first;
private:
	int n;


};

