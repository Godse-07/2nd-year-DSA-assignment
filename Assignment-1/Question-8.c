/*  Write a program to find second highest from an array. (Do not use sorting) 
 */

#include <stdio.h>

int findSecondHighest(int arr[], int size) {
    int firstHighest = arr[0];
    int secondHighest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > firstHighest) {
            secondHighest = firstHighest;
            firstHighest = arr[i];
        } else if (arr[i] > secondHighest && arr[i] != firstHighest) {
            secondHighest = arr[i];
        }
    }

    return secondHighest;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int secondHighest = findSecondHighest(arr, size);

    printf("The second highest element in the array is: %d\n", secondHighest);

    return 0;
}



//python
def find_second_highest(arr):
    first_highest = arr[0]
    second_highest = arr[0]

    for num in arr[1:]:
        if num > first_highest:
            second_highest = first_highest
            first_highest = num
        elif num > second_highest and num != first_highest:
            second_highest = num

    return second_highest

def main():
    size = int(input("Enter the size of the array: "))
    arr = []

    print("Enter elements of the array:")
    for i in range(size):
        num = int(input())
        arr.append(num)

    second_highest = find_second_highest(arr)

    print("The second highest element in the array is:", second_highest)

if __name__ == "__main__":
    main()
