/* Write a program to implement multiple queues in a single array. 
 */


class MultiQueue:
    def __init__(self, num_queues, max_size):
        self.num_queues = num_queues
        self.max_size = max_size
        self.array = [None] * (num_queues * max_size)
        self.front = [-1] * num_queues
        self.rear = [-1] * num_queues

    def isFull(self, queue_num):
        return ((self.rear[queue_num] + 1) % self.max_size == self.front[queue_num])

    def isEmpty(self, queue_num):
        return (self.front[queue_num] == -1 and self.rear[queue_num] == -1)

    def enqueue(self, queue_num, item):
        if self.isFull(queue_num):
            print(f"Queue {queue_num} is full. Cannot enqueue {item}.")
        else:
            if self.isEmpty(queue_num):
                self.front[queue_num] = self.rear[queue_num] = queue_num * self.max_size
            else:
                self.rear[queue_num] = (self.rear[queue_num] + 1) % self.max_size
            self.array[self.rear[queue_num]] = item
            print(f"{item} enqueued to Queue {queue_num}.")

    def dequeue(self, queue_num):
        if self.isEmpty(queue_num):
            print(f"Queue {queue_num} is empty. Cannot dequeue.")
            return -1
        else:
            item = self.array[self.front[queue_num]]
            if self.front[queue_num] == self.rear[queue_num]:
                self.front[queue_num] = self.rear[queue_num] = -1
            else:
                self.front[queue_num] = (self.front[queue_num] + 1) % self.max_size
            print(f"{item} dequeued from Queue {queue_num}.")
            return item

    def display(self, queue_num):
        if self.isEmpty(queue_num):
            print(f"Queue {queue_num} is empty.")
        else:
            i = self.front[queue_num]
            print(f"Queue {queue_num} elements:", end=" ")
            while i != self.rear[queue_num]:
                print(self.array[i], end=" ")
                i = (i + 1) % (self.num_queues * self.max_size)
            print(self.array[i])


mq = MultiQueue(3, 5)

mq.enqueue(0, 10)
mq.enqueue(1, 20)
mq.enqueue(2, 30)
mq.enqueue(0, 40)
mq.enqueue(1, 50)
mq.display(0)
mq.display(1)
mq.display(2)

mq.dequeue(0)
mq.display(0)

mq.enqueue(2, 60)
mq.display(2)




/* output */

10 enqueued to Queue 0.
20 enqueued to Queue 1.
30 enqueued to Queue 2.
40 enqueued to Queue 0.
50 enqueued to Queue 1.
Queue 0 elements: 10 40 
Queue 1 elements: 20 50 
Queue 2 elements: 30 
10 dequeued from Queue 0.
Queue 0 elements: 40 
60 enqueued to Queue 2.
Queue 2 elements: 30 60 





/* c code */

#include <stdio.h>
#include <stdlib.h>

#define NUM_QUEUES 3
#define MAX_SIZE 5

int array[NUM_QUEUES * MAX_SIZE];
int front[NUM_QUEUES];
int rear[NUM_QUEUES];

void initialize() {
    for (int i = 0; i < NUM_QUEUES; i++) {
        front[i] = rear[i] = -1;
    }
}

int isFull(int queueNum) {
    return ((rear[queueNum] + 1) % MAX_SIZE == front[queueNum]);
}

int isEmpty(int queueNum) {
    return (front[queueNum] == -1);
}

void enqueue(int queueNum, int item) {
    if (isFull(queueNum)) {
        printf("Queue %d is full. Cannot enqueue %d.\n", queueNum, item);
    } else {
        if (isEmpty(queueNum)) {
            front[queueNum] = rear[queueNum] = queueNum * MAX_SIZE;
        } else {
            rear[queueNum] = (rear[queueNum] + 1) % MAX_SIZE;
        }
        array[rear[queueNum]] = item;
        printf("%d enqueued to Queue %d.\n", item, queueNum);
    }
}

int dequeue(int queueNum) {
    int item;
    if (isEmpty(queueNum)) {
        printf("Queue %d is empty. Cannot dequeue.\n", queueNum);
        return -1;
    } else {
        item = array[front[queueNum]];
        if (front[queueNum] == rear[queueNum]) {
            front[queueNum] = rear[queueNum] = -1;
        } else {
            front[queueNum] = (front[queueNum] + 1) % MAX_SIZE;
        }
        printf("%d dequeued from Queue %d.\n", item, queueNum);
        return item;
    }
}

void display(int queueNum) {
    if (isEmpty(queueNum)) {
        printf("Queue %d is empty.\n", queueNum);
    } else {
        int i = front[queueNum];
        printf("Queue %d elements: ", queueNum);
        while (i != rear[queueNum]) {
            printf("%d ", array[i]);
            i = (i + 1) % (NUM_QUEUES * MAX_SIZE);
        }
        printf("%d\n", array[i]);
    }
}

int main() {
    initialize();
    
    enqueue(0, 10);
    enqueue(1, 20);
    enqueue(2, 30);
    enqueue(0, 40);
    enqueue(1, 50);

    display(0);
    display(1);
    display(2);

    dequeue(0);
    display(0);

    enqueue(2, 60);
    display(2);

    return 0;
}
