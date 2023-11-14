/* Write a program to create a binary tree.  */

    1
   / \
  2   3
 / \
4   5



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

int main() {
    // Create the root node and add child nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the binary tree
    printf("Binary Tree in C:\n");
    printf("   %d\n", root->data);
    printf("  / \\\n");
    printf(" %d   %d\n", root->left->data, root->right->data);
    printf("/ \\\n");
    printf("%d   %d\n", root->left->left->data, root->left->right->data);

    return 0;
}






class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to create a new node
def create_node(data):
    return Node(data)

# Create the root node and add child nodes
root = create_node(1)
root.left = create_node(2)
root.right = create_node(3)
root.left.left = create_node(4)
root.left.right = create_node(5)

# Print the binary tree
print("Binary Tree in Python:")
print("   {}".format(root.data))
print("  / \\")
print(" {}   {}".format(root.left.data, root.right.data))
print("/ \\")
print("{}   {}".format(root.left.left.data, root.left.right.data))
