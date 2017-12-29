#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "anagram.h"
#include "chess.h"

int menu();

int main(void)
{
	T_stack p;
	initialize(&p);

	int keepGoing = 1, test;
	int counter, choice, element, newElement, e, i, j, displayMode;
	char * string;

	string = malloc(sizeof(char) * MAX);
	if (string == NULL)
    {
        printf("There is a problem with memory, please relaunch the program\n");
        return EXIT_FAILURE;
    }
    for (i = 0 ; i < MAX ; i++)
        string[i] = i + 'a';

    do
    {
		choice = menu();
		switch (choice)
		{
			case 1:
			initialize(&p);
			printf("The stack is empty (top is now %d)\n", p.top);
			break;

			case 2:
			if (stackIsFull(&p))
                printf("The stack is full\n");
			else
                printf("The stack is not full\n");
			break;

			case 3:
			if (stackIsEmpty(&p))
                printf("The stack is empty\n");
			else
                printf("The stack is not empty\n");
			break;

			case 4:
			displayStack(&p);
			break;

			case 5:
			printf("Which value do you want to push? Your choice: ");
			scanf("%d", &element);
			if (push(&p, element))
                printf("The element %d got pushed correctly\n", element);
			else
                printf("Pushing the value is not possible as the stack is full\n");
			break;

			case 6:
			if (pop(&p, &newElement))
                printf("The element %d got popped correctly\n", newElement);
			else
                printf("Popping is impossible as the stack is empty\n");
			break;

			case 7:
			if (getTopOfStack(&p, &newElement))
                printf("The element %d is at the top of the stack\n", newElement);
			else
                printf("The stack is empty so there is no top element to display\n");
			break;

			case 8:
			if (validNodeSimpleCheck(&p))
                printf("There is no duplicate values\n");
			else
                printf("There are some duplicate values\n");
			break;

			// PROBLEM 1: PERMUTATIONS
			case 9:
            printf("\tDo you want to display the combinations?\n\t\t1 if you want to\n\t\tAnother value if you don't want to\n\tYour choice: ");
            scanf("%d", &displayMode);
			counter = 0;
			initialize(&p);
			goToFirstChild(p);
			do
			{
				test = 1;
				while (validNodeSimpleCheck(&p) && test)
				{
					if (nodeIsTerminal(p))
					{
						if (displayMode == 1)
						{
						    for (i = 1 ; i < MAX ; i++)
                                printf("%c", string[p.elements[i] - 1]);
                            printf("\t");
						}
						counter++;
						test = 0;
					}
					else
						goToFirstChild(p);
				}
				while (!processIsComplete(p) && (p.elements[p.top] == MAX - 1))
					goToFather(p, e);
				if (!processIsComplete(p))
				{
					goToNextBrother(p, e);
				}
			} while (!processIsComplete(p));
			printf("\nThere are %d combinations\n", counter);
			break;

            // PROBLEM 2: N QUEENS PUZZLE
			case 10:
			printf("\tDo you want to display the combinations?\n\t\t1 for a simple chess notation\n\t\t2 for a chessboard display (consumes space)\n\t\tAnother value if you don't want to\n\tYour choice: ");
			scanf("%d", &displayMode);
			printf("\n");
			counter = 0;
			initialize(&p);
			goToFirstChild(p);
			do
			{
				test = 1;
				while (validNodeSimpleCheck(&p) && validNodeDiagonalCheck(&p) && test)
				{
					if (nodeIsTerminal(p))
					{
						if (displayMode == 1)
						{
                            for(i = 1 ; i < MAX ; i++)
                                printf("%c%d", i - 1 + 'a', p.elements[i]);
                            printf("\n");
						}
						else if (displayMode == 2)
						{
						    printf("    ");
						    for(i = 1 ; i < MAX ; i++)
                                printf("  %c ", i - 1 + 'A');
                            printf("\n");
                            for(j = 1 ; j < MAX ; j++)
                            {
                                printf("\n    ");
                                for(i = 1 ; i < MAX ; i++)
                                    printf("+---");

                                printf("+\n  %d ", j);

                                for(i = 1 ; i < MAX ; i++)
                                {
                                    if (p.elements[i] == j)
                                        printf("| R ");
                                    else
                                        printf("| . ");
                                }
                                printf("|");
                            }

                            printf("\n    ");

                            for(i = 1 ; i < MAX ; i++)
                                printf("+---");

                            printf("+");
                            printf("\n\n");
						}
						counter++;
						test = 0;
					}
					else
						goToFirstChild(p);
				}
				while (!processIsComplete(p) && (p.elements[p.top] == MAX - 1))
					goToFather(p, e);
				if (!processIsComplete(p))
				{
					goToNextBrother(p, e);
				}
			} while (!processIsComplete(p));
			printf("\nThere are %d combinations\n", counter);
			break;

			case 11:
			printf("Goodbye\n");
			keepGoing = 0;
			break;

			default:
			printf("Incorrect choice...\n");
			break;
		}
	} while(keepGoing);
	return EXIT_SUCCESS;
}

int menu(void)
{
	int choice;
	printf("\n\tMENU:\n\t-----\n");
	printf("\t 1 - Initialize the stack\n");
	printf("\t 2 - Check if the stack is full\n");
	printf("\t 3 - Check if the stack is empty\n");
	printf("\t 4 - Display the whole stack\n");
	printf("\t 5 - Push a number to the stack\n");
	printf("\t 6 - Pop a number from the stack\n");
	printf("\t 7 - Check what is the value at the top\n");
	printf("\t 8 - Check if the stack has duplicate values\n");
	printf("\t 9 - Solve problem 1 about permutations (%d letters)\n", MAX - 1);
	printf("\t10 - Solve problem 2 about queens puzzle (%d queens)\n", MAX - 1);
	printf("\t11 - Exit\n");
	printf("\tYour choice: ");
	scanf("%d", &choice);
	return choice;
}
