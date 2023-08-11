/* Write a program to implement a doubly linked list. */



#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);

    printf("Doubly Linked List: ");
    display(head);

    return 0;
}



/* Doubly Linked List: 1 <-> 2 <-> 3 <-> NULL */



class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insertEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def display(self):
        temp = self.head
        while temp is not None:
            print(temp.data, "<->", end=" ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    doubly_list = DoublyLinkedList()

    doubly_list.insertEnd(1)
    doubly_list.insertEnd(2)
    doubly_list.insertEnd(3)

    print("Doubly Linked List:")
    doubly_list.display()
