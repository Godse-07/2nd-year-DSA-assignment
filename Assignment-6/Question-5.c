/* Write a program to evaluate a postfix expression.  */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int peek(struct Stack *stack) {
    return stack->items[stack->top];
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
        return -1; // Return an error value for empty stack
    } else {
        return stack->items[stack->top--];
    }
}

int evaluatePostfix(char *postfix) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(&stack, c - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (c) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1; // Return an error value for invalid operator
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}






/* Enter a postfix expression: 23*5+
Result: 11 */






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

def evaluate_postfix(postfix):
    stack = Stack()
    
    for char in postfix:
        if char.isdigit():
            stack.push(int(char))
        else:
            operand2 = stack.pop()
            operand1 = stack.pop()
            
            if char == '+':
                stack.push(operand1 + operand2)
            elif char == '-':
                stack.push(operand1 - operand2)
            elif char == '*':
                stack.push(operand1 * operand2)
            elif char == '/':
                stack.push(operand1 / operand2)
            else:
                print(f"Invalid operator: {char}")
                return None
    
    return stack.pop()

if __name__ == "__main__":
    postfix_expression = input("Enter a postfix expression: ")
    result = evaluate_postfix(postfix_expression)
    
    if result is not None:
        print("Result:", result)

