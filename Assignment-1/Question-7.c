/* Write a program to remove duplicate elements from array. 
 */

#include <stdio.h>

void removeDuplicates(int arr[], int *size) {
    int uniqueIndex = 1;

    for (int i = 1; i < *size; i++) {
        int isDuplicate = 0;

        for (int j = 0; j < uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            arr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
    }

    *size = uniqueIndex;
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

    removeDuplicates(arr, &size);

    printf("Array with duplicates removed: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



//python code

def remove_duplicates(array):
  

  new_array = []
  seen = set()
  for element in array:
    if element not in seen:
      new_array.append(element)
      seen.add(element)

  return new_array


def main():
 
  array = []
  for i in range(int(input("Enter the number of elements in the array: "))):
    element = int(input("Enter element {}: ".format(i + 1)))
    array.append(element)

 
  new_array = remove_duplicates(array)

  
  print("The new array without duplicate elements is:", new_array)


if __name__ == "__main__":
  main()
