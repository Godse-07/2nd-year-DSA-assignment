/* Write a program to divide doubly linked list from middle and rejoin them in reverse
manner.
Sample input: 1->2->3->4->5->6
Output: 3->2->1->6->5->4 */


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
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void divideAndReverse(struct Node** head) {
    struct Node* slow = *head;
    struct Node* fast = *head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow->next;
    slow->next = NULL;
    secondHalf->prev = NULL;

    struct Node* current = secondHalf;
    struct Node* prev = NULL;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        current->prev = nextNode;
        prev = current;
        current = nextNode;
    }

    *head = prev;
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = secondHalf;
    secondHalf->prev = temp;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    printf("Original Doubly Linked List: ");
    display(head);

    divideAndReverse(&head);

    printf("Reversed and Joined Doubly Linked List: ");
    display(head);

    return 0;
}









class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def create_node(self, data):
        new_node = Node(data)
        return new_node

    def insert_at_end(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def divide_and_reverse(self):
        slow = self.head
        fast = self.head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        second_half = slow.next
        slow.next = None
        second_half.prev = None

        current = second_half
        prev = None

        while current:
            current.prev, current.next = current.next, prev
            prev = current
            current = current.prev

        self.head = prev
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = second_half
        second_half.prev = temp

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    dll = DoublyLinkedList()

    for i in range(1, 7):
        dll.insert_at_end(i)

    print("Original Doubly Linked List:")
    dll.display()

    dll.divide_and_reverse()

    print("Reversed and Joined Doubly Linked List:")
    dll.display()
