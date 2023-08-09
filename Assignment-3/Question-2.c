/* Write a program to store following numbers ( 1 to 9) in a matrix in spiral manner.  */

#include <stdio.h>

#define M 3
#define N 3

void fillSpiralMatrix(int matrix[M][N]) {
    int value = 1;
    int topRow = 0, bottomRow = M - 1, leftColumn = 0, rightColumn = N - 1;

    while (value <= M * N) {
        
        for (int i = leftColumn; i <= rightColumn; i++) {
            matrix[topRow][i] = value++;
        }
        topRow++;

        
        for (int i = topRow; i <= bottomRow; i++) {
            matrix[i][rightColumn] = value++;
        }
        rightColumn--;

       
        for (int i = rightColumn; i >= leftColumn; i--) {
            matrix[bottomRow][i] = value++;
        }
        bottomRow--;

        
        for (int i = bottomRow; i >= topRow; i--) {
            matrix[i][leftColumn] = value++;
        }
        leftColumn++;
    }
}

int main() {
    int matrix[M][N];
    fillSpiralMatrix(matrix);

    
    printf("Spiral Matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* 
Spiral Matrix:
 1  2  3 
 8  9  4 
 7  6  5  */







 def fill_spiral_matrix(matrix, M, N):
    value = 1
    top_row, bottom_row, left_column, right_column = 0, M - 1, 0, N - 1

    while value <= M * N:
        
        for i in range(left_column, right_column + 1):
            matrix[top_row][i] = value
            value += 1
        top_row += 1

       
        for i in range(top_row, bottom_row + 1):
            matrix[i][right_column] = value
            value += 1
        right_column -= 1

       
        for i in range(right_column, left_column - 1, -1):
            matrix[bottom_row][i] = value
            value += 1
        bottom_row -= 1

        
        for i in range(bottom_row, top_row - 1, -1):
            matrix[i][left_column] = value
            value += 1
        left_column += 1


def main():
    M, N = 3, 3
    matrix = [[0 for _ in range(N)] for _ in range(M)]
    fill_spiral_matrix(matrix, M, N)

   
    print("Spiral Matrix:")
    for row in matrix:
        print(" ".join(f"{num:2d}" for num in row))


if __name__ == "__main__":
    main()
