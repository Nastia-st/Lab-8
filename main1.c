#include <stdio.h>
#include <limits.h> 
#define M 3  
#define K 2  
#define N 4  

int main() {
    system("chcp 65001");
    int A[M][K], B[K][N], C[M][N];
    printf("Введіть матрицю A (%d x %d):\n", M, K);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            scanf("%d", &A[i][j]);

    printf("Введіть матрицю B (%d x %d):\n", K, N);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    int max = INT_MIN;
    int max_row = -1, max_col = -1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] > max) {
                max = C[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    printf("\nМатриця C = A × B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nНайбільший елемент: %d (рядок %d, стовпчик %d)\n",
           max, max_row, max_col);
    return 0;
}
