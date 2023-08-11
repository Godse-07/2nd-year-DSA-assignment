/* Write a program to perform insertion & deletion of elements at different position of
singly circular linked list.  */



#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    
    return head;
}

// Function to insert a new node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }

    return head;
}

// Function to delete a node at a given position
struct Node* deletePosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head->next;
    struct Node* prev = NULL;

    if (position == 1) {
        head->next = temp->next;
        free(temp);
        temp = NULL;
        return head;
    }

    for (int i = 1; i < position && temp != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Invalid position.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    temp = NULL;

    return head;
}

// Function to display the singly circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;

    head = insertBeginning(head, 2);
    head = insertBeginning(head, 1);
    head = insertEnd(head, 3);

    printf("Initial List: ");
    display(head);

    head = deletePosition(head, 2);
    printf("List after deleting at position 2: ");
    display(head);

    head = deletePosition(head, 1);
    printf("List after deleting at position 1: ");
    display(head);

    return 0;
}



/* Initial List: 1 -> 2 -> 3 -> ...
List after deleting at position 2: 1 -> 3 -> ...
List after deleting at position 1: 3 -> ... */




class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyCircularLinkedList:
    def __init__(self):
        self.head = None

    def insertBeginning(self, data):
        new_node = Node(data)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            new_node.next = self.head.next
            self.head.next = new_node

    def insertEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            new_node.next = self.head.next
            self.head.next = new_node
            self.head = new_node

    def deletePosition(self, position):
        if self.head is None:
            print("List is empty.")
            return

        temp = self.head.next
        prev = None

        if position == 1:
            self.head.next = temp.next
            if temp == self.head:
                self.head = None
            return

        for i in range(1, position):
            prev = temp
            temp = temp.next

        if temp == self.head.next:
            self.head.next = temp.next

        prev.next = temp.next
        if temp == self.head:
            self.head = prev

    def display(self):
        if self.head is None:
            print("List is empty.")
            return

        temp = self.head.next
        while temp != self.head.next:
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("...")

if __name__ == "__main__":
    singly_circular_list = SinglyCircularLinkedList()

    singly_circular_list.insertBeginning(2)
    singly_circular_list.insertBeginning(1)
    singly_circular_list.insertEnd(3)

    print("Initial List:")
    singly_circular_list.display()

    singly_circular_list.deletePosition(2)
    print("List after deleting at position 2:")
    singly_circular_list.display()

    singly_circular_list.deletePosition(1)
    print("List after deleting at position 1:")
    singly_circular_list.display()
