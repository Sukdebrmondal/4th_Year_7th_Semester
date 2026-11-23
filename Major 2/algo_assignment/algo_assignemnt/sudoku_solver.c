// write a C program to implement a Sudoku solver using backtracking algorithm. 
// The program should take a partially filled Sudoku grid as input and output the solved Sudoku grid.
#include <stdio.h>

#define N 9

// Function to print the Sudoku grid
void printSudoku(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check whether a number can be placed
// at a particular position
int isSafe(int grid[N][N], int row, int col, int num)
{
    // Check the row
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
            return 0;
    }

    // Check the column
    for (int x = 0; x < N; x++)
    {
        if (grid[x][col] == num)
            return 0;
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

// Backtracking function to solve Sudoku
int solveSudoku(int grid[N][N])
{
    int row, col;
    int emptyFound = 0;

    // Find an empty cell (represented by 0)
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                emptyFound = 1;
                break;
            }
        }

        if (emptyFound)
            break;
    }

    // No empty cell means Sudoku is solved
    if (!emptyFound)
        return 1;

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            // Make a choice
            grid[row][col] = num;

            // Recursively solve the remaining puzzle
            if (solveSudoku(grid))
                return 1;

            // Backtrack: undo the choice
            grid[row][col] = 0;
        }
    }

    // No valid number found
    return 0;
}

int main()
{
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku:\n");
    printSudoku(grid);

    if (solveSudoku(grid))
    {
        printf("\nSolved Sudoku:\n");
        printSudoku(grid);
    }
    else
    {
        printf("\nNo solution exists!\n");
    }

    return 0;
}


Original Sudoku:
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Solved Sudoku:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9