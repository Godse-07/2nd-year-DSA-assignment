/* Write a program to implement a stack using queue.  */



#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Create a new queue node
struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Check if a queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Enqueue an element into a queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from a queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    } else {
        struct QueueNode* temp = queue->front;
        int data = temp->data;
        queue->front = temp->next;
        free(temp);
        return data;
    }
}

// Structure for a stack using two queues
struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

// Initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    enqueue(stack->q2, data);
    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack->q1)) {
        return -1;
    }
    return dequeue(stack->q1);
}

int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    push(stack, 40);
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    return 0;
}





/* python code */

class Queue:
    def __init__(self):
        self.queue = []

    def is_empty(self):
        return len(self.queue) == 0

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        return None

class StackUsingQueue:
    def __init__(self):
        self.q1 = Queue()
        self.q2 = Queue()

    def push(self, item):
        self.q2.enqueue(item)
        while not self.q1.is_empty():
            self.q2.enqueue(self.q1.dequeue())
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if not self.q1.is_empty():
            return self.q1.dequeue()
        return None

if __name__ == "__main__":
    stack = StackUsingQueue()
    stack.push(10)
    stack.push(20)
    stack.push(30)
    print("Popped element:", stack.pop())
    print("Popped element:", stack.pop())
    stack.push(40)
    print("Popped element:", stack.pop())
    print("Popped element:", stack.pop())



/* output */

Popped element: 30
Popped element: 20
Popped element: 40
Popped element: 10
