/* Write a program to insert a new element in array at given location k */

#include <stdio.h>

void insertElement(int arr[], int *size, int k, int element) {
    if (k < 0 || k > *size) {
        printf("Invalid location. Insertion not possible.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size - 1; i >= k; i--) {
        arr[i + 1] = arr[i];
    }

    arr[k] = element;
    (*size)++;
}

int main() {
    int size, k, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert the element (0-indexed): ");
    scanf("%d", &k);

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    insertElement(arr, &size, k, element);

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



//python code
def insert_element(arr, k, element):
    arr.insert(k, element)

def main():
    size = int(input("Enter the size of the array: "))
    arr = []

    print("Enter elements of the array:")
    for i in range(size):
        num = int(input())
        arr.append(num)

    k = int(input("Enter the position to insert the element (0-indexed): "))
    element = int(input("Enter the element to be inserted: "))

    insert_element(arr, k, element)

    print("Array after insertion:", arr)

if __name__ == "__main__":
    main()
