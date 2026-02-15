#include <stdio.h>

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diagonal_sum = 0;

    for (int i = 0; i < m && i < n; i++) {
        diagonal_sum += matrix[i][i];
    }

    printf("%d\n", diagonal_sum);

    return 0;
}
