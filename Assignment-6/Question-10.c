/* Write a program to implement multiple stacks in a single array.  */



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_STACKS 3

struct MultiStack {
    int array[MAX_SIZE];
    int top[NUM_STACKS];
    int stackSize;
};

void initialize(struct MultiStack *stack, int stackSize) {
    stack->stackSize = stackSize;

    for (int i = 0; i < NUM_STACKS; i++) {
        stack->top[i] = -1;
    }
}

int isFull(struct MultiStack *stack, int stackNum) {
    return (stack->top[stackNum] == (stackNum + 1) * stack->stackSize - 1);
}

int isEmpty(struct MultiStack *stack, int stackNum) {
    return (stack->top[stackNum] == -1);
}

void push(struct MultiStack *stack, int stackNum, int data) {
    if (isFull(stack, stackNum)) {
        printf("Stack %d is full. Cannot push.\n", stackNum);
    } else {
        stack->array[++stack->top[stackNum]] = data;
    }
}

int pop(struct MultiStack *stack, int stackNum) {
    if (isEmpty(stack, stackNum)) {
        printf("Stack %d is empty. Cannot pop.\n", stackNum);
        return -1;
    } else {
        return stack->array[stack->top[stackNum]--];
    }
}

int main() {
    struct MultiStack stack;
    int stackSize = MAX_SIZE / NUM_STACKS;

    initialize(&stack, stackSize);

    push(&stack, 0, 1);
    push(&stack, 0, 2);
    push(&stack, 1, 3);
    push(&stack, 2, 4);
    push(&stack, 1, 5);

    printf("Popped from Stack 0: %d\n", pop(&stack, 0));
    printf("Popped from Stack 1: %d\n", pop(&stack, 1));
    printf("Popped from Stack 2: %d\n", pop(&stack, 2));

    return 0;
}




/* Popped from Stack 0: 2
Popped from Stack 1: 5
Popped from Stack 2: 4
 */




class MultiStack:
    def __init__(self, num_stacks, stack_size):
        self.num_stacks = num_stacks
        self.stack_size = stack_size
        self.array = [None] * (num_stacks * stack_size)
        self.top = [-1] * num_stacks

    def is_full(self, stack_num):
        return self.top[stack_num] == (stack_num + 1) * self.stack_size - 1

    def is_empty(self, stack_num):
        return self.top[stack_num] == -1

    def push(self, stack_num, data):
        if self.is_full(stack_num):
            print(f"Stack {stack_num} is full. Cannot push.")
        else:
            self.top[stack_num] += 1
            self.array[self.top[stack_num] + stack_num * self.stack_size] = data

    def pop(self, stack_num):
        if self.is_empty(stack_num):
            print(f"Stack {stack_num} is empty. Cannot pop.")
            return None
        else:
            data = self.array[self.top[stack_num] + stack_num * self.stack_size]
            self.top[stack_num] -= 1
            return data

if __name__ == "__main__":
    num_stacks = 3
    stack_size = 5
    stack = MultiStack(num_stacks, stack_size)

    stack.push(0, 1)
    stack.push(0, 2)
    stack.push(1, 3)
    stack.push(2, 4)
    stack.push(1, 5)

    print("Popped from Stack 0:", stack.pop(0))
    print("Popped from Stack 1:", stack.pop(1))
    print("Popped from Stack 2:", stack.pop(2))




/* Popped from Stack 0: 2
Popped from Stack 1: 5
Popped from Stack 2: 4
 .gitignore*/