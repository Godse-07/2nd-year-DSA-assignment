/* Write a program to convert a decimal number into binary number using stack. */



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1; 
    } else {
        return stack->items[stack->top--];
    }
}

void decimalToBinary(int decimal) {
    struct Stack stack;
    initialize(&stack);

    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal < 0) {
        printf("Binary representation is not defined for negative numbers.\n");
    } else if (decimal == 0) {
        printf("Binary representation: 0\n");
    } else {
        decimalToBinary(decimal);
    }

    return 0;
}


/* Enter a decimal number: 10
Binary representation: 1010 */




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

def decimal_to_binary(decimal):
    if decimal < 0:
        return "Binary representation is not defined for negative numbers."
    elif decimal == 0:
        return "Binary representation: 0"

    stack = Stack()

    while decimal > 0:
        remainder = decimal % 2
        stack.push(remainder)
        decimal //= 2

    binary_representation = "Binary representation: "
    while not stack.is_empty():
        binary_representation += str(stack.pop())

    return binary_representation

decimal = int(input("Enter a decimal number: "))
binary_result = decimal_to_binary(decimal)
print(binary_result)
