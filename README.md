# eight-queens-puzzle
The eight queens puzzle is a famous problem we solved as freshmen in 2012 in a few hours. This repository gathers two similar problems (see "Evolution between problem 1 and problem 2" down below for more information):
- Problem 1 is the permutation of N letters
- Problem 2 is the N queens puzzle

## Test

### Problem 1

If the input is 3 then it will find all permutations of 3 letters: `abc`, `acb`, `bac`, `bca`, `cab`, `cba`. For N letters, there are always N! permutations (e.g. for 3 letters, there are `3 * 2 * 1 = 6` combinations).

### Problem 2

The input is the size of the chessboard (8 means the chessboard has an 8x8 conventional size). If the chessboard has an 8x8 size, there are 92 distinct solutions being displayed (see https://en.wikipedia.org/wiki/Eight_queens_puzzle#Solutions for more explanation about it).
Solutions can be displayed in two ways:
- as a simple chess notation (e.g. for a 4x4 size there are 2 combinations: `a2b4c1d3` and `a3b1c4d2`)
- as an actual chessboard

A chessboard with a 4x4 size would show these 2 solutions in this display mode:
```
    A   B   C   D

  +---+---+---+---+
1 | . | . | R | . |
  +---+---+---+---+
2 | R | . | . | . |
  +---+---+---+---+
3 | . | . | . | R |
  +---+---+---+---+
4 | . | R | . | . |
  +---+---+---+---+
  
    A   B   C   D

  +---+---+---+---+
1 | . | R | . | . |
  +---+---+---+---+
2 | . | . | . | R |
  +---+---+---+---+
3 | R | . | . | . |
  +---+---+---+---+
4 | . | . | R | . |
  +---+---+---+---+
  
There are 2 combinations
```

## Algorithm

### Structure needed for the algorithm

A tree is built
```
a
	aa (can be abandoned)
	ab
		aba (can be abandoned)
		abb (can be abandoned)
		abc
	ac
		...
b
	ba
	bb (can be abandoned)
		...
	bc
		...
c
	ca
		...
	cb
		...
	cc (can be abandoned)
```
If a node has duplicate values then there is point in going deeper in this branch.
The terminal nodes are the solutions to the problem.
A stack is needed in order to store the different choices that were made while going through the tree.

### Terminology

If `ab` is the current node then:
- `aba` is its first child
- `a` is its father
- `ac` is its next brother

### Steps of the algorithm

Here is the algorithm to follow in order to find the solutions thanks to the tree
```
Start at #0 of the stack (which is empty)
#1 of the stack receives the first element possible (e.g. the first letter)
REPEAT
	1] WHILE the current node is valid
		IF this is a terminal node
			Print the solution
			Go out of 1] and go to 2]
		ELSE
			Go to this node's first child
			(i.e. go to the next level of depth by picking the first element possible (e.g. the first letter))
		END OF IF
	END OF WHILE
	
	2] WHILE all solutions are not found AND the current node doesn't have brothers anymore
		Go to this node's father
	END OF WHILE
	
	3] IF all solutions are not found
		Go to this node's next brother
	END OF IF
UNTIL all solutions are found
```


### Evolution between problem 1 and problem 2

- Problem 1 is the permutation of N letters
- Problem 2 is the N queens puzzle

Problem 2 is a simple evolution of problem 1: we know for sure that they can't be two queens on the same line. Hence we just have to determinate the columns' numbers to solve the problem.
Problem 1 is actually similar to a N rooks/castles puzzle.
In order to solve problem 2, we can keep the same logic as problem 1 then add a diagonal check as queens can move diagonally whereas rooks/castles can't.
