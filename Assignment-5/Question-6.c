/* Write a program to perform insertion & deletion of elements at different position of
doubly circular linked list */




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

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (current == *head) {
        *head = current->next;
    }
    free(current);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtPosition(&head, 1, 0);
    insertAtPosition(&head, 3, 1);
    insertAtPosition(&head, 2, 1);
    printf("Original List: ");
    printList(head);

    deleteAtPosition(&head, 1);
    printf("List after deleting at position 1: ");
    printList(head);

    return 0;
}



/* 
Original List: 1 2 3 
List after deleting at position 1: 1 3  */



class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_at_position(head, data, position):
    new_node = Node(data)
    if head is None:
        new_node.prev = new_node
        new_node.next = new_node
        return new_node

    current = head
    for i in range(position - 1):
        current = current.next

    new_node.prev = current
    new_node.next = current.next
    current.next.prev = new_node
    current.next = new_node
    return head

def delete_at_position(head, position):
    if head is None:
        return None

    current = head
    for i in range(position):
        current = current.next

    current.prev.next = current.next
    current.next.prev = current.prev
    if current == head:
        head = current.next

    del current
    return head

def print_list(head):
    if head is None:
        print("List is empty.")
        return
    
    current = head
    while True:
        print(current.data, end=" ")
        current = current.next
        if current == head:
            break
    print()

if __name__ == "__main__":
    head = None
    head = insert_at_position(head, 1, 0)
    head = insert_at_position(head, 3, 1)
    head = insert_at_position(head, 2, 1)
    print("Original List:", end=" ")
    print_list(head)

    head = delete_at_position(head, 1)
    print("List after deleting at position 1:", end=" ")
    print_list(head)
