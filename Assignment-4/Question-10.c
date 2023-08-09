/* Write a program to perform addition of two polynomials using linked list */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;
    }
    return newNode;
}

void insertTerm(Node **head, int coeff, int exp) {
    Node *newNode = createNode(coeff, exp);
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coeff, temp->exp);
        if (temp->next != NULL && temp->next->coeff > 0) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void freePolynomial(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 3, 3);
    insertTerm(&poly2, -2, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Node *result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}




/* Polynomial 1: (5x^2) + (4x^1) + (2x^0) 
Polynomial 2: (3x^3) (-2x^2) + (1x^0) 
Resultant Polynomial: (3x^3) + (3x^2) + (4x^1) + (3x^0)  */




class Node:
    def __init__(self, coeff, exp):
        self.coeff = coeff
        self.exp = exp
        self.next = None

def insert_term(head, coeff, exp):
    new_node = Node(coeff, exp)
    if not head:
        return new_node
    
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = new_node
    return head

def display_polynomial(head):
    temp = head
    while temp:
        if temp.coeff != 0:
            print(f"({temp.coeff}x^{temp.exp})", end=" ")
            if temp.next and temp.next.coeff > 0:
                print("+", end=" ")
        temp = temp.next
    print()

def add_polynomials(poly1, poly2):
    result = None

    while poly1 and poly2:
        if poly1.exp > poly2.exp:
            result = insert_term(result, poly1.coeff, poly1.exp)
            poly1 = poly1.next
        elif poly1.exp < poly2.exp:
            result = insert_term(result, poly2.coeff, poly2.exp)
            poly2 = poly2.next
        else:
            result = insert_term(result, poly1.coeff + poly2.coeff, poly1.exp)
            poly1 = poly1.next
            poly2 = poly2.next

    while poly1:
        result = insert_term(result, poly1.coeff, poly1.exp)
        poly1 = poly1.next

    while poly2:
        result = insert_term(result, poly2.coeff, poly2.exp)
        poly2 = poly2.next

    return result

def free_polynomial(head):
    temp = head
    while temp:
        next_node = temp.next
        del temp
        temp = next_node

if __name__ == "__main__":
    poly1 = None
    poly2 = None

    poly1 = insert_term(poly1, 5, 2)
    poly1 = insert_term(poly1, 4, 1)
    poly1 = insert_term(poly1, 2, 0)

    poly2 = insert_term(poly2, 3, 3)
    poly2 = insert_term(poly2, -2, 2)
    poly2 = insert_term(poly2, 1, 0)

    print("Polynomial 1:", end=" ")
    display_polynomial(poly1)
    print("Polynomial 2:", end=" ")
    display_polynomial(poly2)

    result = add_polynomials(poly1, poly2)

    print("Resultant Polynomial:", end=" ")
    display_polynomial(result)

    free_polynomial(poly1)
    free_polynomial(poly2)
    free_polynomial(result)
