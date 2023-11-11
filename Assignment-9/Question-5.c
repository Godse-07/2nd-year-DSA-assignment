/* Find maximum length subarray having an equal number of 0’s and 1’s 
 */


#include <stdio.h>
#include <stdlib.h>

int maxLengthSubarrayWithEqualZerosOnes(int arr[], int size) {
    int maxLength = 0;
    int sum = 0;
    int start = 0;
    int end = -1;

    int *hashTable = (int *)malloc(sizeof(int) * 100000); // Assuming a maximum array size
    for (int i = 0; i < 100000; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        sum += (arr[i] == 0) ? -1 : 1;

        if (sum == 0) {
            maxLength = i + 1;
            end = i;
        } else if (hashTable[sum] != -1) {
            if (i - hashTable[sum] > maxLength) {
                maxLength = i - hashTable[sum];
                start = hashTable[sum] + 1;
                end = i;
            }
        }

        if (hashTable[sum] == -1) {
            hashTable[sum] = i;
        }
    }

    if (end != -1) {
        printf("Maximum length subarray with equal 0s and 1s starts at index %d and ends at index %d\n", start, end);
    } else {
        printf("No subarray found with equal 0s and 1s\n");
    }

    free(hashTable);
    return maxLength;
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxLength = maxLengthSubarrayWithEqualZerosOnes(arr, size);
    printf("Maximum length of subarray with equal 0s and 1s is %d\n", maxLength);

    return 0;
}






def max_length_subarray_equal_zeros_ones(arr):
    max_length = 0
    start = 0
    end = -1
    sum_indices = {0: -1}
    current_sum = 0

    for i in range(len(arr)):
        current_sum += -1 if arr[i] == 0 else 1

        if current_sum in sum_indices:
            if i - sum_indices[current_sum] > max_length:
                max_length = i - sum_indices[current_sum]
                start = sum_indices[current_sum] + 1
                end = i

        if current_sum not in sum_indices:
            sum_indices[current_sum] = i

    if end != -1:
        print(f"Maximum length subarray with equal 0s and 1s starts at index {start} and ends at index {end}")
    else:
        print("No subarray found with equal 0s and 1s")

    return max_length

arr = [0, 1, 1, 0, 1, 1, 1, 0]

max_len = max_length_subarray_equal_zeros_ones(arr)
print(f"Maximum length of subarray with equal 0s and 1s is {max_len}")



//output
Maximum length subarray with equal 0s and 1s starts at index 1 and ends at index 6
Maximum length of subarray with equal 0s and 1s is 6
