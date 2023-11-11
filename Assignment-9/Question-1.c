/*  Given an unsorted integer array, find a pair with the given sum in it. 
 */


#include <stdio.h>

void findPairWithSum(int arr[], int size, int targetSum) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found at index %d and %d (%d + %d = %d)\n", i, j, arr[i], arr[j], targetSum);
                return;
            }
        }
    }
    printf("Pair not found for the given sum\n");
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    findPairWithSum(arr, size, targetSum);
    return 0;
}







//python code
def find_pair_with_sum(arr, target_sum):
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == target_sum:
                return i, j, arr[i], arr[j], target_sum
    return None

arr = [8, 7, 2, 5, 3, 1]
target_sum = 10

result = find_pair_with_sum(arr, target_sum)
if result:
    i, j, val1, val2, total = result
    print(f"Pair found at index {i} and {j} ({val1} + {val2} = {total})")
else:
    print("Pair not found for the given sum")




//output
Pair found at index 0 and 2 (8 + 2 = 10)
