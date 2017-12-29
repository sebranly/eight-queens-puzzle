#ifndef ANAGRAMH
#define ANAGRAMH

#include "stack.h"

#define goToFirstChild(p) push(&p, 1);
#define goToNextBrother(p, e) pop(&p, &e);\
				   push(&p, e + 1);
#define nodeIsTerminal(p) stackIsFull(&p) == 1
#define goToFather(p, e) pop(&p, &e);
#define processIsComplete(p) stackIsEmpty(&p) == 1

int validNodeSimpleCheck(T_stack *);

#endif
