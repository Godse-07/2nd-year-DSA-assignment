/* Write a program to implement ‘Dequeue’.  */


#include <stdio.h>
#include <stdlib.h>

struct DequeNode {
    int data;
    struct DequeNode* next;
    struct DequeNode* prev;
};

struct Deque {
    struct DequeNode* front;
    struct DequeNode* rear;
};

struct DequeNode* createNode(int data) {
    struct DequeNode* newNode = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (deque == NULL) {
        return NULL;
    }
    deque->front = deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void addToFront(struct Deque* deque, int data) {
    struct DequeNode* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void addToRear(struct Deque* deque, int data) {
    struct DequeNode* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int removeFromFront(struct Deque* deque) {
    int item;
    if (isEmpty(deque)) {
        return -1;
    } else {
        struct DequeNode* temp = deque->front;
        item = temp->data;
        if (deque->front == deque->rear) {
            deque->front = deque->rear = NULL;
        } else {
            deque->front = deque->front->next;
            deque->front->prev = NULL;
        }
        free(temp);
        return item;
    }
}

int removeFromRear(struct Deque* deque) {
    int item;
    if (isEmpty(deque)) {
        return -1;
    } else {
        struct DequeNode* temp = deque->rear;
        item = temp->data;
        if (deque->front == deque->rear) {
            deque->front = deque->rear = NULL;
        } else {
            deque->rear = deque->rear->prev;
            deque->rear->next = NULL;
        }
        free(temp);
        return item;
    }
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        struct DequeNode* current = deque->front;
        printf("Deque elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void reverseDisplay(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        struct DequeNode* current = deque->rear;
        printf("Deque elements (in reverse order): ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->prev;
        }
        printf("\n");
    }
}

int main() {
    struct Deque* deque = createDeque();
    addToFront(deque, 10);
    addToRear(deque, 20);
    addToFront(deque, 5);
    display(deque);
    reverseDisplay(deque);
    removeFromFront(deque);
    display(deque);
    reverseDisplay(deque);
    removeFromRear(deque);
    display(deque);
    reverseDisplay(deque);
    return 0;
}



/* python code */


class DequeNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.front = None
        self.rear = None

    def createNode(self, data):
        newNode = DequeNode(data)
        return newNode

    def isEmpty(self):
        return (self.front is None)

    def addToFront(self, data):
        newNode = self.createNode(data)
        if newNode is None:
            return
        if self.isEmpty():
            self.front = self.rear = newNode
        else:
            newNode.next = self.front
            self.front.prev = newNode
            self.front = newNode

    def addToRear(self, data):
        newNode = self.createNode(data)
        if newNode is None:
            return
        if self.isEmpty():
            self.front = self.rear = newNode
        else:
            newNode.prev = self.rear
            self.rear.next = newNode
            self.rear = newNode

    def removeFromFront(self):
        if self.isEmpty():
            return -1
        else:
            temp = self.front
            item = temp.data
            if self.front == self.rear:
                self.front = self.rear = None
            else:
                self.front = self.front.next
                self.front.prev = None
            del temp
            return item

    def removeFromRear(self):
        if self.isEmpty():
            return -1
        else:
            temp = self.rear
            item = temp.data
            if self.front == self.rear:
                self.front = self.rear = None
            else:
                self.rear = self.rear.prev
                self.rear.next = None
            del temp
            return item

    def display(self):
        if self.isEmpty():
            print("Deque is empty.")
        else:
            current = self.front
            print("Deque elements:", end=" ")
            while current is not None:
                print(current.data, end=" ")
                current = current.next
            print()

    def reverseDisplay(self):
        if self.isEmpty():
            print("Deque is empty.")
        else:
            current = self.rear
            print("Deque elements (in reverse order):", end=" ")
            while current is not None:
                print(current.data, end=" ")
                current = current.prev
            print()

# Create a Deque
deque = Deque()
deque.addToFront(10)
deque.addToRear(20)
deque.addToFront(5)
deque.display()
deque.reverseDisplay()
deque.removeFromFront()
deque.display()
deque.reverseDisplay()
deque.removeFromRear()
deque.display()
deque.reverseDisplay()
