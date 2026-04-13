#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], indegree[MAX], n;

void sourceRemovalTopoSort() {
    int count = 0;

    // Step 1: Initialize indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Step 2: Compute indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("Topological Order:\n");

    // Step 3: Source removal process
    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                printf("%d ", i);

                // Mark as removed
                indegree[i] = -1;

                // Reduce indegree of adjacent vertices
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1) {
                        indegree[j]--;
                    }
                }

                found = 1;
                count++;
            }
        }

        // Cycle detection
        if (!found) {
            printf("\nGraph has a cycle! Topological sort not possible.\n");
            return;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    sourceRemovalTopoSort();

    return 0;
}
