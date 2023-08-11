/* Write a program to arrange a binary tree with a doubly linked list.  */


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
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

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct TreeNode* concatenate(struct TreeNode* leftList, struct TreeNode* rightList) {
    if (leftList == NULL) {
        return rightList;
    }
    if (rightList == NULL) {
        return leftList;
    }

    struct TreeNode* leftLast = leftList->left;
    struct TreeNode* rightLast = rightList->left;

    leftLast->right = rightList;
    rightList->left = leftLast;

    rightLast->right = leftList;
    leftList->left = rightLast;

    return leftList;
}

struct TreeNode* treeToDLL(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* leftList = treeToDLL(root->left);
    struct TreeNode* rightList = treeToDLL(root->right);

    root->left = root;
    root->right = root;

    leftList = concatenate(leftList, root);
    leftList = concatenate(leftList, rightList);

    return leftList;
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);

    printf("Inorder Traversal of Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    struct TreeNode* head = treeToDLL(root);

    printf("Doubly Linked List from Binary Tree: ");
    struct TreeNode* current = head;
    do {
        printf("%d ", current->data);
        current = current->right;
    } while (current != head);
    printf("\n");

    return 0;
}



/* Inorder Traversal of Binary Tree: 1 2 3 4 5 
Doubly Linked List from Binary Tree: 1 2 3 4 5  */




class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return TreeNode(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

def inorder_traversal(root):
    if root is not None:
        inorder_traversal(root.left)
        print(root.data, end=" ")
        inorder_traversal(root.right)

def concatenate(left_list, right_list):
    if left_list is None:
        return right_list
    if right_list is None:
        return left_list

    left_last = left_list.left
    right_last = right_list.left

    left_last.right = right_list
    right_list.left = left_last

    right_last.right = left_list
    left_list.left = right_last

    return left_list

def tree_to_dll(root):
    if root is None:
        return None

    left_list = tree_to_dll(root.left)
    right_list = tree_to_dll(root.right)

    root.left = root
    root.right = root

    left_list = concatenate(left_list, root)
    left_list = concatenate(left_list, right_list)

    return left_list

def print_dll(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.right
        if current == head:
            break
    print()

if __name__ == "__main__":
    root = None
    root = insert(root, 4)
    insert(root, 2)
    insert(root, 1)
    insert(root, 3)
    insert(root, 5)

    print("Inorder Traversal of Binary Tree:", end=" ")
    inorder_traversal(root)
    print()

    head = tree_to_dll(root)

    print("Doubly Linked List from Binary Tree:", end=" ")
    print_dll(head)
