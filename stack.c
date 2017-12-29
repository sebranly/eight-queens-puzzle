#include <stdio.h>
#include "stack.h"

void initialize(T_stack * stack)
{
	stack->top = 0;
}

int stackIsFull(T_stack * stack)
{
	return stack->top == MAX - 1;
}

int stackIsEmpty(T_stack * stack)
{
	return stack->top == 0;
}

int push(T_stack * stack, T_Elt e)
{
	if (stackIsFull(stack))
        return 0;
	(stack->top)++;
	stack->elements[stack->top] = e;
	return 1;
}

int pop(T_stack * stack, T_Elt * e)
{
	if (stackIsEmpty(stack))
        return 0;
	*e = stack->elements[stack->top];
    (stack->top)--;
    return 1;
}

void displayStack(T_stack * stack)
{
	int i;
	if (stackIsEmpty(stack))
        printf("The stack is empty\n");
	else
	{
		printf("Here are the elements in the stack:\n");
		for (i = stack->top ; i > 0 ; i--)
		printf("%d\t", stack->elements[i]);
	}
}

int getTopOfStack(T_stack * stack, T_Elt * e)
{
	if (stackIsEmpty(stack))
        return 0;
	*e = stack->elements[stack->top];
	return 1;
}
