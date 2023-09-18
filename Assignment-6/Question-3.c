/* Write a program to check whether number of opening ‘(‘ & closing ‘)’ parenthesis are
equal or not.  */



#include <stdio.h>
#include <string.h>

int main() {
    char expression[100];
    int openCount = 0, closeCount = 0;

    printf("Enter an expression: ");
    gets(expression);

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            openCount++;
        } else if (expression[i] == ')') {
            closeCount++;
        }
    }

    if (openCount == closeCount) {
        printf("The number of opening and closing parentheses are equal.\n");
    } else {
        printf("The number of opening and closing parentheses are not equal.\n");
    }

    return 0;
}




/* Enter an expression: (a + b) - (c * d)
The number of opening and closing parentheses are equal. */






def check_parentheses_balance(expression):
    open_count = expression.count('(')
    close_count = expression.count(')')

    if open_count == close_count:
        return "The number of opening and closing parentheses are equal."
    else:
        return "The number of opening and closing parentheses are not equal."

if __name__ == "__main__":
    expression = input("Enter an expression: ")
    result = check_parentheses_balance(expression)
    print(result)

