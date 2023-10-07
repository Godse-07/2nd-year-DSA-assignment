/* Write a program to find three elements in the array such that their sum is equal to given
element K.  */


def find_triplets_with_sum(arr, K):
    arr.sort()  # Sort the array in ascending order
    triplets = []

    for i in range(len(arr) - 2):
        left, right = i + 1, len(arr) - 1

        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]

            if current_sum == K:
                triplets.append([arr[i], arr[left], arr[right]])
                left += 1
                right -= 1
            elif current_sum < K:
                left += 1
            else:
                right -= 1

    return triplets

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
K = 15

triplets = find_triplets_with_sum(arr, K)

if triplets:
    for triplet in triplets:
        print(triplet)
else:
    print("No triplet found with the given sum.")









/* c code */

#include <stdio.h>
#include <stdlib.h>

void findTriplets(int arr[], int n, int K) {
    int i, j, k;
    int found = 0;

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == K) {
                    printf("Triplets with sum %d: %d, %d, %d\n", K, arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No triplets found with sum %d\n", K);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 15;

    findTriplets(arr, n, K);

    return 0;
}




/* output */

Triplets with sum 15: 1, 5, 9
Triplets with sum 15: 2, 4, 9
Triplets with sum 15: 2, 5, 8
Triplets with sum 15: 3, 4, 8
Triplets with sum 15: 3, 5, 7
