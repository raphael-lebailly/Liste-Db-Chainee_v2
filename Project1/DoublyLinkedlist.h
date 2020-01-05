#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE_NAME 80

#define INCREASING_O 0
#define DECREASING_O 1

#define DISTINCT_DATA -1
#define EQL_DATA 0

#define INF_DATA 1
#define SUP_DATA 2
#define END_OF_COMPARISON 3

// dev2
// dev2

/****************************************************************/
/*							STRUCTURES							*/
/****************************************************************/

struct etCell {
	void *pData;
	struct etCell *pRight;
	struct etCell *pLeft;
};

struct etList
{
	struct etCell *pStart;
	struct etCell *pEnd;
	struct etCell *pCurrentCell;
};


/****************************************************************/
/*							PROTOTYPES							*/
/****************************************************************/

/*****************************/
/*	fonctions membres		 */
/*****************************/

void InitObj(struct etList *pListClients);
void InsertCell(struct etList *pListClients, void *pDataToList, int(*pCompareClients)(void*, void*), int (pIsEqual)(void *, void *), void(*pAllocMemoryForCell)(void*, void*));
//void DisplayListCell(struct etList stListClients, int dReadingOrder);
void DestructObject(struct etList *pListClients);

/*****************************/
/*	fonctions non-membres	 */
/*****************************/
void cleanScreen();
void viderBuffer();