#include <stdio.h>
#include <stdlib.h>
#define V 4

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m c?nh v�o �? th?
void addEdge(Node* arr[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// In danh s�ch k?
void printList(Node* array[]) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node* temp = array[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // T?o �? th? c� 4 �?nh kh�ng c?nh
    Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Th�m c?nh
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    // In danh s�ch k?
    printList(adj);

    // Gi?i ph�ng b? nh?
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}

