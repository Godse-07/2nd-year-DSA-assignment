/* Write a program to implement a singly circular linked list. 
 */


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* insertEnd(struct Node* last, int data) {
    if (last == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = newNode;
        return newNode;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}


void display(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("...\n");
}

int main() {
    struct Node* last = NULL;

    last = insertEnd(last, 1);
    last = insertEnd(last, 2);
    last = insertEnd(last, 3);

    printf("Circular Linked List: ");
    display(last);

    return 0;
}




/* Circular Linked List: 1 -> 2 -> 3 -> ... */



class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.last = None

    def insertEnd(self, data):
        new_node = Node(data)
        if self.last is None:
            self.last = new_node
            new_node.next = new_node
        else:
            new_node.next = self.last.next
            self.last.next = new_node
            self.last = new_node

    def display(self):
        if self.last is None:
            print("List is empty.")
            return

        temp = self.last.next
        while True:
            print(temp.data, "->", end=" ")
            temp = temp.next
            if temp == self.last.next:
                break
        print("...")

if __name__ == "__main__":
    circular_list = CircularLinkedList()

    circular_list.insertEnd(1)
    circular_list.insertEnd(2)
    circular_list.insertEnd(3)

    print("Circular Linked List:")
    circular_list.display()
