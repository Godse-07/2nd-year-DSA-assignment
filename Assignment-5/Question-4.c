/* Write a program to perform insertion & deletion of elements at different position of
singly circular linked list.  */



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; ++i) {
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position.\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < position) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            printf("Invalid position.\n");
            return;
        }
        count++;
    }
    if (prev == NULL) {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        *head = temp->next;
        last->next = *head;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Circular Linked List after insertion: ");
    display(head);

    insertAtBeginning(&head, 0);
    insertAtPosition(&head, 4, 4);

    printf("Circular Linked List after more insertions: ");
    display(head);

    deleteAtPosition(&head, 1);
    deleteAtPosition(&head, 3);

    printf("Circular Linked List after deletions: ");
    display(head);

    return 0;
}




/* Circular Linked List after insertion:
1 -> 2 -> 3 -> ...
Circular Linked List after more insertions:
0 -> 1 -> 2 -> 3 -> 4 -> ...
Circular Linked List after deletions:
1 -> 2 -> ...  */





class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def create_node(self, data):
        new_node = Node(data)
        new_node.next = new_node
        return new_node

    def insert_at_beginning(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            new_node.next = self.head
            temp.next = new_node
            self.head = new_node

    def insert_at_end(self, data):
        new_node = self.create_node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def insert_at_position(self, data, position):
        if position == 1:
            self.insert_at_beginning(data)
            return
        new_node = self.create_node(data)
        temp = self.head
        count = 1
        while count < position - 1:
            temp = temp.next
            if temp == self.head:
                print("Invalid position.")
                return
            count += 1
        new_node.next = temp.next
        temp.next = new_node

    def delete_at_position(self, position):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        prev = None
        count = 1
        while count < position:
            prev = temp
            temp = temp.next
            if temp == self.head:
                print("Invalid position.")
                return
            count += 1
        if prev is None:
            last = self.head
            while last.next != self.head:
                last = last.next
            self.head = temp.next
            last.next = self.head
            del temp
        else:
            prev.next = temp.next
            del temp

    def display(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        while True:
            print(temp.data, "->", end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print("...")

if __name__ == "__main__":
    cll = CircularLinkedList()

    cll.insert_at_end(1)
    cll.insert_at_end(2)
    cll.insert_at_end(3)

    print("Circular Linked List after insertion:")
    cll.display()

    cll.insert_at_beginning(0)
    cll.insert_at_position(4, 4)

    print("Circular Linked List after more insertions:")
    cll.display()

    cll.delete_at_position(1)
    cll.delete_at_position(3)

    print("Circular Linked List after deletions:")
    cll.display()
