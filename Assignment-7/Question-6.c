/* Write a program to implement priority queue.  */



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct Node* front = NULL;

void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (newNode == NULL) {
        return;
    }
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* current = front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    printf("Dequeued element: %d (Priority: %d)\n", temp->data, temp->priority);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements:\n");
    struct Node* current = front;
    while (current != NULL) {
        printf("Element: %d (Priority: %d)\n", current->data, current->priority);
        current = current->next;
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 2);
    display();
    dequeue();
    display();
    return 0;
}




Priority Queue elements:
Element: 20 (Priority: 1)
Element: 10 (Priority: 2)
Element: 40 (Priority: 2)
Element: 30 (Priority: 3)
Dequeued element: 20 (Priority: 1)
Priority Queue elements:
Element: 10 (Priority: 2)
Element: 40 (Priority: 2)
Element: 30 (Priority: 3)




/* python code */
import heapq

class PriorityQueue:
    def __init__(self):
        self.elements = []
    
    def enqueue(self, item, priority):
        heapq.heappush(self.elements, (priority, item))
    
    def dequeue(self):
        if not self.is_empty():
            priority, item = heapq.heappop(self.elements)
            return item, priority
        else:
            return None
    
    def is_empty(self):
        return len(self.elements) == 0

    def display(self):
        if not self.is_empty():
            print("Priority Queue elements:")
            for priority, item in self.elements:
                print(f"Element: {item} (Priority: {priority})")
        else:
            print("Priority Queue is empty.")

# Create a Priority Queue
pq = PriorityQueue()
pq.enqueue(10, 2)
pq.enqueue(20, 1)
pq.enqueue(30, 3)
pq.enqueue(40, 2)
pq.display()

item, priority = pq.dequeue()
if item is not None:
    print(f"Dequeued element: {item} (Priority: {priority})")

pq.display()
