/* Given a square matrix, print the maximum length snake sequence in it. A snake
sequence is defined as a sequence of numbers where each new number, which can
only be located to the right or down of the current number, is either plus or minus one.

For example, we can either move right from any cell in the matrix (if that number is ±1 ) or
move down (if that number is ±1 ). The problem is finding the longest path (snake sequence)
through the matrix, keeping in mind that we can only move to a new cell whose value
is concerning the current cell.

For example, the maximum length snake sequence of the following matrix is  5 —> 4 — >5
— > 6 — >7 —> 8 —> 7 —> 6
as highlighted below:   */



#include <stdio.h>

#define N 4

int max(int a, int b) {
    return a > b ? a : b;
}

int snakeSequence(int matrix[N][N]) {
    int dp[N][N];
    int maxLength = 1;

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1;
        }
    }

   
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            if (matrix[i][j] == matrix[i + 1][j] + 1 || matrix[i][j] == matrix[i + 1][j] - 1) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
            }
            if (matrix[i][j] == matrix[i][j + 1] + 1 || matrix[i][j] == matrix[i][j + 1] - 1) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
            }
            maxLength = max(maxLength, dp[i][j]);
        }
    }

    return maxLength;
}

int main() {
    int matrix[N][N] = {
        {9, 6, 5, 2},
        {8, 7, 6, 5},
        {7, 3, 1, 6},
        {1, 1, 1, 7}
    };

    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int maxLength = snakeSequence(matrix);
    printf("\nMaximum length snake sequence: %d\n", maxLength);

    return 0;
}



/* Matrix:
9 6 5 2 
8 7 6 5 
7 3 1 6 
1 1 1 7 

Maximum length snake sequence: 5 */



def max_snake_sequence(matrix):
    N = len(matrix)
    dp = [[1 for _ in range(N)] for _ in range(N)]
    max_length = 1

    for i in range(N - 2, -1, -1):
        for j in range(N - 2, -1, -1):
            if matrix[i][j] == matrix[i + 1][j] + 1 or matrix[i][j] == matrix[i + 1][j] - 1:
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1)
            if matrix[i][j] == matrix[i][j + 1] + 1 or matrix[i][j] == matrix[i][j + 1] - 1:
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1)
            max_length = max(max_length, dp[i][j])

    return max_length

if __name__ == "__main__":
    matrix = [
        [9, 6, 5, 2],
        [8, 7, 6, 5],
        [7, 3, 1, 6],
        [1, 1, 1, 7]
    ]

    print("Matrix:")
    for row in matrix:
        print(" ".join(str(num) for num in row))

    max_length = max_snake_sequence(matrix)
    print("\nMaximum length snake sequence:", max_length)
