/* Write a program to check whether a matrix is sparse or not. */


#include <stdio.h>

#define ROWS 3
#define COLS 3

int isSparseMatrix(int matrix[ROWS][COLS]) {
    int zeroCount = 0;
    int totalCount = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    return (zeroCount > totalCount / 2);
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 3}
    };

    if (isSparseMatrix(matrix)) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}


/* The matrix is sparse. */


def is_sparse_matrix(matrix):
    zero_count = 0
    total_count = len(matrix) * len(matrix[0])

    for row in matrix:
        zero_count += row.count(0)

    return zero_count > total_count / 2

if __name__ == "__main__":
    matrix = [
        [1, 0, 0],
        [0, 2, 0],
        [0, 0, 3]
    ]

    if is_sparse_matrix(matrix):
        print("The matrix is sparse.")
    else:
        print("The matrix is not sparse.")
