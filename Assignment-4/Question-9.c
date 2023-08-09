/* Write a program to detect a loop in a list.  */


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

void createLoop(Node *head, int pos) {
    if (pos < 0)
        return;

    Node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node *loopNode = head;
    while (pos--) {
        loopNode = loopNode->next;
    }

    tail->next = loopNode;
}

int detectLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop
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
    insertAtEnd(&head, 5);

    createLoop(head, 2);

    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    freeList(head);

    return 0;
}



/* Loop detected in the linked list. */


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

def create_loop(head, pos):
    if pos < 0:
        return

    tail = head
    while tail.next:
        tail = tail.next

    loop_node = head
    while pos:
        loop_node = loop_node.next
        pos -= 1

    tail.next = loop_node

def detect_loop(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True  # Loop detected

    return False  # No loop

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
    head = insert_at_end(head, 5)

    create_loop(head, 2)

    if detect_loop(head):
        print("Loop detected in the linked list.")
    else:
        print("No loop detected in the linked list.")

    free_list(head)
