/* Write a program to delete an element from array. 
 */


#include <stdio.h>

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position. Deletion not possible.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {
    int size, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete (0-indexed): ");
    scanf("%d", &position);

    deleteElement(arr, &size, position);

    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



//python code

def delete_element_at_position(array, position):
  
  new_array = array[:position] + array[position + 1:]
  return new_array


def main():
  
  array = []
  for i in range(int(input("Enter the number of elements in the array: "))):
    element = int(input("Enter element {}: ".format(i + 1)))
    array.append(element)

  
  position = int(input("Enter the position of the element to delete: "))

  
  new_array = delete_element_at_position(array, position)

 
  print("The new array after deleting the element at position {} is: {}".format(
      position, new_array))


if __name__ == "__main__":
  main()
