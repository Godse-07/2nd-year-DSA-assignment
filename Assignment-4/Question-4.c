/* Write a program to perform insertion & deletion of element in a given list.  */


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

void deleteNode(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == data) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *prev = *head;
    Node *current = (*head)->next;

    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Element not found in the list.\n");
}

void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    printf("Linked List: ");
    displayList(head);

    deleteNode(&head, 20);
    
    printf("Linked List after deletion: ");
    displayList(head);

    freeList(head);

    return 0;
}



/* Linked List: 10 -> 20 -> 30 -> NULL
Linked List after deletion: 10 -> 30 -> NULL */



class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
    
    def delete_node(self, data):
        if not self.head:
            print("List is empty.")
            return

        if self.head.data == data:
            temp = self.head
            self.head = self.head.next
            del temp
            return

        prev = self.head
        current = self.head.next

        while current:
            if current.data == data:
                prev.next = current.next
                del current
                return
            prev = current
            current = current.next

        print("Element not found in the list.")
    
    def display_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")
    
    def free_list(self):
        temp = self.head
        while temp:
            next_node = temp.next
            del temp
            temp = next_node

if __name__ == "__main__":
    linked_list = LinkedList()

    linked_list.insert_at_end(10)
    linked_list.insert_at_end(20)
    linked_list.insert_at_end(30)
    
    print("Linked List:", end=" ")
    linked_list.display_list()

    linked_list.delete_node(20)
    
    print("Linked List after deletion:", end=" ")
    linked_list.display_list()

    linked_list.free_list()
