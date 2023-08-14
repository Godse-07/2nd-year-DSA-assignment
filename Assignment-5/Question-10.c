/* Write a program to arrange a binary tree with a doubly linked list. */



#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createListNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void convertTreeToDLL(struct TreeNode* root, struct Node** head, struct Node** tail) {
    if (root == NULL)
        return;

    convertTreeToDLL(root->left, head, tail);

    struct Node* newNode = createListNode(root->data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }

    convertTreeToDLL(root->right, head, tail);
}

void displayDLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    convertTreeToDLL(root, &head, &tail);

    printf("Doubly Linked List from Binary Tree: ");
    displayDLL(head);

    return 0;
}





/* Doubly Linked List from Binary Tree:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> None */







class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def convert_tree_to_dll(root, head, tail):
    if root is None:
        return
    
    convert_tree_to_dll(root.left, head, tail)

    new_node = Node(root.data)
    if head[0] is None:
        head[0] = new_node
        tail[0] = new_node
    else:
        new_node.prev = tail[0]
        tail[0].next = new_node
        tail[0] = new_node

    convert_tree_to_dll(root.right, head, tail)

def display_dll(head):
    temp = head
    while temp:
        print(temp.data, "->", end=" ")
        temp = temp.next
    print("None")

if __name__ == "__main__":
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(7)

    head = None
    tail = None

    convert_tree_to_dll(root, [head], [tail])

    print("Doubly Linked List from Binary Tree:")
    display_dll(head)
