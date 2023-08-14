/* Write a program to perform insertion & deletion of elements at different position of
doubly circular linked list.  */


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
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *head;
        (*head)->prev = newNode;
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
        if (temp == *head) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < position) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position.\n");
            return;
        }
        count++;
    }
    if (prev == NULL) {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        *head = temp->next;
        last->next = *head;
        (*head)->prev = last;
        free(temp);
    } else {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
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

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Doubly Circular Linked List after insertion: ");
    display(head);

    insertAtBeginning(&head, 0);
    insertAtPosition(&head, 4, 4);

    printf("Doubly Circular Linked List after more insertions: ");
    display(head);

    deleteAtPosition(&head, 1);
    deleteAtPosition(&head, 3);

    printf("Doubly Circular Linked List after deletions: ");
    display(head);

    return 0;
}




/* Doubly Circular Linked List after insertion:
1 -> 2 -> 3 -> ...
Doubly Circular Linked List after more insertions:
0 -> 1 -> 2 -> 4 -> 3 -> ...
Doubly Circular Linked List after deletions:
1 -> 2 -> ... */






class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    def create_node(self, data):
        new_node = Node(data)
        new_node.prev = new_node
        new_node.next = new_node
        return new_node

    def insert_at_beginning(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            new_node.prev = self.head.prev
            self.head.prev.next = new_node
            self.head.prev = new_node
            self.head = new_node

    def insert_at_end(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head.prev
            temp.next = new_node
            new_node.prev = temp
            new_node.next = self.head
            self.head.prev = new_node

    def insert_at_position(self, data, position):
        if position == 1:
            self.insert_at_beginning(data)
            return
        new_node = self.create_node(data)
        temp = self.head
        count = 1
        while count < position - 1:
            temp = temp.next
            if temp == self.head:
                print("Invalid position.")
                return
            count += 1
        new_node.next = temp.next
        new_node.prev = temp
        temp.next.prev = new_node
        temp.next = new_node

    def delete_at_position(self, position):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        count = 1
        while count < position:
            temp = temp.next
            if temp == self.head:
                print("Invalid position.")
                return
            count += 1
        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        if temp == self.head:
            self.head = temp.next
        del temp

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

    dcll.insert_at_end(1)
    dcll.insert_at_end(2)
    dcll.insert_at_end(3)

    print("Doubly Circular Linked List after insertion:")
    dcll.display()

    dcll.insert_at_beginning(0)
    dcll.insert_at_position(4, 4)

    print("Doubly Circular Linked List after more insertions:")
    dcll.display()

    dcll.delete_at_position(1)
    dcll.delete_at_position(3)

    print("Doubly Circular Linked List after deletions:")
    dcll.display()
