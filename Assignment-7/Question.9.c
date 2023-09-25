/* Write a program to reverse a queue. 
 */


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

// Structure for a stack
struct Stack {
    struct QueueNode* top;
};

// Initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Push an element onto a stack
void push(struct Stack* stack, int data) {
    struct QueueNode* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from a stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }
    struct QueueNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to reverse a queue
void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack();
    while (!isEmpty(queue)) {
        push(stack, dequeue(queue));
    }
    while (stack->top != NULL) {
        enqueue(queue, pop(stack));
    }
}

// Function to display the elements of a queue
void display(struct Queue* queue) {
    struct QueueNode* current = queue->front;
    printf("Queue elements (front to rear): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Original ");
    display(queue);

    reverseQueue(queue);

    printf("Reversed ");
    display(queue);

    return 0;
}




/* python */

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

    def display(self):
        print("Queue elements (front to rear):", self.queue)

def reverse_queue(queue):
    stack = []
    while not queue.is_empty():
        stack.append(queue.dequeue())
    while stack:
        queue.enqueue(stack.pop())

if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)
    queue.enqueue(40)

    print("Original ", end="")
    queue.display()

    reverse_queue(queue)

    print("Reversed ", end="")
    queue.display()




/* output */
Original Queue elements (front to rear): 10 20 30 40
Reversed Queue elements (front to rear): 40 30 20 10
