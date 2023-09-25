/* Write a program to implement linear queue using array.  */



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
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
            front++;
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}





/* python code */



MAX_SIZE = 100

queue = [0] * MAX_SIZE
front = -1
rear = -1

def isFull():
    return rear == MAX_SIZE - 1

def isEmpty():
    return front == -1

def enqueue(item):
    global front, rear
    if isFull():
        print("Queue is full. Cannot enqueue.")
    else:
        if front == -1:
            front = 0
        rear += 1
        queue[rear] = item
        print(f"{item} enqueued to the queue.")

def dequeue():
    global front, rear
    if isEmpty():
        print("Queue is empty. Cannot dequeue.")
        return -1
    else:
        item = queue[front]
        if front == rear:
            front = rear = -1
        else:
            front += 1
        print(f"{item} dequeued from the queue.")
        return item

def display():
    if isEmpty():
        print("Queue is empty.")
    else:
        print("Queue elements:", end=" ")
        for i in range(front, rear + 1):
            print(queue[i], end=" ")
        print()

if __name__ == "__main__":
    enqueue(10)
    enqueue(20)
    enqueue(30)
    display()
    dequeue()
    display()





/* output */

10 enqueued to the queue.
20 enqueued to the queue.
30 enqueued to the queue.
Queue elements: 10 20 30 
10 dequeued from the queue.
Queue elements: 20 30 
