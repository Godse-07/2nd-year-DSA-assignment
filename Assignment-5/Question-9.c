/* Write a program to reverse a doubly linked list.  */


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

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void reverseDoublyLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Doubly Linked List: ");
    display(head);

    reverseDoublyLinkedList(&head);

    printf("Reversed Doubly Linked List: ");
    display(head);

    return 0;
}





/* Original Doubly Linked List:
1 -> 2 -> 3 -> 4 -> 5 -> None
Reversed Doubly Linked List:
5 -> 4 -> 3 -> 2 -> 1 -> None */





class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def create_node(self, data):
        new_node = Node(data)
        return new_node

    def insert_at_end(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def reverse(self):
        current = self.head
        temp = None

        while current:
            temp = current.prev
            current.prev = current.next
            current.next = temp
            current = current.prev

        if temp:
            self.head = temp.prev

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    dll = DoublyLinkedList()

    for i in range(1, 6):
        dll.insert_at_end(i)

    print("Original Doubly Linked List:")
    dll.display()

    dll.reverse()

    print("Reversed Doubly Linked List:")
    dll.display()
