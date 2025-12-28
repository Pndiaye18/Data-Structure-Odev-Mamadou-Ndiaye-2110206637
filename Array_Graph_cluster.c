#include <stdio.h>

#define N 6   // number of vertices

int graph[N][N] = {
    {1,2,3,4,5,6},
    {7,8,9,10,11,0},
    
};

int visited[N];

// DFS function
void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, cluster = 0;

    for (i = 0; i < N; i++)
        visited[i] = 0;

    printf("Clusters in the graph:\n");

    for (i = 0; i < N; i++) {
        if (!visited[i]) {
            cluster++;
            printf("Cluster %d: ", cluster);
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}
