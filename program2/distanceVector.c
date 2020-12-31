#include <stdio.h>

int A[10][10], n, d[10], p[10];

int bellman_ford() {
    int i, u, v;
    for (int i = 0; i < n; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (d[v] > d[u] + A[u][v]) {
                    d[v] = d[u] + A[u][v];
                    p[v] = u;
                }
            }
        }
    }
    for (u = 0; u < n; u++) {
        for (v = 0; v < n; v++) {
            if (d[v] > d[u] + A[u][v]) {
                printf("Detected negative edge\n");
                return -1;
            }
        }
    }
    return 0;
}

int main() {
    printf("N: ");
    scanf("%d", &n);
    printf("Matrix: \n");
    int source = 0, destination = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for(source = 0; source < n; source++) {

        for(destination = 0; destination < n; destination++){

            for (int i = 0; i < n; i++) {
                d[i] = 999;
                p[i] = -1;
            }

            d[source] = 0;

            int valid = bellman_ford();

            if (valid == -1) {
                printf("Graph contains negative edge\n");
                return 0;
            }

            printf("\nFrom Router %d to Router %d\n", source+1, destination+1);

            printf("Cost: %2d | Path: ", d[destination]);
            if(destination != source){
                int j = destination;
                while(p[j] != -1){
                    printf("%d <- ",j+1);
                    j = p[j];
                }
            }
            
            printf("%d\n",source+1);

        }

    }
}

// 0 1 5 999 999
// 1 0 3 999 9
// 5 3 0 4 999
// 999 999 4 0 2
// 999 9 999 2 0
