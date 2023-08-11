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

void removeCharacter(struct Node** head, char character) {
    if (*head == NULL) {
        return;
    }
    
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == character) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = createNode('a');
    head->next = createNode('b');
    head->next->prev = head;
    head->next->next = createNode('c');
    head->next->next->prev = head->next;

    printf("Original List: ");
    printList(head);

    char characterToRemove = 'b';
    removeCharacter(&head, characterToRemove);
    
    printf("List after removing '%c': ", characterToRemove);
    printList(head);

    return 0;
}




/* Original List: a b c 
List after removing 'b': a c  */



class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def remove_character(head, character):
    if head is None:
        return None

    current = head
    while current is not None:
        if current.data == character:
            if current.prev is not None:
                current.prev.next = current.next
            else:
                head = current.next

            if current.next is not None:
                current.next.prev = current.prev

            temp = current
            current = current.next
            del temp
        else:
            current = current.next

    return head

def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    head = Node('a')
    head.next = Node('b')
    head.next.prev = head
    head.next.next = Node('c')
    head.next.next.prev = head.next

    print("Original List:", end=" ")
    print_list(head)

    character_to_remove = 'b'
    head = remove_character(head, character_to_remove)

    print("List after removing '{}':".format(character_to_remove), end=" ")
    print_list(head)
