/* . Write a program to search a number occurring odd number of times.  */


#include <stdio.h>

int findOddOccurrence(int arr[], int n) {
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    
    return result;
}

int main() {
    int arr[] = {4, 3, 4, 2, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int oddNumber = findOddOccurrence(arr, n);

    printf("The number occurring an odd number of times is: %d\n", oddNumber);

    return 0;
}
            



/* python code */

def find_odd_occurrence(arr):
    result = 0
    
    for num in arr:
        result ^= num
        
    return result

arr = [4, 3, 4, 2, 2, 3, 4]

odd_number = find_odd_occurrence(arr)

print(f"The number occurring an odd number of times is: {odd_number}")



/* output */
The number occurring an odd number of times is: 4
