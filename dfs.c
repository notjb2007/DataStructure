#include <stdio.h>

int visited[20], n, a[20][20];

void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for(i = 1; i <= n; i++) {
        if(a[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(start);
    return 0;
}
