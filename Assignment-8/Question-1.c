/* Write a program to implement linear search. */

#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}





/* python code */

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Element found, return its index
    return -1  # Element not found

arr = [12, 45, 67, 89, 34, 56]
target = 34

result = linear_search(arr, target)

if result != -1:
    print(f"Element found at index: {result}")
else:
    print("Element not found in the array")




/* oputput */
Element found at index: 4
