#include "anagramme.h"

int noeud_valide_simple(T_pile * lap)
{
	int valeur;
	int pileValide=1; //On part du principe qu'elle est valide
	int i, j;

	for(i=1;i<=(lap->sommet);i++)
	{
		valeur=lap->corps[i];
		for(j=i+1;j<=(lap->sommet);j++)
		{
			if(lap->corps[j]==valeur) pileValide=0; //C'est un doublon
		}
	}

	return pileValide;
}
