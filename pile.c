#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

void init(T_pile * lap)
{
	lap->sommet=0;
}

int pile_pleine(T_pile * lap)
{
	if((lap->sommet)==(MAX-1))
	{return 1;}
	else
	{return 0;}
}

int empiler(T_pile * lap, T_Elt e)
{
	if(pile_pleine(lap))
	{return 0;}
	else
	{
		(lap->sommet)++;
		lap->corps[lap->sommet]=e;
		return 1;
	}
}

void afficher(T_pile * lap)
{
	int i=0;
	if(pile_vide(lap))
	{printf("\nLa pile est vide !");}
	else
	{
		printf("\n\nVoici les éléments de la pile :\n");
		for(i=lap->sommet;i>=1;i--)
		printf("%d\t", lap->corps[i]);
	}		
	
}

int pile_vide(T_pile * lap)
{
	if((lap->sommet)==(0))
	{return 1;}
	else
	{return 0;}
}

int depiler(T_pile * lap, T_Elt * e)
{
	if(pile_vide(lap))
	{return 0;}
	else
	{
		*e=lap->corps[lap->sommet];
		(lap->sommet)--;
		return 1;
	}
}

int sommet(T_pile * lap, T_Elt * e)
{
	if(pile_vide(lap))
	{return 0;}
	else
	{
		*e=lap->corps[lap->sommet];
		return 1;
	}
}
