#ifndef PILEH
#define PILEH

//IMPORTANT : MAX ne doit pas etre mise à plus de 9 car le processus devient long et aussi car la taille d'un échiquier est 8 (9-1)
#define MAX 9 //MAX-1 éléments empilables (Cette constante sert aux deux problèmes)

typedef int T_Elt;

typedef struct {
	T_Elt corps[MAX];
	int sommet;
}T_pile;

void init(T_pile *);
int pile_pleine(T_pile *);
int empiler(T_pile *, T_Elt);
void afficher(T_pile *);
int pile_vide(T_pile *);
int depiler(T_pile *, T_Elt *);
int sommet(T_pile *, T_Elt *);

#endif
