/* Write a program to implement a two way threaded binary tree.  */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a threaded binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded; // Indicates whether the right pointer is a thread
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0; // Initially, both left and right pointers are not threads
    return newNode;
}

// Function to perform in-order traversal of the threaded binary tree
void inOrderTraversal(struct Node* root) {
    struct Node* current = leftMost(root);

    while (current != NULL) {
        // Print the current node's data
        printf("%d ", current->data);

        // If the right pointer is a thread, move to the in-order successor
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost child of the right subtree
            current = leftMost(current->right);
        }
    }
}

// Function to find the leftmost node in a subtree
struct Node* leftMost(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

// Function to insert a value into the threaded binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Find the position to insert the new node
    if (data < root->data) {
        // Insert into the left subtree
        root->left = insert(root->left, data);

        // Set threaded pointers
        if (root->left->right == NULL) {
            root->left->right = root;
            root->left->isThreaded = 1;
        }
    } else if (data > root->data) {
        // Insert into the right subtree
        root->right = insert(root->right, data);

        // Set threaded pointers
        if (root->right->left == NULL) {
            root->right->left = root;
            root->right->isThreaded = 1;
        }
    }

    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert values into the threaded binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal to display the threaded binary tree
    printf("In-order Traversal of Threaded Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}


/*
In-order Traversal of Threaded Binary Tree: 20 30 40 50 60 70 80 
*/

//python code
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.isThreaded = False

def in_order_traversal(root):
    current = left_most(root)

    while current:
        print(current.data, end=" ")

        if current.isThreaded:
            current = current.right
        else:
            current = left_most(current.right)

def left_most(node):
    if not node:
        return None

    while node.left:
        node = node.left

    return node

def insert(root, data):
    if not root:
        return Node(data)

    if data < root.data:
        root.left = insert(root.left, data)

        if not root.left.right:
            root.left.right = root
            root.left.isThreaded = True
    elif data > root.data:
        root.right = insert(root.right, data)

        if not root.right.left:
            root.right.left = root
            root.right.isThreaded = True

    return root

root = None

root = insert(root, 50)
insert(root, 30)
insert(root, 20)
insert(root, 40)
insert(root, 70)
insert(root, 60)
insert(root, 80)

print("In-order Traversal of Threaded Binary Tree: ", end="")
in_order_traversal(root)
print()
