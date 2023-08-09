/* . Write a program to check whether a string is palindrome or not. */


#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

   
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}



/* Enter a string: Godse
The string is not a palindrome. */


def is_palindrome(input_string):
    return input_string == input_string[::-1]

if __name__ == "__main__":
    input_string = input("Enter a string: ")

    if is_palindrome(input_string):
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")
