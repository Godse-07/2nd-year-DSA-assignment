/* Write a program to check whether a tree is full or complete.  */

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

// Function to check if a binary tree is full
int isFull(struct Node* root) {
    // An empty tree is full
    if (root == NULL)
        return 1;

    // If the tree is not empty and has only one child, it is not full
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        return 0;

    // Recursively check the left and right subtrees
    return isFull(root->left) && isFull(root->right);
}

// Function to check if a binary tree is complete
int isComplete(struct Node* root, int index, int nodeCount) {
    // An empty tree is complete
    if (root == NULL)
        return 1;

    // Check if the index of the current node is less than the number of nodes in the tree
    if (index >= nodeCount)
        return 0;

    // Recursively check the left and right subtrees
    return isComplete(root->left, 2 * index + 1, nodeCount) && isComplete(root->right, 2 * index + 2, nodeCount);
}

// Function to count the number of nodes in a binary tree
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Create a full binary tree
    struct Node* fullTree = createNode(1);
    fullTree->left = createNode(2);
    fullTree->right = createNode(3);
    fullTree->left->left = createNode(4);
    fullTree->left->right = createNode(5);
    fullTree->right->left = createNode(6);
    fullTree->right->right = createNode(7);

    // Check if the full tree is full and complete
    if (isFull(fullTree))
        printf("The tree is full.\n");
    else
        printf("The tree is not full.\n");

    if (isComplete(fullTree, 0, countNodes(fullTree)))
        printf("The tree is complete.\n");
    else
        printf("The tree is not complete.\n");

    return 0;
}




//python code
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to check if a binary tree is full
def is_full(root):
    if root is None:
        return True

    if (root.left is None and root.right is not None) or (root.left is not None and root.right is None):
        return False

    return is_full(root.left) and is_full(root.right)

# Function to check if a binary tree is complete
def is_complete(root, index, node_count):
    if root is None:
        return True

    if index >= node_count:
        return False

    return is_complete(root.left, 2 * index + 1, node_count) and is_complete(root.right, 2 * index + 2, node_count)

# Function to count the number of nodes in a binary tree
def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

# Create a full binary tree
full_tree = Node(1)
full_tree.left = Node(2)
full_tree.right = Node(3)
full_tree.left.left = Node(4)
full_tree.left.right = Node(5)
full_tree.right.left = Node(6)
full_tree.right.right = Node(7)

# Check if the full tree is full and complete
if is_full(full_tree):
    print("The tree is full.")
else:
    print("The tree is not full.")

if is_complete(full_tree, 0, count_nodes(full_tree)):
    print("The tree is complete.")
else:
    print("The tree is not complete.")





/*
The tree is full.
The tree is complete.
*/