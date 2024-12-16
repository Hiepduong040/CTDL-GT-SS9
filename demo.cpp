#include <stdio.h>
#include <stdlib.h>
#define V 4

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm c?nh vào ð? th?
void addEdge(Node* arr[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// In danh sách k?
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
    // T?o ð? th? có 4 ð?nh không c?nh
    Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Thêm c?nh
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    // In danh sách k?
    printList(adj);

    // Gi?i phóng b? nh?
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

