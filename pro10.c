#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int x, int y) {
    return ((x > y) ? x : y);
}

void knap(int n, int w[], int value[], int m, int v[][10]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], value[i] + v[i - 1][j - w[i]]);
            }
        }
    }

    printf("The solution for solving the knapsack problem:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, w[10], value[10], m, v[10][10];
    double clk;
    clock_t start, end;

    printf("Enter the number of items:\n");
    scanf("%d", &n);

    printf("Enter the weight of each item:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the value of each item:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack:\n");
    scanf("%d", &m);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] = 0;
        }
    }

    start = clock();
    knap(n, w, value, m, v);
    end = clock();

    clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", clk);

    return 0;
}