/* Write a program to implement circular queue.  */


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); // This will overflow the circular queue.
    display();
    return 0;
}


/* output */


10 enqueued to the queue.
20 enqueued to the queue.
30 enqueued to the queue.
Queue elements: 10 20 30
10 dequeued from the queue.
Queue elements: 20 30
40 enqueued to the queue.
50 enqueued to the queue.
Queue is full. Cannot enqueue.
Queue elements: 20 30 40 50





/* python code */


class CircularQueue:
    def __init__(self, max_size):
        self.max_size = max_size
        self.queue = [None] * max_size
        self.front = self.rear = -1

    def isFull(self):
        return ((self.rear + 1) % self.max_size == self.front)

    def isEmpty(self):
        return (self.front == -1 and self.rear == -1)

    def enqueue(self, item):
        if self.isFull():
            print("Queue is full. Cannot enqueue.")
        else:
            if self.isEmpty():
                self.front = self.rear = 0
            else:
                self.rear = (self.rear + 1) % self.max_size
            self.queue[self.rear] = item
            print(f"{item} enqueued to the queue.")

    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty. Cannot dequeue.")
            return -1
        else:
            item = self.queue[self.front]
            if self.front == self.rear:
                self.front = self.rear = -1
            else:
                self.front = (self.front + 1) % self.max_size
            print(f"{item} dequeued from the queue.")
            return item

    def display(self):
        if self.isEmpty():
            print("Queue is empty.")
        else:
            i = self.front
            print("Queue elements:", end=" ")
            while i != self.rear:
                print(self.queue[i], end=" ")
                i = (i + 1) % self.max_size
            print(self.queue[i])

# Create a circular queue with a maximum size of 5
cq = CircularQueue(5)

cq.enqueue(10)
cq.enqueue(20)
cq.enqueue(30)
cq.display()
cq.dequeue()
cq.display()
cq.enqueue(40)
cq.enqueue(50)
cq.enqueue(60)  # This will overflow the circular queue.
cq.display()
