/* Write a program to divide doubly linked list from middle and rejoin them in reverse
manner.
Sample input: 1->2->3->4->5->6
Output: 3->2->1->6->5->4 
 */



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
    struct Node* prev = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    *head = prev;
}

void divideAndReverse(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow->next;
    slow->next = NULL;
    secondHalf->prev = NULL;

    reverseList(&secondHalf);

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = secondHalf;
    secondHalf->prev = current;
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
    insertAtEnd(&head, 6);

    printf("Original List: ");
    printList(head);

    divideAndReverse(&head);

    printf("List after division and reversal: ");
    printList(head);

    return 0;
}




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
    prev = None
    current = head
    while current is not None:
        next_node = current.next
        current.next = prev
        current.prev = next_node
        prev = current
        current = next_node
    return prev

def divide_and_reverse(head):
    if head is None or head.next is None:
        return head

    slow = head
    fast = head
    while fast.next is not None and fast.next.next is not None:
        slow = slow.next
        fast = fast.next.next

    second_half = slow.next
    slow.next = None
    second_half.prev = None

    second_half = reverse_list(second_half)

    current = head
    while current.next is not None:
        current = current.next

    current.next = second_half
    second_half.prev = current

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
    head = insert_at_end(head, 6)

    print("Original List:", end=" ")
    print_list(head)

    head = divide_and_reverse(head)

    print("List after division and reversal:", end=" ")
    print_list(head)
