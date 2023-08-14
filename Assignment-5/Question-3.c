/* Write a program to implement a doubly circular linked list.  */



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Doubly Circular Linked List: ");
    display(head);

    return 0;
}



/* Doubly Circular Linked List: 4 -> 3 -> 2 -> 1 -> ... */




class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None
        
class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            new_node.next = new_node
            new_node.prev = new_node
        else:
            new_node.next = self.head
            new_node.prev = self.head.prev
            self.head.prev.next = new_node
            self.head.prev = new_node

    def display(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        while True:
            print(temp.data, "->", end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print("...")

if __name__ == "__main__":
    dcll = DoublyCircularLinkedList()

    dcll.insert(1)
    dcll.insert(2)
    dcll.insert(3)
    dcll.insert(4)

    print("Doubly Circular Linked List:", end=" ")
    dcll.display()
