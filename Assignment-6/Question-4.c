/* Write a program to convert infix expression to postfix expression */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char peek(struct Stack *stack) {
    return stack->items[stack->top];
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
        return '\0'; // Return null character for empty stack
    } else {
        return stack->items[stack->top--];
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char *infix) {
    struct Stack stack;
    initialize(&stack);

    char postfix[MAX_SIZE];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(c) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}





/* Enter an infix expression: (a+b)*c-d/e
Postfix expression: ab+c*de/- */





class Stack:
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0
    
    def peek(self):
        if not self.is_empty():
            return self.items[-1]
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

def infix_to_postfix(infix):
    precedence = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2,
    }

    stack = Stack()
    postfix = []
    
    for char in infix:
        if char.isalnum():
            postfix.append(char)
        elif char == '(':
            stack.push(char)
        elif char == ')':
            while not stack.is_empty() and stack.peek() != '(':
                postfix.append(stack.pop())
            if not stack.is_empty() and stack.peek() != '(':
                return "Invalid expression"
            else:
                stack.pop()
        else:
            while not stack.is_empty() and precedence.get(char, 0) <= precedence.get(stack.peek(), 0):
                postfix.append(stack.pop())
            stack.push(char)
    
    while not stack.is_empty():
        postfix.append(stack.pop())
    
    return ''.join(postfix)

if __name__ == "__main__":
    infix_expression = input("Enter an infix expression: ")
    postfix_expression = infix_to_postfix(infix_expression)
    print("Postfix expression:", postfix_expression)

