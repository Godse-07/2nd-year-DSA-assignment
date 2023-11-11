/* Given an integer array, find the maximum length subarray having a given sum.  */

#include <stdio.h>
#include <stdlib.h>

int maxLengthSubarrayWithGivenSum(int arr[], int size, int targetSum) {
    int maxLength = 0;
    int sum = 0;
    int start = 0;
    int end = -1;

    int *hashTable = (int *)malloc(sizeof(int) * 100000); // Assuming a maximum array size
    for (int i = 0; i < 100000; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];

        if (sum == targetSum) {
            maxLength = i + 1;
            end = i;
        } else if (hashTable[sum - targetSum] != -1) {
            if (i - hashTable[sum - targetSum] > maxLength) {
                maxLength = i - hashTable[sum - targetSum];
                start = hashTable[sum - targetSum] + 1;
                end = i;
            }
        }

        if (hashTable[sum] == -1) {
            hashTable[sum] = i;
        }
    }

    if (end != -1) {
        printf("Maximum length subarray with sum %d starts at index %d and ends at index %d\n", targetSum, start, end);
    } else {
        printf("No subarray found with the given sum\n");
    }

    free(hashTable);
    return maxLength;
}

int main() {
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 8;

    int maxLength = maxLengthSubarrayWithGivenSum(arr, size, targetSum);
    printf("Maximum length of subarray with sum %d is %d\n", targetSum, maxLength);

    return 0;
}






def max_length_subarray_with_given_sum(arr, target_sum):
    max_length = 0
    start = 0
    end = -1
    sum_indices = {0: -1}
    current_sum = 0

    for i in range(len(arr)):
        current_sum += arr[i]

        if current_sum - target_sum in sum_indices:
            if i - sum_indices[current_sum - target_sum] > max_length:
                max_length = i - sum_indices[current_sum - target_sum]
                start = sum_indices[current_sum - target_sum] + 1
                end = i

        if current_sum not in sum_indices:
            sum_indices[current_sum] = i

    if end != -1:
        print(f"Maximum length subarray with sum {target_sum} starts at index {start} and ends at index {end}")
    else:
        print("No subarray found with the given sum")

    return max_length

arr = [5, 6, -5, 5, 3, 5, 3, -2, 0]
target_sum = 8

max_len = max_length_subarray_with_given_sum(arr, target_sum)
print(f"Maximum length of subarray with sum {target_sum} is {max_len}")




//output
Maximum length subarray with sum 8 starts at index 2 and ends at index 5
Maximum length of subarray with sum 8 is 4
