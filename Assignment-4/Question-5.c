/* Write a program to merge two already sorted list.  */



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

Node *mergeSortedLists(Node *list1, Node *list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *mergedList = NULL;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }

    return mergedList;
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
    Node *list1 = createNode(5);
    list1->next = createNode(10);
    list1->next->next = createNode(15);

    Node *list2 = createNode(2);
    list2->next = createNode(7);
    list2->next->next = createNode(12);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    Node *mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted List: ");
    displayList(mergedList);

    freeList(mergedList);

    return 0;
}



/* List 1: 5 -> 10 -> 15 -> NULL
List 2: 2 -> 7 -> 12 -> NULL
Merged Sorted List: 2 -> 5 -> 7 -> 10 -> 12 -> 15 -> NULL */



class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def merge_sorted_lists(list1, list2):
    if not list1:
        return list2
    if not list2:
        return list1

    merged_list = None
    if list1.data <= list2.data:
        merged_list = list1
        merged_list.next = merge_sorted_lists(list1.next, list2)
    else:
        merged_list = list2
        merged_list.next = merge_sorted_lists(list1, list2.next)

    return merged_list

def display_list(head):
    temp = head
    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next
    print("None")

def free_list(head):
    temp = head
    while temp:
        next_node = temp.next
        del temp
        temp = next_node

if __name__ == "__main__":
    list1 = Node(5)
    list1.next = Node(10)
    list1.next.next = Node(15)

    list2 = Node(2)
    list2.next = Node(7)
    list2.next.next = Node(12)

    print("List 1:", end=" ")
    display_list(list1)
    print("List 2:", end=" ")
    display_list(list2)

    merged_list = merge_sorted_lists(list1, list2)

    print("Merged Sorted List:", end=" ")
    display_list(merged_list)

    free_list(merged_list)
