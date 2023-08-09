/* Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is
a given positive integer smaller than or equal to length of the linked list.
Sample Input: 2->4->7->8->9
K = 3
Output: 8->9->2->4->7  */


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

void leftShift(Node **head, int k) {
    if (*head == NULL || k <= 0) {
        return;
    }

    Node *current = *head;
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    Node *kthNode = current;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
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

    int k = 3;
    leftShift(&head, k);

    printf("Linked List after left shift by %d nodes: ", k);
    displayList(head);

    freeList(head);

    return 0;
}



/* Original Linked List: 2 -> 4 -> 7 -> 8 -> 9 -> NULL
Linked List after left shift by 3 nodes: 8 -> 9 -> 2 -> 4 -> 7 -> NULL */



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

def left_shift(head, k):
    if not head or k <= 0:
        return head

    current = head
    count = 1
    while count < k and current:
        current = current.next
        count += 1

    if not current:
        return head

    kth_node = current
    while current.next:
        current = current.next

    current.next = head
    new_head = kth_node.next
    kth_node.next = None

    return new_head

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

    k = 3
    head = left_shift(head, k)

    print(f"Linked List after left shift by {k} nodes:", end=" ")
    display_list(head)

    free_list(head)
