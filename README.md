# Sudoku-Solver
Solves a game of sudoku given a .txt file with initial values. This was a way for me to experiment and learn more about recursive backtracking, so everything is pretty rudimentary.

## Setting Up
The program initializes the game with initial values that are set by the user. There is no error-checking right now, so submitting an empty, or incorrectly formatted file will just screw up the output. 

### Formatting the input
Each line has everything needed to place a single given value. The first number in the line represents the row the value will be in. The second represents the column. The last represents the actual value to place. For example, `1 4 7` means that the value `7` is on row `1` and column `4`
```
1 4 7
2 1 8
2 4 3
2 5 5
2 9 1
3 3 9
3 6 8
3 7 6
3 8 7
4 1 3
4 7 1
4 8 9
4 9 5
6 1 9
6 2 4
6 3 6
6 9 2
7 2 1
7 3 8
7 4 9
7 7 2
8 1 6
8 5 1
8 6 3
8 9 8
9 6 4
```

## Starting
The input from the last section will result in an output:
```
+---+---+---+   +---+---+---+   +---+---+---+
|   |   |   |   | 7 |   |   |   |   |   |   |
+---+---+---+   +---+---+---+   +---+---+---+
| 8 |   |   |   | 3 | 5 |   |   |   |   | 1 |
+---+---+---+   +---+---+---+   +---+---+---+
|   |   | 9 |   |   |   | 8 |   | 6 | 7 |   |
+---+---+---+   +---+---+---+   +---+---+---+

+---+---+---+   +---+---+---+   +---+---+---+
| 3 |   |   |   |   |   |   |   | 1 | 9 | 5 |
+---+---+---+   +---+---+---+   +---+---+---+
|   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+   +---+---+---+   +---+---+---+
| 9 | 4 | 6 |   |   |   |   |   |   |   | 2 |
+---+---+---+   +---+---+---+   +---+---+---+

+---+---+---+   +---+---+---+   +---+---+---+
|   | 1 | 8 |   | 9 |   |   |   | 2 |   |   |
+---+---+---+   +---+---+---+   +---+---+---+
| 6 |   |   |   |   | 1 | 3 |   |   |   | 8 |
+---+---+---+   +---+---+---+   +---+---+---+
|   |   |   |   |   |   | 4 |   |   |   |   |
+---+---+---+   +---+---+---+   +---+---+---+
```
