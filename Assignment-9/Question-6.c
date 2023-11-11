/* Find the largest subarray formed by consecutive integers  */

#include <stdio.h>
#include <stdlib.h>

int maxSubarrayConsecutiveIntegers(int arr[], int size) {
    int maxLength = 0;
    int start = 0;
    int end = 0;

    int *hashTable = (int *)malloc(sizeof(int) * 100000); // Assuming a maximum array size
    for (int i = 0; i < 100000; i++) {
        hashTable[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        hashTable[arr[i]] = 1;
    }

    for (int i = 0; i < size; i++) {
        if (hashTable[arr[i]] == 1) {
            int count = 1;
            int j = arr[i];

            while (hashTable[j + 1] == 1) {
                count++;
                j++;
            }

            if (count > maxLength) {
                maxLength = count;
                start = arr[i];
                end = j;
            }
        }
    }

    if (maxLength > 1) {
        printf("Largest subarray formed by consecutive integers starts at %d and ends at %d\n", start, end);
    } else {
        printf("No subarray found with consecutive integers\n");
    }

    free(hashTable);
    return maxLength;
}

int main() {
    int arr[] = {2, 0, 2, 1, 4, 3, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxLength = maxSubarrayConsecutiveIntegers(arr, size);
    printf("Maximum length of subarray with consecutive integers is %d\n", maxLength);

    return 0;
}





def max_subarray_consecutive_integers(arr):
    max_length = 0
    start = 0
    end = 0
    hash_table = {num: 1 for num in arr}

    for i in range(len(arr)):
        if hash_table[arr[i]] == 1:
            count = 1
            j = arr[i]

            while j + 1 in hash_table and hash_table[j + 1] == 1:
                count += 1
                j += 1

            if count > max_length:
                max_length = count
                start = arr[i]
                end = j

    if max_length > 1:
        print(f"Largest subarray formed by consecutive integers starts at {start} and ends at {end}")
    else:
        print("No subarray found with consecutive integers")

    return max_length

arr = [2, 0, 2, 1, 4, 3, 1, 0]

max_len = max_subarray_consecutive_integers(arr)
print(f"Maximum length of subarray with consecutive integers is {max_len}")



//output
Largest subarray formed by consecutive integers starts at 0 and ends at 4
Maximum length of subarray with consecutive integers is 5
