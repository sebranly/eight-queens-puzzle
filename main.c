#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "anagram.h"
#include "chess.h"

int menu();

int main()
{
	T_stack p;
	p.top=0;

	int keepGoing=1;
	int counter=0;
	int choice;
	int feedback;
	int element;
	int newElement;
	int e;
	int test=1;
	int i=0, j=0;
	int displayMode;

	char string[]="abcdefgh"; // 8 max. Think about changing the define value in stack.h to update it to a lower value

		do{
		choice=menu();
		switch(choice)
		{
			case 1:
			initialize(&p);
			printf("\nThe stack is empty (top is now %d)", p.top);
			break;

			case 2:
			feedback=stackIsFull(&p);
			if(feedback==1)
			{printf("\nThe stack is full");}
			else
			{printf("\nThe stack is not full");}
			break;

			case 3:
			feedback=stackIsEmpty(&p);
			if(feedback==1)
			{printf("\nThe stack is empty");}
			else
			{printf("\nThe stack is not empty");}
			break;

			case 4:
			displayStack(&p);
			break;

			case 5:
			printf("\nWhich value do you want to push? ");
			scanf("%d", &element);
			feedback=push(&p, element);
			if(feedback==0)
			{printf("\nPushing the value is not possible as the stack is full");}
			else
			{printf("\nThe element %d got pushed correctly", element);}
			break;

			case 6:
			feedback=pop(&p, &newElement);
			if(feedback==0)
			{printf("\nPopping is impossible as the stack is empty");}
			else
			{printf("\nThe element %d got popped correctly", newElement);}
			break;

			case 7:
			feedback=getTopOfStack(&p, &newElement);
			if(feedback==0)
			{printf("\nThe stack is empty so there is no top element to display");}
			else
			{printf("\nThe element %d is at the top of the stack", newElement);}
			break;

			case 8:
			feedback=validNodeSimpleCheck(&p);
			if(feedback==0)
			{printf("\nThere are some duplicate values");}
			else
			{printf("\nThere is no duplicate values");}
			break;

			// PROBLEM 1: PERMUTATIONS
			case 9:
            printf("\n\tDo you want to display the combinations?\n\t\t1 if you want to\n\t\tAnother value if you don't want to\n\tYour choice: ");
            scanf("%d", &displayMode);
			counter=0;
			initialize(&p);
			goToFirstChild(p);
			do{
				test=1;
				while(validNodeSimpleCheck(&p) && test==1)
				{
					if(nodeIsTerminal(p))
					{
						if(displayMode==1)
						{
						    for(i=1;i<=MAX-1;i++) printf("%c", string[p.elements[i]-1]);
                            printf("\t");
						}
						counter++;
						test=0;
					}
					else
					{
						goToFirstChild(p);
					}
				}
				while(!processIsComplete(p) && (p.elements[p.top]==MAX-1))
				{
					goToFather(p, e);
				}
				if(!processIsComplete(p))
				{
					goToNextBrother(p, e);
				}
			}while(!processIsComplete(p));
			printf("\n\nThere are %d combinations", counter);
			break;

            // PROBLEM 2: N QUEENS PUZZLE
			case 10:
			printf("\n\tDo you want to display the combinations?\n\t\t1 for a simple chess notation\n\t\t2 for a chessboard display (consumes space)\n\t\tAnother value if you don't want to\n\tYour choice: ");
			scanf("%d", &displayMode);
			printf("\n");
			counter=0;
			initialize(&p);
			goToFirstChild(p);
			do{
				test=1;
				while(validNodeSimpleCheck(&p) && validNodeDiagonalCheck(&p) && test==1)
				{
					if(nodeIsTerminal(p))
					{
						if(displayMode==1)
						{
                            for(i=1;i<=MAX-1;i++)
                            {
                                printf("%c%d", i-1+'a', p.elements[i]);
                            }
                            printf("\n");
						}
						else if(displayMode==2)
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
                                    if(p.elements[i]==j)
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
						counter++;
						test=0;
					}
					else
					{
						goToFirstChild(p);
					}
				}
				while(!processIsComplete(p) && (p.elements[p.top]==MAX-1))
				{
					goToFather(p, e);
				}
				if(!processIsComplete(p))
				{
					goToNextBrother(p, e);
				}
			}while(!processIsComplete(p));
			printf("\n\nThere are %d combinations", counter);
			break;

			case 11:
			printf("\n\nGoodbye\n\n");
			keepGoing=0;
			break;

			default:
			printf("\nIncorrect choice...");
			break;
		}

	}while(keepGoing);

	return 0;

}

int menu()
{
	int choice;
	printf("\n\n\tMENU :\n\t______");
	printf("\n\n\t 1-Initialize the stack");
	printf("\n\t 2-Check if the stack is full");
	printf("\n\t 3-Check if the stack is empty");
	printf("\n\t 4-Display the whole stack");
	printf("\n\t 5-Push a number to the stack");
	printf("\n\t 6-Pop a number from the stack");
	printf("\n\t 7-Check what is the value at the top");
	printf("\n\t 8-Check if the stack has duplicate values");
	printf("\n\t 9-Solve problem 1 about permutations (%d letters)", MAX-1);
	printf("\n\t10-Solve problem 2 about queens puzzle (%d queens)", MAX-1);
	printf("\n\t11-Exit");
	printf("\n\n\tYour choice: ");
	scanf("%d", &choice);
	return choice;
}
