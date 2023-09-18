/*   Write a program to reverse a string using stack.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

void reverseString(char *str) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    printf("Reversed String: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    gets(str);

    reverseString(str);

    return 0;
}





/* Enter a string: Hello, World!
Reversed String: !dlroW ,olleH */




class Stack:
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if not self.is_empty():
            return self.items.pop()

def reverse_string(input_string):
    stack = Stack()
    
    for char in input_string:
        stack.push(char)
    
    reversed_string = ""
    while not stack.is_empty():
        reversed_string += stack.pop()
    
    return reversed_string

input_string = input("Enter a string: ")
reversed_result = reverse_string(input_string)
print("Reversed String:", reversed_result)




/* Enter a string: Hello, World!
Reversed String: !dlroW ,olleH */

