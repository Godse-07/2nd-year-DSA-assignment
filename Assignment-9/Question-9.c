/* Find the minimum index of a repeating element in an array 
 */

def min_index_of_repeating_element(arr):
    index_map = {}

    min_index = len(arr)  # Initialize with maximum possible index

    for i, num in enumerate(arr):
        if num in index_map:
            min_index = min(min_index, index_map[num])
        else:
            index_map[num] = i

    return min_index if min_index != len(arr) else -1

arr = [4, 5, 6, 4, 5, 7, 8]
min_index = min_index_of_repeating_element(arr)

print(f"The minimum index of a repeating element is: {min_index}")





#include <stdio.h>
#include <stdlib.h>

int minIndexOfRepeatingElement(int arr[], int size) {
    int minIndex = size; // Initialize with maximum possible index
    int *indexMap = (int *)malloc(sizeof(int) * 10000); // Assuming maximum possible size

    for (int i = 0; i < 10000; i++) {
        indexMap[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        if (indexMap[arr[i]] != -1) {
            minIndex = (minIndex < indexMap[arr[i]]) ? minIndex : indexMap[arr[i]];
        } else {
            indexMap[arr[i]] = i;
        }
    }

    free(indexMap);
    return (minIndex != size) ? minIndex : -1;
}

int main() {
    int arr[] = {4, 5, 6, 4, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int minIndex = minIndexOfRepeatingElement(arr, size);

    printf("The minimum index of a repeating element is: %d\n", minIndex);
    
    return 0;
}



//output
The minimum index of a repeating element is: 3
