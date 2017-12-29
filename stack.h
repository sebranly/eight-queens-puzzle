#ifndef STACKH
#define STACKH

// IMPORTANT: for the eight queens puzzle, MAX should not be greater than 9 because the process would be long, plus a chessboard has a 8x8 size
#define MAX 5 // MAX - 1 elements in the stack (this constant is used for both problems) as index 0 is used differently

typedef int T_Elt;

typedef struct {
	T_Elt elements[MAX];
	int top;
} T_stack;

void initialize(T_stack *);
int stackIsFull(T_stack *);
int push(T_stack *, T_Elt);
void displayStack(T_stack *);
int stackIsEmpty(T_stack *);
int pop(T_stack *, T_Elt *);
int getTopOfStack(T_stack *, T_Elt *);

#endif
