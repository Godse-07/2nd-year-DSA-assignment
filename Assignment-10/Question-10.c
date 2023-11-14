/* Write a program to implement DFS algorithm.  */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct AdjList* createGraph(int V) {
    struct AdjList* graph = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i) {
        graph[i].head = NULL;
    }

    return graph;
}

void addEdge(struct AdjList* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src].head;
    graph[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest].head;
    graph[dest].head = newNode;
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }

    int data = stack->top->data;
    struct StackNode* temp = stack->top;

    stack->top = stack->top->next;
    free(temp);

    return data;
}

void DFS(struct AdjList* graph, int V, int startVertex) {
    int visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = 0;
    }

    struct Stack stack;
    stack.top = NULL;

    push(&stack, startVertex);

    printf("Depth-First Search starting from vertex %d: ", startVertex);

    while (stack.top != NULL) {
        int currentVertex = pop(&stack);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }

        struct Node* temp = graph[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                push(&stack, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int V = 5;

    struct AdjList* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    DFS(graph, V, 0);

    return 0;
}


//output
Depth-First Search starting from vertex 0: 0 4 1 3 2 



//python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class AdjList:
    def __init__(self):
        self.head = None

class StackNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

def create_graph(V):
    graph = [AdjList() for _ in range(V)]
    return graph

def add_edge(graph, src, dest):
    new_node = Node(dest)
    new_node.next = graph[src].head
    graph[src].head = new_node

    new_node = Node(src)
    new_node.next = graph[dest].head
    graph[dest].head = new_node

def push(stack, data):
    new_node = StackNode(data)
    new_node.next = stack.top
    stack.top = new_node

def pop(stack):
    if not stack.top:
        return -1

    data = stack.top.data
    temp = stack.top

    stack.top = stack.top.next
    del temp

    return data

def DFS(graph, V, start_vertex):
    visited = [0] * V

    stack = Stack()
    stack.top = None

    push(stack, start_vertex)

    print(f"Depth-First Search starting from vertex {start_vertex}: ", end="")

    while stack.top:
        current_vertex = pop(stack)

        if not visited[current_vertex]:
            print(current_vertex, end=" ")
            visited[current_vertex] = 1

        temp = graph[current_vertex].head
        while temp:
            adj_vertex = temp.data
            if not visited[adj_vertex]:
                push(stack, adj_vertex)
            temp = temp.next

    print()

if __name__ == "__main__":
    V = 5

    graph = create_graph(V)

    add_edge(graph, 0, 1)
    add_edge(graph, 0, 4)
    add_edge(graph, 1, 2)
    add_edge(graph, 1, 3)
    add_edge(graph, 1, 4)
    add_edge(graph, 2, 3)
    add_edge(graph, 3, 4)

    DFS(graph, V, 0)
