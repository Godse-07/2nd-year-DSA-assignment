/* Sort elements by their frequency and index  */



from collections import Counter

def sort_elements_by_frequency_and_index(arr):
    # Count the frequency of each element
    count = Counter(arr)

    # Custom sorting function considering both frequency and index
    def custom_sort(elem):
        return (-count[elem], arr.index(elem))

    # Sort the array based on the custom sorting function
    arr.sort(key=custom_sort)

    return arr

arr = [4, 5, 6, 4, 5, 7, 8, 5, 6]
sorted_arr = sort_elements_by_frequency_and_index(arr)

print("Sorted elements by frequency and index:")
print(sorted_arr)







#include <stdio.h>
#include <stdlib.h>

// Structure to hold the element, its frequency, and original index
typedef struct {
    int value;
    int frequency;
    int index;
} Element;

// Compare function for sorting the array of elements
int compare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;

    // Sort by frequency in descending order
    if (elem1->frequency != elem2->frequency) {
        return elem2->frequency - elem1->frequency;
    }

    // If frequency is the same, sort by index in ascending order
    return elem1->index - elem2->index;
}

int *sortElementsByFrequencyAndIndex(int arr[], int size) {
    Element elements[size];

    // Initialize elements with values, frequencies, and indices
    for (int i = 0; i < size; i++) {
        elements[i].value = arr[i];
        elements[i].frequency = 0;
        elements[i].index = i;
    }

    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        elements[arr[i]].frequency++;
    }

    // Sort the array of elements using the custom compare function
    qsort(elements, size, sizeof(Element), compare);

    // Rearrange the array based on the sorted elements
    int *sortedArr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        sortedArr[i] = elements[i].value;
    }

    return sortedArr;
}

int main() {
    int arr[] = {4, 5, 6, 4, 5, 7, 8, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *sortedArr = sortElementsByFrequencyAndIndex(arr, size);

    printf("Sorted elements by frequency and index:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    free(sortedArr);
    return 0;
}






//output
Sorted elements by frequency and index:
5 5 5 4 4 6 6 7 8 

