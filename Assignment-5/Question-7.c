/* Write a program to remove a particular character from a doubly linked list.  */




#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, char data) {
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

void removeCharacter(struct Node** head, char target) {
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == target) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                *head = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 'a');
    insertAtEnd(&head, 'b');
    insertAtEnd(&head, 'c');
    insertAtEnd(&head, 'a');
    insertAtEnd(&head, 'd');
    insertAtEnd(&head, 'a');

    printf("Original Doubly Linked List: ");
    display(head);

    char target = 'a';
    removeCharacter(&head, target);

    printf("Doubly Linked List after removing '%c': ", target);
    display(head);

    return 0;
}





/* Original Doubly Linked List:
a -> b -> c -> a -> d -> a -> None
Doubly Linked List after removing 'a':
b -> c -> d -> None */







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

    def remove_character(self, target):
        temp = self.head
        while temp:
            if temp.data == target:
                if temp.prev:
                    temp.prev.next = temp.next
                else:
                    self.head = temp.next
                if temp.next:
                    temp.next.prev = temp.prev
                to_delete = temp
                temp = temp.next
                del to_delete
            else:
                temp = temp.next

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    dll = DoublyLinkedList()

    dll.insert_at_end('a')
    dll.insert_at_end('b')
    dll.insert_at_end('c')
    dll.insert_at_end('a')
    dll.insert_at_end('d')
    dll.insert_at_end('a')

    print("Original Doubly Linked List:")
    dll.display()

    target = 'a'
    dll.remove_character(target)

    print(f"Doubly Linked List after removing '{target}':")
    dll.display()
