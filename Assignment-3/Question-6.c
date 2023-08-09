/* Write a program to interchange different rows of a matrix */

#include <stdio.h>

#define ROWS 3
#define COLS 3

void interchangeRows(int matrix[ROWS][COLS], int row1, int row2)
{
    for (int j = 0; j < COLS; j++)
    {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

int main()
{
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    interchangeRows(matrix, 0, 2);

    printf("\nMatrix after interchanging rows 0 and 2:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/* Original Matrix:
 1  2  3 
 4  5  6 
 7  8  9 

Matrix after interchanging rows 0 and 2:
 7  8  9 
 4  5  6 
 1  2  3  */



 def interchange_rows(matrix, row1, row2):
    matrix[row1], matrix[row2] = matrix[row2], matrix[row1]

def display_matrix(matrix):
    for row in matrix:
        print(" ".join(str(num) for num in row))

if __name__ == "__main__":
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    print("Original Matrix:")
    display_matrix(matrix)


    interchange_rows(matrix, 0, 2)

    print("\nMatrix after interchanging rows 0 and 2:")
    display_matrix(matrix)
