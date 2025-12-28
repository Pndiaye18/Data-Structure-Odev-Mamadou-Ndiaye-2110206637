#include <stdio.h>

#define N 5

int graph[N][N] = {
    {2,1,6,0,9},
    {3,8,7,1,0},
    
};

int visited[N];

// DFS (recursive)
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start) {
    int queue[N];
    int front = 0, rear = 0;
    int i;
    int visitedBFS[N] = {0};

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < N; i++) {
            if (graph[v][i] == 1 && !visitedBFS[i]) {
                queue[rear++] = i;
                visitedBFS[i] = 1;
            }
        }
    }
}

int main() {
    int i;

    printf("DFS Traversal: ");
    for (i = 0; i < N; i++)
        visited[i] = 0;
    DFS(0);

    printf("\nBFS Traversal: ");
    BFS(0);

    return 0;
}
