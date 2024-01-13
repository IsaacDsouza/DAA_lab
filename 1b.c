//. Write a program to implement the following graph representations and display 
//i. Adjacency list
//ii. Adjacency matrix
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Node{
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};
struct Node* createNode(int vertex){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=vertex;
    newNode->next=NULL;
    return newNode;
}
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=numVertices;
    for(int i=0; i<numVertices;i++){
        graph->adjList[i]=NULL;

    }
    return graph;
    
}
void addEdge(struct Graph* graph, int src, int dest){
    struct Node *newNode =createNode(dest);
    newNode->next=graph->adjList[src];
    graph->adjList[src]=newNode;

    newNode= createNode(src);
    newNode->next=graph->adjList[dest];
    graph->adjList[dest]=newNode;


}
void displayAdjList(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        struct Node* current = graph->adjList[i];
        while (current) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void displayAdjMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            int isEdge = 0;
            struct Node* current = graph->adjList[i];
            while (current) {
                if (current->vertex == j) {
                    isEdge = 1;
                    break;
                }
                current = current->next;
            }
            printf("%d ", isEdge);
        }
        printf("\n");
    }
}
int main() {
    
    struct Graph* graph = createGraph(5);

    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayAdjList(graph);

    
    displayAdjMatrix(graph);

    return 0;
}

