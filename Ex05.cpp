#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Ham Dijkstra tinh khoang cach ngan nhat tu dinh bat dau den cac dinh con lai
void dijkstra(int graph[MAX][MAX], int n, int BATDAU) {
    int distance[MAX];
    int visited[MAX] = {0};
    int i, j, minDistance, nextVertex;

    // Khoi tao mang khoang cach voi gia tri vo cung (INF)
    for (i = 0; i < n; i++) {
        distance[i] = INF;
    }
    distance[BATDAU] = 0;  // Khoang cach tu dinh bat dau toi chinh no la 0

    // Tim cac dinh co khoang cach ngan nhat
    for (i = 0; i < n - 1; i++) {
        minDistance = INF;
        
        // Tim dinh chua duoc tham va co khoang cach ngan nhat
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                nextVertex = j;
            }
        }
        
        visited[nextVertex] = 1;  // Danh dau dinh da duoc tham

        // Cap nhat khoang cach cho cac dinh lan can
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[nextVertex][j] != 0 && distance[nextVertex] != INF &&
                distance[nextVertex] + graph[nextVertex][j] < distance[j]) {
                distance[j] = distance[nextVertex] + graph[nextVertex][j];
            }
        }
    }

    // In ra khoang cach ngan nhat tu dinh bat dau den cac dinh khac
    printf("Khoang cach ngan nhat tu dinh %d den cac dinh khac:\n", BATDAU);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("Dinh %d: Khong the di toi\n", i);
        } else {
            printf("Dinh %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX];
    int n, edges, i, j, BATDAU, DINH1, DINH2, weight;

    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &edges);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach cac canh (DINH1 DINH2 trong so):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &DINH1, &DINH2, &weight);
        graph[DINH1][DINH2] = weight;   
        graph[DINH2][DINH1] = weight;   
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &BATDAU);

    dijkstra(graph, n, BATDAU);

    return 0;
}
