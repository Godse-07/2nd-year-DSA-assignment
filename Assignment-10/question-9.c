/* Write a program to implement BFS algorithm.  */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
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

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }

    int data = queue->front->data;
    struct QueueNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

void BFS(struct AdjList* graph, int V, int startVertex) {
    int visited[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = 0;
    }

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (queue->front != NULL) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(queue);
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

    BFS(graph, V, 0);

    return 0;
}


//output
Breadth-First Search starting from vertex 0: 0 1 4 2 3 




//python
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class AdjList:
    def __init__(self):
        self.head = None

class QueueNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

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

def enqueue(queue, data):
    new_node = QueueNode(data)

    if not queue.rear:
        queue.front = queue.rear = new_node
        return

    queue.rear.next = new_node
    queue.rear = new_node

def dequeue(queue):
    if not queue.front:
        return -1

    data = queue.front.data
    temp = queue.front

    queue.front = queue.front.next

    if not queue.front:
        queue.rear = None

    del temp

    return data

def BFS(graph, V, start_vertex):
    visited = [0] * V

    queue = Queue()
    queue.front = queue.rear = None

    visited[start_vertex] = 1
    enqueue(queue, start_vertex)

    print(f"Breadth-First Search starting from vertex {start_vertex}: ", end="")

    while queue.front:
        current_vertex = dequeue(queue)
        print(current_vertex, end=" ")

        temp = graph[current_vertex].head
        while temp:
            adj_vertex = temp.data
            if not visited[adj_vertex]:
                visited[adj_vertex] = 1
                enqueue(queue, adj_vertex)
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

    BFS(graph, V, 0)
