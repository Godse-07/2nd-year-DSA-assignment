/* Write a program to sort a given set of numbers using BST */

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

// Function to perform in-order traversal of the BST and print the sorted numbers
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to sort an array using BST
void sortArrayWithBST(int arr[], int n) {
    struct Node* root = NULL;

    // Insert numbers into the BST
    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i]);
    }

    // Perform in-order traversal to print the sorted numbers
    printf("Sorted numbers using BST: ");
    inOrderTraversal(root);
    printf("\n");
}

int main() {
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using BST
    sortArrayWithBST(arr, n);

    return 0;
}



//python
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

# Function to perform in-order traversal of the BST and print the sorted numbers
def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(root.data, end=" ")
        in_order_traversal(root.right)

# Function to sort an array using BST
def sort_array_with_bst(arr):
    root = None

    # Insert numbers into the BST
    for num in arr:
        root = insert(root, num)

    # Perform in-order traversal to print the sorted numbers
    print("Sorted numbers using BST:", end=" ")
    in_order_traversal(root)
    print()

# Example usage
arr = [50, 30, 20, 40, 70, 60, 80]
sort_array_with_bst(arr)




/*
Sorted numbers using BST: 20 30 40 50 60 70 80
*/