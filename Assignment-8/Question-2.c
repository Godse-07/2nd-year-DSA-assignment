/* Write a program to implement binary search.  */


#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {12, 34, 45, 56, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}





/* python code */

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid  # Element found, return its index

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # Element not found

arr = [12, 34, 45, 56, 67, 89]
target = 34

result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index: {result}")
else:
    print("Element not found in the array")




/* output */
Element found at index: 1
