/* Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.  */



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

void pairwiseSwap(Node *head) {
    Node *current = head;

    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        current = current->next->next;
    }
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

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printf("Original Linked List: ");
    displayList(head);

    pairwiseSwap(head);

    printf("Linked List after pairwise swapping: ");
    displayList(head);

    freeList(head);

    return 0;
}



/* Original Linked List: 1 -> 2 -> 3 -> 4 -> NULL
Linked List after pairwise swapping: 2 -> 1 -> 4 -> 3 -> NULL */



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

def pairwise_swap(head):
    current = head
    while current and current.next:
        current.data, current.next.data = current.next.data, current.data
        current = current.next.next

def free_list(head):
    temp = head
    while temp:
        next_node = temp.next
        del temp
        temp = next_node

if __name__ == "__main__":
    head = None

    head = insert_at_end(head, 1)
    head = insert_at_end(head, 2)
    head = insert_at_end(head, 3)
    head = insert_at_end(head, 4)

    print("Original Linked List:", end=" ")
    display_list(head)

    pairwise_swap(head)

    print("Linked List after pairwise swapping:", end=" ")
    display_list(head)

    free_list(head)
