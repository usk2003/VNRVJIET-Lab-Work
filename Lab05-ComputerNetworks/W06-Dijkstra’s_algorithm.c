#include<stdio.h>
int main() {
    int cost[10][10], i, j, n, source, target, visited[10] = {0}, min, dist[10], pre[10];
    int start, m, d, path[10];

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter weight of all the paths in adjacency matrix form (enter 0 for no path):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) 
                cost[i][j] = 999;  // Assign a high value for no path
        }
    }

    // Input source and target nodes
    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter the target node: ");
    scanf("%d", &target);

    // Initialization for Dijkstra's algorithm
    for(i = 1; i <= n; i++) {
        dist[i] = 999;  // Initially set all distances to infinity (999)
        pre[i] = -1;    // Previous node array initialized to -1
    }

    dist[source] = 0;  // Distance from source to itself is 0
    visited[source] = 1;  // Mark source node as visited

    start = source;

    // Dijkstra's algorithm
    while(visited[target] == 0) {
        min = 999;
        m = 0;
        
        // Find the next node with the minimum distance
        for(i = 1; i <= n; i++) {
            if(visited[i] == 0) {
                d = dist[start] + cost[start][i]; // Calculate the tentative distance
                
                if(d < dist[i]) {
                    dist[i] = d;  // Update the distance
                    pre[i] = start;  // Update the previous node
                }

                if(dist[i] < min) {
                    min = dist[i];

                    m = i;  // Update node with the smallest distance
                }
            }
        }

        start = m;  // Move to the node with the smallest tentative distance
        visited[m] = 1;  // Mark the node as visited
    }

    // Reconstruct the shortest path
    start = target;
    j = 0;
    while(start != -1) {
        path[j++] = start;  // Store the nodes in the path array
        start = pre[start];  // Move to the previous node
    }

    // Print the shortest path
    printf("Shortest path: ");
    for(i = j - 1; i >= 0; i--) {
        if(i != j - 1) printf(" -> ");
        printf("%d", path[i]);
    }

    // Print the distance to the target node
    printf("\nShortest path distance is: %d\n", dist[target]);

    return 0;
}
