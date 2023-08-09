/* . Write a program to reverse a string.  */


#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

   
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}


/* Enter a string: Godse
Reversed string: esdoG */



def reverse_string(input_string):
    return input_string[::-1]

if __name__ == "__main__":
    input_string = input("Enter a string: ")
    reversed_string = reverse_string(input_string)
    print("Reversed string:", reversed_string)
