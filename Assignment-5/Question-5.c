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

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    newNode->prev = current;
    current->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
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



/* Original List: 1 2 3 
List after deleting at position 1: 1 3 
 */


class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def insert_at_position(head, data, position):
    new_node = Node(data)
    if head is None:
        return new_node

    if position == 0:
        new_node.next = head
        head.prev = new_node
        return new_node

    current = head
    for i in range(position - 1):
        if current.next is not None:
            current = current.next
        else:
            break

    new_node.next = current.next
    if current.next is not None:
        current.next.prev = new_node
    new_node.prev = current
    current.next = new_node
    return head

def delete_at_position(head, position):
    if head is None:
        return None

    current = head
    for i in range(position):
        if current is not None:
            current = current.next
        else:
            break

    if current is None:
        return head

    if current.prev is not None:
        current.prev.next = current.next
    else:
        head = current.next

    if current.next is not None:
        current.next.prev = current.prev

    del current
    return head

def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
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
