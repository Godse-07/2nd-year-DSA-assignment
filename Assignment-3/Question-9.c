/*  Write a program to print abbreviation of a given word. (1st letter of each word)  */


#include <stdio.h>
#include <ctype.h>
#include<string.h>

void printAbbreviation(const char *word) {
    if (word == NULL || *word == '\0') {
        printf("Invalid input.\n");
        return;
    }

    printf("%c", toupper(word[0]));

    while (*word != '\0') {
        if (*word == ' ') {
            printf("%c", toupper(word[1]));
        }
        word++;
    }

    printf("\n");
}

int main() {
    char word[100];

    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);

    // Remove the newline character from the input
    word[strcspn(word, "\n")] = '\0';

    printAbbreviation(word);

    return 0;
}



/* Enter a word: Godse
G */




def print_abbreviation(word):
    if not word:
        print("Invalid input.")
        return

    words = word.split()
    abbreviation = "".join(word[0].upper() for word in words)

    print(abbreviation)

if __name__ == "__main__":
    word = input("Enter a word: ")
    print_abbreviation(word)
