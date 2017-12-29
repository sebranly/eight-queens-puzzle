#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "anagram.h"
#include "chess.h"

int menu();

int main()
{
	T_pile p;
	p.sommet=0;

	int continuer=1;
	int compteur=0;
	int choix;
	int retour;
	int element;
	int nouvelElement;
	int e;
	int test=1;
	int i=0, j=0;
	int affichage;

	char chaine[]="abcdefgh"; //8 au plus. PENSEZ A REDEFINIR LE MAX DE PILE.H POUR D'AUTRES VALEURS

		do{
		choix=menu();
		switch(choix)
		{
			case 1:
			init(&p);
			printf("\nLa pile est vide (sommet vaut désormais %d !)", p.sommet);
			break;

			case 2:
			retour=pile_pleine(&p);
			if(retour==1)
			{printf("\nLa pile est pleine !");}
			else
			{printf("\nLa pile est non pleine !");}
			break;

			case 3:
			retour=pile_vide(&p);
			if(retour==1)
			{printf("\nLa pile est vide !");}
			else
			{printf("\nLa pile est non vide !");}
			break;

			case 4:
			afficher(&p);
			break;

			case 5:
			printf("\nQue voulez-vous empiler comme valeur ? ");
			scanf("%d", &element);
			retour=empiler(&p, element);
			if(retour==0)
			{printf("\nIl est impossible d'empiler l'élément car la pile est pleine !");}
			else
			{printf("\nL'élement %d a bien été empilé !", element);}
			break;

			case 6:
			retour=depiler(&p, &nouvelElement);
			if(retour==0)
			{printf("\nIl est impossible de dépiler car la pile est vide !");}
			else
			{printf("\nL'élement %d a bien été dépilé !", nouvelElement);}
			break;

			case 7:
			retour=sommet(&p, &nouvelElement);
			if(retour==0)
			{printf("\nIl est impossible de consulter car la pile est vide !");}
			else
			{printf("\nL'élement %d est la valeur au sommet de la pile !", nouvelElement);}
			break;

			case 8:
			retour=noeud_valide_simple(&p);
			if(retour==0)
			{printf("\nIl y a des doublons !");}
			else
			{printf("\nLa pile ne possède pas de doublon !");}
			break;

			//ELEMENT PRINCIPAL DU PROGRAMME : PERMUTATIONS
			case 9:
            printf("\n\tVoulez vous un affichage ?\n\t\t1 pour OUI\n\t\tN'importe quelle valeur pour NON\n\tChoisissez : ");
            scanf("%d", &affichage);
			compteur=0;
			init(&p);
			passerAuPremierFils(p);
			do{
				test=1;
				while(noeud_valide_simple(&p) && test==1)
				{
					if(noeudTerminal(p))
					{
						//AFFICHAGE
						if(affichage==1)
						{
						    for(i=1;i<=MAX-1;i++) printf("%c", chaine[p.corps[i]-1]);
                            printf("\t");
						}
						compteur++;
						test=0;
					}
					else
					{
						passerAuPremierFils(p);
					}
				}
				while(!rechercheTerminee(p) && (p.corps[p.sommet]==MAX-1))
				{
					remonterAuPere(p, e);
				}
				if(!rechercheTerminee(p))
				{
					passerAuFrereSuivant(p, e);
				}
			}while(!rechercheTerminee(p));
			printf("\n\nIl y a %d possibilités !", compteur);
			printf("\nRemarque : vous pouvez tester avec de plus grands mots en redéfinissant la constante MAX dans le code !");
			break;

            //RESOLUTION DU PROBLEME DES DAMES
			case 10:
			printf("\n\tVoulez-vous un affichage ?\n\t\t1 pour NOTATION ECHEC\n\t\t2 pour ECHIQUIER 2D\n\t\tN'importe quelle autre valeur pour AUCUN AFFICHAGE\n\tChoisissez : ");
			scanf("%d", &affichage);
			printf("\n");
			compteur=0;
			init(&p);
			passerAuPremierFils(p);
			do{
				test=1;
				while(noeud_valide_simple(&p) && noeud_valide_diag(&p) && test==1)
				{
					if(noeudTerminal(p))
					{
						//AFFICHAGE
						if(affichage==1)
						{
                            for(i=1;i<=MAX-1;i++)
                            {
                                printf("%c%d", i-1+'a', p.corps[i]);
                            }
                            printf("\n");
						}
						else if(affichage==2)
						{
						    printf("    ");
						    for(i=1;i<=MAX-1;i++)
                            {
                                    printf("  %c ", i-1+'A');
                            }
                            printf("\n");
                            for(j=1;j<=MAX-1;j++)
                            {
                                printf("\n    ");
                                for(i=1;i<=MAX-1;i++) printf("+---");

                                printf("+\n  %d ", j);

                                for(i=1;i<=MAX-1;i++)
                                {
                                    if(p.corps[i]==j)
                                    {printf("| R ");}
                                    else
                                    {printf("| . ");}
                                }
                                printf("|");
                            }

                            printf("\n    ");

                            for(i=1;i<=MAX-1;i++) printf("+---");

                            printf("+");
                            printf("\n\n");
						}
						compteur++;
						test=0;
					}
					else
					{
						passerAuPremierFils(p);
					}
				}
				while(!rechercheTerminee(p) && (p.corps[p.sommet]==MAX-1))
				{
					remonterAuPere(p, e);
				}
				if(!rechercheTerminee(p))
				{
					passerAuFrereSuivant(p, e);
				}
			}while(!rechercheTerminee(p));
			printf("\n\nIl y a %d possibilités !", compteur);
			break;

			case 11:
			printf("\n\nVous avez choisi de quitter !\n\n");
			continuer=0;
			break;

			default:
			printf("\nChoix impossible !");
			break;
		}

	}while(continuer);

	return 0;

}

int menu()
{
	int choix;
	printf("\n\n\tMENU :\n\t______");
	printf("\n\n\t 1-Initialiser la pile");
	printf("\n\t 2-Tester si la pile est pleine");
	printf("\n\t 3-Tester si la pile est vide");
	printf("\n\t 4-Afficher toute la pile");
	printf("\n\t 5-Empiler un élément");
	printf("\n\t 6-Dépiler");
	printf("\n\t 7-Consulter la valeur au sommet");
	printf("\n\t 8-Vérifier que la pile n'a pas de doublons");
	printf("\n\t 9-Toutes les combinaisons en permutant %d lettres", MAX-1);
	printf("\n\t10-Résoudre le problème des dames sur un échiquier");
	printf("\n\t11-QUITTER");
	printf("\n\n\tVous sélectionnez : ");
	scanf("%d", &choix);
	return choix;
}
