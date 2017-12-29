#include "anagram.h"

int validNodeSimpleCheck(T_stack * stack)
{
	int value;
	int validStack=1;
	int i, j;

	for(i=1;i<=(stack->top);i++)
	{
		value=stack->elements[i];
		for(j=i+1;j<=(stack->top);j++)
		{
			if(stack->elements[j]==value) validStack=0;
		}
	}

	return validStack;
}
