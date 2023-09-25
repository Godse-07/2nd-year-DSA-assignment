/* Write a program to implement a queue using stack.  */



#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for a stack
struct Stack {
    struct StackNode* top;
};

// Create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Check if a stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Push an element onto a stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from a stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Structure for a queue using two stacks
struct QueueUsingStacks {
    struct Stack* stack1; // For enqueue
    struct Stack* stack2; // For dequeue
};

// Initialize a queue using two stacks
struct QueueUsingStacks* createQueue() {
    struct QueueUsingStacks* queue = (struct QueueUsingStacks*)malloc(sizeof(struct QueueUsingStacks));
    if (queue == NULL) {
        return NULL;
    }
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

// Enqueue an element into the queue
void enqueue(struct QueueUsingStacks* queue, int data) {
    push(queue->stack1, data);
}

// Dequeue an element from the queue
int dequeue(struct QueueUsingStacks* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        return -1;
    }
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main() {
    struct QueueUsingStacks* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    enqueue(queue, 40);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    return 0;
}






/* python code */

class Stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None

class QueueUsingStacks:
    def __init__(self):
        self.stack1 = Stack()  # For enqueue
        self.stack2 = Stack()  # For dequeue

    def enqueue(self, item):
        self.stack1.push(item)

    def dequeue(self):
        if self.is_empty():
            return None
        if self.stack2.is_empty():
            while not self.stack1.is_empty():
                self.stack2.push(self.stack1.pop())
        return self.stack2.pop()

    def is_empty(self):
        return self.stack1.is_empty() and self.stack2.is_empty()

if __name__ == "__main__":
    queue = QueueUsingStacks()
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)
    print("Dequeued element:", queue.dequeue())
    print("Dequeued element:", queue.dequeue())
    queue.enqueue(40)
    print("Dequeued element:", queue.dequeue())
    print("Dequeued element:", queue.dequeue())









/* output */
Dequeued element: 10
Dequeued element: 20
Dequeued element: 30
Dequeued element: 40
