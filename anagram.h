#ifndef ANAGRAMMEH
#define ANAGRAMMEH

#include "stack.h"

#define passerAuPremierFils(p) empiler(&p, 1);
#define passerAuFrereSuivant(p, e) depiler(&p, &e);\
				   empiler(&p, e+1);
#define noeudTerminal(p) pile_pleine(&p)==1
#define remonterAuPere(p, e) depiler(&p, &e);
#define rechercheTerminee(p) pile_vide(&p)==1

int noeud_valide_simple(T_pile *);

#endif
