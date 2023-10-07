/* Write a program to implement interpolation search */


#include <stdio.h>

int interpolationSearch(int arr[], int n, int target) {
    int left = 0, right = (n - 1);

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target) {
            return pos; 
        }

        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {12, 34, 45, 56, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;

    int result = interpolationSearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}




/* python code */

def interpolation_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right and target >= arr[left] and target <= arr[right]:

        pos = left + ((target - arr[left]) * (right - left)) // (arr[right] - arr[left])

        if arr[pos] == target:
            return pos  

        if arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1

    return -1 

arr = [12, 34, 45, 56, 67, 89]
target = 34

result = interpolation_search(arr, target)

if result != -1:
    print(f"Element found at index: {result}")
else:
    print("Element not found in the array")




/* output */

Element found at index: 1
