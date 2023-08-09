/* Write a program to reverse a list.  */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);

    printf("Original Linked List: ");
    displayList(head);

    head = reverseList(head);

    printf("Reversed Linked List: ");
    displayList(head);

    freeList(head);

    return 0;
}




/* Original Linked List: 2 -> 4 -> 7 -> 8 -> 9 -> NULL
Reversed Linked List: 9 -> 8 -> 7 -> 4 -> 2 -> NULL */



class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert_at_end(head, data):
    new_node = Node(data)
    if not head:
        return new_node
    
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = new_node
    return head

def display_list(head):
    temp = head
    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next
    print("None")

def reverse_list(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def free_list(head):
    temp = head
    while temp:
        next_node = temp.next
        del temp
        temp = next_node

if __name__ == "__main__":
    head = None

    head = insert_at_end(head, 2)
    head = insert_at_end(head, 4)
    head = insert_at_end(head, 7)
    head = insert_at_end(head, 8)
    head = insert_at_end(head, 9)

    print("Original Linked List:", end=" ")
    display_list(head)

    head = reverse_list(head)

    print("Reversed Linked List:", end=" ")
    display_list(head)

    free_list(head)
