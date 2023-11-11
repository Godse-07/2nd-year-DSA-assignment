/* Check if a subarray with 0 sum exists or not. 
 */

#include <stdio.h>
#include <stdbool.h>

bool subArrayExists(int arr[], int size) {
    bool exists = false;
    int sum = 0;
    bool hashTable[100000] = {false}; // Assuming a maximum array size

    for (int i = 0; i < size; i++) {
        sum += arr[i];

        if (arr[i] == 0 || sum == 0 || hashTable[sum]) {
            exists = true;
            break;
        }

        hashTable[sum] = true;
    }

    return exists;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, size)) {
        printf("Subarray with 0 sum exists");
    } else {
        printf("Subarray with 0 sum does not exist");
    }

    return 0;
}







def subarray_exists(arr):
    exists = False
    sum = 0
    hash_table = set()

    for element in arr:
        sum += element

        if element == 0 or sum == 0 or sum in hash_table:
            exists = True
            break

        hash_table.add(sum)

    return exists

arr = [4, 2, -3, 1, 6]

if subarray_exists(arr):
    print("Subarray with 0 sum exists")
else:
    print("Subarray with 0 sum does not exist")





//output
Subarray with 0 sum exists
