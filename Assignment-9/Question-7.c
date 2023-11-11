/* Find pairs with difference in an array 
 */


#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findPairsWithDifference(int arr[], int size, int difference) {
    qsort(arr, size, sizeof(int), compare);
    int left = 0;
    int right = 1;

    while (right < size) {
        int currentDiff = arr[right] - arr[left];

        if (currentDiff == difference) {
            printf("Pair found: %d, %d\n", arr[left], arr[right]);
            left++;
            right++;
        } else if (currentDiff > difference) {
            left++;
        } else {
            right++;
        }
    }
}

int main() {
    int arr[] = {4, 1, 5, 3, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int difference = 2;

    printf("Pairs with a difference of %d:\n", difference);
    findPairsWithDifference(arr, size, difference);

    return 0;
}





def find_pairs_with_difference(arr, difference):
    pair_set = set()

    for num in arr:
        if num - difference in pair_set:
            print(f"Pair found: {num - difference}, {num}")
        if num + difference in pair_set:
            print(f"Pair found: {num}, {num + difference}")

        pair_set.add(num)

arr = [4, 1, 5, 3, 8, 6]
difference = 2

print(f"Pairs with a difference of {difference}:")
find_pairs_with_difference(arr, difference)



//output
Pairs with a difference of 2:
Pair found: 1, 3
Pair found: 3, 5
Pair found: 5, 3
Pair found: 6, 8
