#include "clientSide.h"

int clCompareClients(void *pCurrentData, void *pNewClient)
{
	struct etClient* pLocalCurrentData = (struct etClient*)pCurrentData;
	struct etClient* pLocalNewClient = (struct etClient*)pNewClient;

	/********************************************************/
	/* parcours de la liste pour positionner le NewClient	*/
	/********************************************************/
	if (pLocalCurrentData->dId < pLocalNewClient->dId)
		return INF_DATA;

	else if (pLocalCurrentData->dId > pLocalNewClient->dId)
		return SUP_DATA;

	else 
		return END_OF_COMPARISON;
}

int clIsEqual(void *pCurrentData, void *pNewClient)
{
	struct etClient* pLocalCurrentData = (struct etClient*)pCurrentData;
	struct etClient* pLocalNewClient = (struct etClient*)pNewClient;


	if (pLocalCurrentData->dId == pLocalNewClient->dId)
	{
		printf("%d && %d", pLocalNewClient->dId, pLocalCurrentData->dId);
		printf("\n\t *Ce client existe deja.\n");
		return EQL_DATA;
	}

	else
	{
		printf("%d && %d", pLocalNewClient->dId, pLocalCurrentData->dId);
		printf("\n\t *Ce client n'existe pas.\n");
		return DISTINCT_DATA;
	}
}

void clAllocMemoryForCell(void *pCurrentData, void *pNewClient)
{
	struct etClient *pLocalCurrentData = (struct etClient*)pCurrentData;
	struct etClient *pLocalNewClient = (struct etClient*)pNewClient;

	/****************************************************/
	/*	Allocation de mémoire							*/
	/****************************************************/
	int dSizeName = (strlen(pLocalNewClient->sName) + 1);
	pLocalCurrentData = (etClient*)malloc(sizeof(etClient) + dSizeName*sizeof(char));

	//pCurrentData = (etClient*)realloc(pCurrentData, ((sizeof(pLocalNewClient->dId)) + (dSizeName * sizeof(char))));
	assert(pLocalCurrentData);

	pLocalCurrentData->dId = pLocalNewClient->dId;
	strcpy_s(pLocalCurrentData->sName, dSizeName, pLocalNewClient->sName);

	/****************************************************/
	/*	Copie data										*/
	/****************************************************/
	//strcpy_s(pLocalCurrentData->sName, dSizeName, pLocalNewClient->sName);
	//pLocalCurrentData->dId = pLocalNewClient->dId;
	pCurrentData = pLocalCurrentData;
}