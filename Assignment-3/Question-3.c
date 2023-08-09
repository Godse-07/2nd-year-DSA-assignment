/* Rotate a given matrix in 90 (degree) */

#include <stdio.h>

#define N 4

void rotateMatrix(int mat[N][N]) {
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            
            int temp = mat[i][j];
            mat[i][j] = mat[i][N - 1 - j];
            mat[i][N - 1 - j] = temp;
        }
    }
}

void displayMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    displayMatrix(mat);

    rotateMatrix(mat);

    printf("\nRotated Matrix (90 degrees):\n");
    displayMatrix(mat);

    return 0;
}


/* Original Matrix:
1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      16

Rotated Matrix (90 degrees):
13      9       5       1
14      10      6       2
15      11      7       3
16      12      8       4 */




def rotate_matrix(mat):
    N = len(mat)

    
    for i in range(N):
        for j in range(i + 1, N):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

    
    for i in range(N):
        mat[i] = mat[i][::-1]


def display_matrix(mat):
    for row in mat:
        print(*row)


if __name__ == "__main__":
    mat = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    print("Original Matrix:")
    display_matrix(mat)

    rotate_matrix(mat)

    print("\nRotated Matrix (90 degrees clockwise):")
    display_matrix(mat)
