/* Write a program to implement stack using array.  */


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", item);
    } else {
        stack->arr[++stack->top] = item;
        printf("Pushed %d onto the stack\n", item);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    } else {
        int item = stack->arr[stack->top--];
        printf("Popped %d from the stack\n", item);
        return item;
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    int popped_item = pop(&stack);
    printf("Popped item: %d\n", popped_item);

    return 0;
}




/* Pushed 10 onto the stack
Pushed 20 onto the stack
Pushed 30 onto the stack
Popped 30 from the stack
Popped item: 30 */







class Stack:
    def __init__(self):
        self.stack = []
    
    def is_empty(self):
        return len(self.stack) == 0
    
    def push(self, item):
        self.stack.append(item)
        print(f"Pushed {item} onto the stack")
    
    def pop(self):
        if self.is_empty():
            print("Stack underflow, cannot pop")
            return None
        else:
            item = self.stack.pop()
            print(f"Popped {item} from the stack")
            return item

if __name__ == "__main__":
    stack = Stack()

    stack.push(10)
    stack.push(20)
    stack.push(30)

    popped_item = stack.pop()
    print(f"Popped item: {popped_item}")
