/* Write a program to merge two sorted array of length M & N. [M & N may not be
equal] */

#include <stdio.h>

void mergeArrays(int arr1[], int m, int arr2[], int n, int merged[]) {
    int i = 0; 
    int j = 0;
    int k = 0; 

    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    
    while (i < m) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

   
    while (j < n) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int m, n;

    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter elements of the first sorted array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter elements of the second sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[m + n]; 

    mergeArrays(arr1, m, arr2, n, merged);

    printf("Merged Array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}




//python code


def merge_sorted_arrays(arr1, arr2):
  

  merged_array = []
  i = 0
  j = 0
  while i < len(arr1) and j < len(arr2):
    if arr1[i] <= arr2[j]:
      merged_array.append(arr1[i])
      i += 1
    else:
      merged_array.append(arr2[j])
      j += 1

  merged_array += arr1[i:]
  merged_array += arr2[j:]

  return merged_array


def main():
  
  m = int(input("Enter the length of the first array: "))
  n = int(input("Enter the length of the second array: "))

 
  arr1 = []
  arr2 = []
  for i in range(m):
    element = int(input("Enter element {} of the first array: ".format(i + 1)))
    arr1.append(element)
  for i in range(n):
    element = int(input("Enter element {} of the second array: ".format(i + 1)))
    arr2.append(element)

  
  merged_array = merge_sorted_arrays(arr1, arr2)
  print(merged_array)


if __name__ == "__main__":
  main()
