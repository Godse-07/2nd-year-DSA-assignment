/* Write a program to perform insertion & deletion of elements at different position of
doubly linked list.  */


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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
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

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; ++i) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position; ++i) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
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

    printf("Doubly Linked List after insertion: ");
    display(head);

    insertAtBeginning(&head, 0);
    insertAtPosition(&head, 4, 4);

    printf("Doubly Linked List after more insertions: ");
    display(head);

    deleteAtPosition(&head, 1);
    deleteAtPosition(&head, 3);

    printf("Doubly Linked List after deletions: ");
    display(head);

    return 0;
}




/* Doubly Linked List after insertion:
1 -> 2 -> 3 -> None
Doubly Linked List after more insertions:
0 -> 1 -> 2 -> 4 -> 3 -> None
Doubly Linked List after deletions:
1 -> 2 -> None */







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

    def insert_at_beginning(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

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

    def insert_at_position(self, data, position):
        if position == 1:
            self.insert_at_beginning(data)
            return
        new_node = self.create_node(data)
        temp = self.head
        for i in range(1, position - 1):
            temp = temp.next
            if temp is None:
                print("Invalid position.")
                return
        new_node.next = temp.next
        new_node.prev = temp
        if temp.next:
            temp.next.prev = new_node
        temp.next = new_node

    def delete_at_position(self, position):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        for i in range(1, position):
            temp = temp.next
            if temp is None:
                print("Invalid position.")
                return
        if temp.prev:
            temp.prev.next = temp.next
        else:
            self.head = temp.next
        if temp.next:
            temp.next.prev = temp.prev
        del temp

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    dll = DoublyLinkedList()

    dll.insert_at_end(1)
    dll.insert_at_end(2)
    dll.insert_at_end(3)

    print("Doubly Linked List after insertion:")
    dll.display()

    dll.insert_at_beginning(0)
    dll.insert_at_position(4, 4)

    print("Doubly Linked List after more insertions:")
    dll.display()

    dll.delete_at_position(1)
    dll.delete_at_position(3)

    print("Doubly Linked List after deletions:")
    dll.display()
