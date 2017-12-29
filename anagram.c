#include "anagram.h"

int validNodeSimpleCheck(T_stack * stack)
{
	int value, i, j;
	for (i = 1 ; i <= stack->top ; i++)
	{
		value = stack->elements[i];
		for (j = i + 1 ; j <= stack->top ; j++)
			if (stack->elements[j] == value)
                return 0;
	}
	return 1;
}
