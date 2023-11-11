/* Given an integer array, print all subarrays with zero-sum */


#include <stdio.h>
#include <stdbool.h>

void printAllSubarraysWithZeroSum(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += arr[j];
            if (sum == 0) {
                printf("Subarray [%d..%d]\n", i, j);
            }
        }
    }
}

int main() {
    int arr[] = {4, 2, -3, 1, 6, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Subarrays with zero sum:\n");
    printAllSubarraysWithZeroSum(arr, size);

    return 0;
}





def print_all_subarrays_with_zero_sum(arr):
    for i in range(len(arr)):
        sum = 0
        for j in range(i, len(arr)):
            sum += arr[j]
            if sum == 0:
                print(f"Subarray [{i}..{j}]")

arr = [4, 2, -3, 1, 6, -1]

print("Subarrays with zero sum:")
print_all_subarrays_with_zero_sum(arr)




//output
Subarrays with zero sum:
Subarray [2..3]
Subarray [0..2]
Subarray [3..5]
