#include "chess.h"

int noeud_valide_diag(T_pile *lap)
{
    int valeur;
	int pileValide=1; //On part du principe qu'elle est valide
	int i, j;

	for(i=1;i<=(lap->sommet);i++)
	{
		valeur=lap->corps[i];
		for(j=i+1;j<=(lap->sommet);j++)
		{
			if((abs((lap->corps[j])-valeur))==j-i) pileValide=0; //Ce sont deux dames sur la même diagonale !
		}
	}

	return pileValide;
}
