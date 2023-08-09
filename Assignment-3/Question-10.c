/* Write a program to implement searching and sorting in a given list of words.  */


#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 50


int linear_search(char words[MAX_WORDS][MAX_WORD_LENGTH], int n, char target[MAX_WORD_LENGTH]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i], target) == 0) {
            return i;
        }
    }
    return -1;
}


void selection_sort(char words[MAX_WORDS][MAX_WORD_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(words[j], words[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            char temp[MAX_WORD_LENGTH];
            strcpy(temp, words[i]);
            strcpy(words[i], words[min_index]);
            strcpy(words[min_index], temp);
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int n;

    printf("Enter the number of words (up to %d): ", MAX_WORDS);
    scanf("%d", &n);
    getchar(); 

    printf("Enter the words:\n");
    for (int i = 0; i < n; i++) {
        fgets(words[i], MAX_WORD_LENGTH, stdin);
        words[i][strcspn(words[i], "\n")] = '\0'; 
    }

    
    selection_sort(words, n);

    printf("\nSorted words:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    
    char target[MAX_WORD_LENGTH];
    printf("\nEnter the word to search: ");
    fgets(target, MAX_WORD_LENGTH, stdin);
    target[strcspn(target, "\n")] = '\0'; 

    int result = linear_search(words, n, target);
    if (result != -1) {
        printf("The word is found at index: %d\n", result);
    } else {
        printf("The word is not found.\n");
    }

    return 0;
}



/* Enter the number of words (up to 10): 5
Enter the words:
apple
banana
orange
grape
kiwi

Enter the word to search: orange
Sorted words:
apple
banana
grape
kiwi
orange
The word is found at index: 4 */




def linear_search(words, target):
    for i, word in enumerate(words):
        if word == target:
            return i
    return -1

def selection_sort(words):
    for i in range(len(words) - 1):
        min_index = i
        for j in range(i + 1, len(words)):
            if words[j] < words[min_index]:
                min_index = j
        if min_index != i:
            words[i], words[min_index] = words[min_index], words[i]

if __name__ == "__main__":
    words = []
    n = int(input("Enter the number of words: "))

    print("Enter the words:")
    for i in range(n):
        word = input()
        words.append(word)

    # Perform sorting
    selection_sort(words)

    print("\nSorted words:")
    for word in words:
        print(word)

    # Perform searching
    target = input("\nEnter the word to search: ")
    result = linear_search(words, target)

    if result != -1:
        print("The word is found at index:", result)
    else:
        print("The word is not found.")

