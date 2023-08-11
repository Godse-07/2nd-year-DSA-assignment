/* Write a program to reverse a doubly linked list. */


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
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    
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

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original List: ");
    printList(head);

    reverseList(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}



/* Original List: 1 2 3 4 5 
Reversed List: 5 4 3 2 1  */




class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_at_end(head, data):
    new_node = Node(data)
    if head is None:
        return new_node

    current = head
    while current.next is not None:
        current = current.next

    current.next = new_node
    new_node.prev = current
    return head

def reverse_list(head):
    temp = None
    current = head
    
    while current is not None:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev
        
    if temp is not None:
        head = temp.prev
        
    return head

def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    head = None
    head = insert_at_end(head, 1)
    head = insert_at_end(head, 2)
    head = insert_at_end(head, 3)
    head = insert_at_end(head, 4)
    head = insert_at_end(head, 5)

    print("Original List:", end=" ")
    print_list(head)

    head = reverse_list(head)

    print("Reversed List:", end=" ")
    print_list(head)
