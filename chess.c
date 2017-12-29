#include "chess.h"

int validNodeDiagonalCheck(T_stack *lap)
{
    int value;
	int validStack=1;
	int i, j;

	for(i=1;i<=(lap->top);i++)
	{
		value=lap->elements[i];
		for(j=i+1;j<=(lap->top);j++)
		{
			if((abs((lap->elements[j])-value))==j-i) validStack=0;
		}
	}

	return validStack;
}
