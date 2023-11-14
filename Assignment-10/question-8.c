/* Write a program to print adjacency list of a given graph.  */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
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

void printGraph(struct AdjList* graph, int V) {
    for (int i = 0; i < V; ++i) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* current = graph[i].head;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
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

    // Print the adjacency list
    printGraph(graph, V);

    return 0;
}



//python code
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class AdjList:
    def __init__(self):
        self.head = None

def create_graph(V):
    graph = [AdjList() for _ in range(V)]
    return graph

def add_edge(graph, src, dest):
    new_node = Node(dest)
    new_node.next = graph[src].head
    graph[src].head = new_node

    # For an undirected graph, add an edge from dest to src as well
    new_node = Node(src)
    new_node.next = graph[dest].head
    graph[dest].head = new_node

def print_graph(graph, V):
    for i in range(V):
        print(f"Adjacency list of vertex {i}: ", end="")
        current = graph[i].head
        while current:
            print(f"{current.data} -> ", end="")
            current = current.next
        print("NULL")

# Number of vertices
V = 5

# Create a graph with 5 vertices
graph = create_graph(V)

# Add edges to the graph
add_edge(graph, 0, 1)
add_edge(graph, 0, 4)
add_edge(graph, 1, 2)
add_edge(graph, 1, 3)
add_edge(graph, 1, 4)
add_edge(graph, 2, 3)
add_edge(graph, 3, 4)

# Print the adjacency list
print_graph(graph, V)



/*Adjacency list of vertex 0: 4 -> 1 -> NULL
Adjacency list of vertex 1: 4 -> 3 -> 2 -> 0 -> NULL
Adjacency list of vertex 2: 3 -> 1 -> NULL
Adjacency list of vertex 3: 4 -> 2 -> 1 -> NULL
Adjacency list of vertex 4: 3 -> 1 -> 0 -> NULL
*/
