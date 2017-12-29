#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void initialize(T_stack * stack)
{
	stack->top=0;
}

int stackIsFull(T_stack * stack)
{
	if((stack->top)==(MAX-1))
	{return 1;}
	else
	{return 0;}
}

int push(T_stack * stack, T_Elt e)
{
	if(stackIsFull(stack))
	{return 0;}
	else
	{
		(stack->top)++;
		stack->elements[stack->top]=e;
		return 1;
	}
}

void displayStack(T_stack * stack)
{
	int i=0;
	if(stackIsEmpty(stack))
	{printf("\nThe stack is empty");}
	else
	{
		printf("\n\nHere are the elements in the stack:\n");
		for(i=stack->top;i>=1;i--)
		printf("%d\t", stack->elements[i]);
	}

}

int stackIsEmpty(T_stack * stack)
{
	if((stack->top)==(0))
	{return 1;}
	else
	{return 0;}
}

int pop(T_stack * stack, T_Elt * e)
{
	if(stackIsEmpty(stack))
	{return 0;}
	else
	{
		*e=stack->elements[stack->top];
		(stack->top)--;
		return 1;
	}
}

int getTopOfStack(T_stack * stack, T_Elt * e)
{
	if(stackIsEmpty(stack))
	{return 0;}
	else
	{
		*e=stack->elements[stack->top];
		return 1;
	}
}
