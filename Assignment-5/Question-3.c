/*  Write a program to implement a doubly circular linked list. 
 */


#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }

    return head;
}

// Function to display the doubly circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);

    printf("Doubly Circular Linked List: ");
    display(head);

    return 0;
}




/* Doubly Circular Linked List: 1 <-> 2 <-> 3 <-> ... */




class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    def insertEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            new_node.prev = new_node
            new_node.next = new_node
            self.head = new_node
        else:
            last = self.head.prev
            new_node.next = self.head
            self.head.prev = new_node
            new_node.prev = last
            last.next = new_node

    def display(self):
        if self.head is None:
            print("List is empty.")
            return

        temp = self.head
        while True:
            print(temp.data, "<->", end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print("...")

if __name__ == "__main__":
    doubly_circular_list = DoublyCircularLinkedList()

    doubly_circular_list.insertEnd(1)
    doubly_circular_list.insertEnd(2)
    doubly_circular_list.insertEnd(3)

    print("Doubly Circular Linked List:")
    doubly_circular_list.display()
