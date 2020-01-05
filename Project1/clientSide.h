#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DoublyLinkedlist.h"

#define SIZE_NAME 80



/****************************************************************/
/*							STRUCTURES							*/
/****************************************************************/

struct etClient
{
	int dId;
	char sName[SIZE_NAME];
};

/****************************************************************/
/*							PROTOTYPES							*/
/****************************************************************/

int clCompareClients(void *pCurrentData, void *pNewClient);
int clIsEqual(void *pCurrentData, void *pNewClient);
void clAllocMemoryForCell(void *pCurrentData, void *pNewClient);
