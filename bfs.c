#include <stdio.h>

int queue[20], front = -1, rear = -1, visited[20], a[20][20], n;

void enqueue(int vertex) {
    if(rear == 19)
        printf("Queue is full\n");
    else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if(front == -1 || front > rear) {
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

void bfs(int start) {
    int i, vertex;
    enqueue(start);
    visited[start] = 1;
    while(front <= rear) {
        vertex = dequeue();
        if(vertex == -1) break;
        printf("%d ", vertex);
        for(i = 1; i <= n; i++) {
            if(a[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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
    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start);
    return 0;
}
