#include "DoublyLinkedList.h"

/********************************************************************************************************************************/
/*															FONCTIONS MEMBRES													*/
/********************************************************************************************************************************/

/****************************************************************************************************/
/*	FONCTION InitObj()					réserve de l'espace mémoire pour l'objet liste et 			*/
/*										initialise ses pointeurs à NULL								*/
/*																									*/
/*	---------------																					*/
/*		@param {pListClients}		(struct)		p. vers stListClients							*/
/*																									*/
/****************************************************************************************************/
void InitObj(struct etList *pListClients)
{
	/************************************************************/
	/* Allocation de mémoire									*/
	/************************************************************/
	//init objet

	pListClients->pStart = (etCell*)malloc(sizeof(etCell));
	assert(pListClients->pStart);

	pListClients->pEnd = (etCell*)malloc(sizeof(etCell));
	assert(pListClients->pEnd);

	/************************************************************/
	/* initialisation de la liste								*/
	/************************************************************/

	/****************************************************/
	/* Les extrémités externes de la liste sont 		*/
	/* initialisées à NULL tandis que les extrêmités	*/
	/* internes pointent les unes vers les autres		*/
	/****************************************************/
	pListClients->pStart->pLeft = NULL;
	pListClients->pStart->pRight = pListClients->pEnd;

	pListClients->pEnd->pLeft = pListClients->pStart;
	pListClients->pEnd->pRight = NULL;

	/****************************************************/
	/* la variable pCurrentCell pointe vers la dernière	*/
	/* cellule de la liste								*/
	/****************************************************/
	pListClients->pCurrentCell = pListClients->pEnd;
	//pListClients->pCurrentCell = pListClients->pStart;
}

/****************************************************************************************************/
/*	FONCTION InsertCell()				insère un nouveau client dans la liste doublement chaînée	*/
/*																									*/
/*	---------------																					*/
/*		@param {pListClients}		(struct)		p. vers stListClients							*/
/*		@param {stNewClient}		(struct)		struct. comprenant un ID et un nom de client	*/
/*																									*/
/*	---------------																					*/
/*		@var {dSizeName}	 		(int)			récupère la taille du nom inséré + '\0'			*/
/*		@var {pNewCell}	 			(struct)		nouvelle variable cellule créée dans le but		*/
/*													d'allouer de la mémoire pour le nouveau client	*/
/*																									*/
/****************************************************************************************************/

void InsertCell(struct etList *pListClients, void *pDataToList, int(*pCompareClients)(void*, void*), int (pIsEqual)(void *, void *), void(*pAllocMemoryForCell)(void*, void*))
{
	/********************************************************/
	/* appel de la fonction clCompareClient() qui determine */
	/* si donnée à insérer est inférieure au data de la		*/
	/* cellule pointée par l'index pCurrentCell			   	*/
	/********************************************************/
	printf("1\n");
	system("pause");
	while (pListClients->pCurrentCell != pListClients->pEnd
		&& pListClients->pCurrentCell->pRight != NULL
		&& pCompareClients(pListClients->pCurrentCell->pData, pDataToList) == INF_DATA)
	{
		pListClients->pCurrentCell = pListClients->pCurrentCell->pRight;
	}

	printf("2\n");
	system("pause");

	/********************************************************/
	/* appel de la fonction clCompareClient() qui determine */
	/* si donnée à insérer est supérieure au data de la 	*/
	/* cellule pointée par l'index pCurrentCell			   	*/
	/********************************************************/
	while (pListClients->pCurrentCell != pListClients->pEnd
		&& pListClients->pCurrentCell->pLeft != NULL
		&& pCompareClients(pListClients->pCurrentCell->pData, pDataToList) == SUP_DATA)
	{
		pListClients->pCurrentCell = pListClients->pCurrentCell->pLeft;
	}

	printf("3\n");
	system("pause");

	/********************************************************/
	/* appel de la fonction clIsEqual() qui determine		*/
	/* si donnée à insérer est équivalente au data de la 	*/
	/* cellule pointée par l'index pCurrentCell			   	*/
	/********************************************************/

	if ((pListClients->pCurrentCell != pListClients->pEnd)
		&& (pIsEqual(pListClients->pCurrentCell->pData, pDataToList) == EQL_DATA))
		return;


	/********************************************************/
	/* entre dans la condition si le client n'existe pas 	*/
	/* dans la liste										*/
	/********************************************************/
	else 
	{
		/****************************************************/
		/* Entre dans la condition si la cell. en cours ne	*/
		/* pointe pas vers la dernière cellule de la liste	*/
		/****************************************************/
		if (pListClients->pCurrentCell != pListClients->pEnd)
			pListClients->pCurrentCell = pListClients->pCurrentCell->pRight;

		/****************************************************/
		/* Crée une cellule et alloue de l'espace mémoire	*/
		/* pour chaque membre de cette cellule				*/
		/****************************************************/
		struct etCell *pNewCell = NULL;

		pNewCell = (etCell*)realloc(pNewCell, sizeof(etCell));
		pAllocMemoryForCell(pNewCell->pData, pDataToList);
		pNewCell = (etCell*)realloc(pNewCell, sizeof(pDataToList));
		pNewCell->pData = pDataToList;

		/****************************************************/
		/*	Reliure cellule aux autres cellules de la liste	*/
		/****************************************************/
		// 1
		pNewCell->pRight = pListClients->pCurrentCell;
		// 2
		pNewCell->pLeft = pListClients->pCurrentCell->pLeft;
		// 3
		pListClients->pCurrentCell->pLeft = pNewCell;
		// 4
		pNewCell->pLeft->pRight = pNewCell;

		/****************************************************/
		/*	Repositionnement la cellule courante			*/
		/****************************************************/
		pListClients->pCurrentCell = pNewCell;
		return;
	}
}


/****************************************************************************************************/
/*	FONCTION DisplayListCell()				génère un menu de choix d'affichage croissant ou		*/
/*											décroissant de la liste									*/
/*																									*/
/*	---------------																					*/
/*		@param {stListClients}		(struct)		contient des cellules de structures etClient	*/
/*		@param {dReadingOrder}		(int)			reçoit une constante depuis le client précisant	*/
/*													l'ordre de lecture : croissant ou décroissant	*/
/*	---------------																					*/
/*		@var {dI}					(sh. int)		permet de parcourir le switch afin d'allouer	*/
/*													de la mémoire pour le nouveau client			*/
/*																									*/
/*																									*/
/****************************************************************************************************/
//void DisplayListCell(struct etList stListClients, int dReadingOrder)
//{
//	short int dI = 1;
//
//	/********************************************************/
//	/*	Croissant											*/
//	/********************************************************/
//
//	if (dReadingOrder == INCREASING_O)
//	{
//		stListClients.pCurrentCell = stListClients.pStart;
//		stListClients.pCurrentCell = stListClients.pCurrentCell->pRight;
//
//		while (stListClients.pCurrentCell->pRight != NULL)
//		{
//			printf(" Client %d : \t ID : %d \t | Nom : %s", dI++,
//			stListClients.pCurrentCell->stData.dId,
//				stListClients.pCurrentCell->stData.sName);
//
//			stListClients.pCurrentCell = stListClients.pCurrentCell->pRight;
//		}
//		printf("\n");
//
//		cleanScreen();
//	}
//
//	/********************************************************/
//	/*	Décroissant											*/
//	/********************************************************/
//
//	else if ((dReadingOrder == DECREASING_O))
//	{
//		stListClients.pCurrentCell = stListClients.pEnd;
//		stListClients.pCurrentCell = stListClients.pCurrentCell->pLeft;
//
//		while (stListClients.pCurrentCell->pLeft != NULL)
//		{
//			printf(" Client %d : \t ID : %d \t | Nom : %s", dI++,
//				stListClients.pCurrentCell->stData.dId,
//				stListClients.pCurrentCell->stData.sName);
//			
//			stListClients.pCurrentCell = stListClients.pCurrentCell->pLeft;
//		}
//		printf("\n");
//
//		cleanScreen();
//	}
//}


/****************************************************************************************************/
/*	FONCTION DestructObject()				libère la mémoire allouée pour créer la liste			*/
/*																									*/
/*	---------------																					*/
/*		@param {pListClients}	(struct)		p. vers stListClients								*/
/*																									*/
/*	---------------																					*/
/*		@var {pTempRight}	 	(int)			permet le swap des éléments de pCurrentCell		*/
/*																									*/
/****************************************************************************************************/
void DestructObject(struct etList *pListClients)
{
	struct etCell *pTempRight;

	pListClients->pCurrentCell = pListClients->pStart;

	while (pListClients->pCurrentCell != NULL)
	{
		pTempRight = pListClients->pCurrentCell->pRight;
		free(pListClients->pCurrentCell);
		pListClients->pCurrentCell = pTempRight;
	}
}

/********************************************************************************************************************************/
/*															FONCTIONS NON-MEMBRES												*/
/********************************************************************************************************************************/
/****************************************************************************************************/
/*	FONCTION viderBuffer()				vide le buffer de son contenu à l'aide d'une variable		*/
/*																									*/
/*	---------------																					*/
/*		@var {C}	 		(int)		variable qui parcourt le buffer								*/
/*																									*/
/****************************************************************************************************/
void viderBuffer()
{
	int C = 0;
	while (C != '\n' && C != EOF)
	{
		C = getchar();
	}

	return;
}


/****************************************************************************************************/
/*	FONCTION cleanScreen()				met le systeme en pause puis balaye l'affichage				*/
/****************************************************************************************************/
void cleanScreen()
{
	system("pause");
	system("cls");
	return;
}
