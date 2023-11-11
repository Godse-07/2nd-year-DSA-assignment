/* Group elements of an array based on their first occurrence 
 */


def group_elements_by_first_occurrence(arr):
    first_occurrence = {}
    grouped_elements = {}

    for idx, val in enumerate(arr):
        if val not in first_occurrence:
            first_occurrence[val] = idx

        if val not in grouped_elements:
            grouped_elements[val] = [val]
        else:
            grouped_elements[val].append(val)

    result = []
    for val, indices in grouped_elements.items():
        first_index = first_occurrence[val]
        result.append(arr[first_index:first_index + len(indices)])

    return result

arr = [4, 5, 6, 4, 5, 7, 8]
grouped = group_elements_by_first_occurrence(arr)
print("Grouped elements based on their first occurrence:")
print(grouped)



#include <stdio.h>
#include <stdlib.h>

void groupElementsByFirstOccurrence(int arr[], int size) {
    int *firstOccurrence = (int *)malloc(sizeof(int) * 10000); // Assuming maximum possible size
    int *groupedElements = (int *)malloc(sizeof(int) * 10000); // Assuming maximum possible size
    int *groupedIndices = (int *)malloc(sizeof(int) * 10000); // Assuming maximum possible size

    for (int i = 0; i < 10000; i++) {
        firstOccurrence[i] = -1;
        groupedElements[i] = -1;
        groupedIndices[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        if (firstOccurrence[arr[i]] == -1) {
            firstOccurrence[arr[i]] = i;
            groupedElements[arr[i]] = arr[i];
            groupedIndices[arr[i]] = i;
        } else {
            int start = firstOccurrence[arr[i]];
            int end = groupedIndices[arr[i]];

            for (int j = start; j <= end; j++) {
                if (groupedIndices[arr[j]] == -1) {
                    groupedIndices[arr[j]] = end + 1;
                    groupedElements[end + 1] = arr[j];
                    end++;
                }
            }
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (groupedElements[i] != -1) {
            if (groupedIndices[groupedElements[i]] != -1) {
                int start = firstOccurrence[groupedElements[i]];
                int end = groupedIndices[groupedElements[i]];
                printf("[ ");
                for (int j = start; j <= end; j++) {
                    printf("%d ", arr[j]);
                }
                printf("]\n");
            }
        }
    }

    free(firstOccurrence);
    free(groupedElements);
    free(groupedIndices);
}

int main() {
    int arr[] = {4, 5, 6, 4, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Grouped elements based on their first occurrence:\n");
    groupElementsByFirstOccurrence(arr, size);

    return 0;
}



//output
Grouped elements based on their first occurrence:
[ 4 4 ]
[ 5 5 ]
[ 6 ]
[ 7 ]
[ 8 ]
