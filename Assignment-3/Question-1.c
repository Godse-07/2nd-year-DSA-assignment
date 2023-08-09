/* Write a program to print the sum of the diagonal element of the M*N square
matrix.
 */

#include <stdio.h>

int main()
{
    int M, N;
    printf("Enter the number of rows and columns (M N) of the square matrix: ");
    scanf("%d %d", &M, &N);

    if (M != N)
    {
        printf("Error: The matrix is not square (M != N).\n");
        return 1;
    }

    int matrix[M][N];
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sumDiagonal = 0;
    for (int i = 0; i < M; i++)
    {
        sumDiagonal += matrix[i][i];
    }

    printf("Sum of diagonal elements: %d\n", sumDiagonal);

    return 0;
}


/* 
Enter the number of rows and columns (M N) of the square matrix: 3
3
Enter the elements of the matrix:
1
2
3
4
5
6
7
8
9
Sum of diagonal elements: 15 */


def solve(matrix):
   m = len(matrix)
   if m == 1: return matrix[0][0]

   count = 0
   for i in range(m):
      count += matrix[i][i]
      count += matrix[i][-1 - i]

   if m % 2 == 1: count -= matrix[m // 2][m // 2]

   return count

matrix = [[10,5,9,6],[8,15,3,2],[3,8,12,3],[2,11,7,3],]
print(solve(matrix))

/*    59    */