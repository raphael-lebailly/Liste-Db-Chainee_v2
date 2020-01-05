#include "DoublyLinkedList.h"
#include "clientSide.h"

int main()
{	
	/****************************************************************/
	/*							VARIABLES							*/
	/****************************************************************/
	struct etList stListClients;
	struct etClient stNewClient;

	int dChoix = 0;
	int dCroissantDecroissant = 0;

	/****************************************************************/
	/*						INITIALISATION							*/
	/****************************************************************/
	InitObj(&stListClients);

	/****************************************************************/
	/*								MENU							*/
	/****************************************************************/
	do
	{
		printf("faites votre choix : \n\n");
		printf("\t1. ajouter un client \n");
		printf("\t2. supprimer une cellule \n");
		printf("\t3. afficher la chaine \n");
		printf("\t4. quitter \n");

		scanf_s("%d", &dChoix);
		viderBuffer();

		switch (dChoix)
		{
		/********************************************************/
		/*	Insertion dans la liste								*/
		/********************************************************/
		case 1:
			printf("Le nom du client:");
			fgets(stNewClient.sName, SIZE_NAME, stdin);
			printf("\n");

			printf("L'ID du client:");
			scanf_s("%d", &stNewClient.dId);
			printf("\n");

			viderBuffer();
			InsertCell(&stListClients, &stNewClient, clCompareClients, clIsEqual, clAllocMemoryForCell);

			cleanScreen();
			break;

		/********************************************************/
		/*	Suppression d'une cellule							*/
		/********************************************************/
		case 2: // suppression de la cellule
			cleanScreen(); 
			break;

		/********************************************************/
		/*	Affichage											*/
		/********************************************************/
		//case 3:
		//	do
		//	{
		//		printf("\n\nDans quel ordre voulez-vous parcourir la liste ? \n\n");
		//		printf("\t1. Croissant \n");
		//		printf("\t2. Decroissant \n");

		//		scanf_s("%d", &dCroissantDecroissant);
		//		viderBuffer();

		//		switch (dCroissantDecroissant)
		//		{
		//			/********************************************/
		//			/*	Croissant								*/
		//			/********************************************/
		//		case 1:
		//			DisplayListCell(stListClients, INCREASING_O);
		//			break;

		//			/********************************************/
		//			/*	Décroissant								*/
		//			/********************************************/
		//		case 2:
		//			DisplayListCell(stListClients, DECREASING_O);
		//			break;

		//			/********************************************/
		//			/*	Choix invalide							*/
		//			/********************************************/
		//		default:
		//			printf("ce choix n'est pas valide.\n");
		//			cleanScreen();
		//			break;
		//		}
		//	} while (dCroissantDecroissant != 1 && dCroissantDecroissant != 2);
		//	break;

		/********************************************************/
		/*	Quitter												*/
		/********************************************************/
		case 4:
			dChoix = 0;
			break;

		/********************************************************/
		/*	Choix invalide										*/
		/********************************************************/
		default:
			printf("ce choix n'est pas valide.\n");
			cleanScreen();
			break;
		}

	} while (dChoix);

	DestructObject(&stListClients);
	
	system("pause");
	return 0;
}