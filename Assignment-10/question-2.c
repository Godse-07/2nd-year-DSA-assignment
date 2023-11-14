/* Write a program to implement tree traversal.  */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal function
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal function
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal function
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create the root node and add child nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // In-order traversal
    printf("In-order Traversal in C: ");
    inOrderTraversal(root);
    printf("\n");

    // Pre-order traversal
    printf("Pre-order Traversal in C: ");
    preOrderTraversal(root);
    printf("\n");

    // Post-order traversal
    printf("Post-order Traversal in C: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}




//python code
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to create a new node
def create_node(data):
    return Node(data)

# In-order traversal function
def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(root.data, end=" ")
        in_order_traversal(root.right)

# Pre-order traversal function
def pre_order_traversal(root):
    if root:
        print(root.data, end=" ")
        pre_order_traversal(root.left)
        pre_order_traversal(root.right)

# Post-order traversal function
def post_order_traversal(root):
    if root:
        post_order_traversal(root.left)
        post_order_traversal(root.right)
        print(root.data, end=" ")

# Create the root node and add child nodes
root = create_node(1)
root.left = create_node(2)
root.right = create_node(3)
root.left.left = create_node(4)
root.left.right = create_node(5)

# In-order traversal
print("In-order Traversal in Python:", end=" ")
in_order_traversal(root)
print()

# Pre-order traversal
print("Pre-order Traversal in Python:", end=" ")
pre_order_traversal(root)
print()

# Post-order traversal
print("Post-order Traversal in Python:", end=" ")
post_order_traversal(root)
print()








/*

In-order Traversal in C: 4 2 5 1 3 
Pre-order Traversal in C: 1 2 4 5 3 
Post-order Traversal in C: 4 5 2 3 1 

In-order Traversal in Python: 4 2 5 1 3 
Pre-order Traversal in Python: 1 2 4 5 3 
Post-order Traversal in Python: 4 5 2 3 1 


*/