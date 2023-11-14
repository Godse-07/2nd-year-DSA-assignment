/* Write a program to find mirror image of a BST. 
 */


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
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

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to mirror a BST
struct Node* mirrorBST(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap left and right subtrees
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorBST(root->left);
    mirrorBST(root->right);

    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display original BST
    printf("Original BST (in-order): ");
    inOrderTraversal(root);
    printf("\n");

    // Mirror the BST
    root = mirrorBST(root);

    // Display mirrored BST
    printf("Mirrored BST (in-order): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}



//python code
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to insert a value into the BST
def insert(root, data):
    if root is None:
        return Node(data)

    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)

    return root

# Function to perform in-order traversal of the BST
def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(root.data, end=" ")
        in_order_traversal(root.right)

# Function to mirror a BST
def mirror_bst(root):
    if root is None:
        return None

    # Swap left and right subtrees
    root.left, root.right = root.right, root.left

    # Recursively mirror the left and right subtrees
    mirror_bst(root.left)
    mirror_bst(root.right)

    return root

# Example usage
root = None

# Insert values into the BST
root = insert(root, 50)
insert(root, 30)
insert(root, 20)
insert(root, 40)
insert(root, 70)
insert(root, 60)
insert(root, 80)

# Display original BST
print("Original BST (in-order): ", end="")
in_order_traversal(root)
print()

# Mirror the BST
root = mirror_bst(root)

# Display mirrored BST
print("Mirrored BST (in-order): ", end="")
in_order_traversal(root)
print()



/*
Original BST (in-order): 20 30 40 50 60 70 80 
Mirrored BST (in-order): 80 70 60 50 40 30 20 
*/