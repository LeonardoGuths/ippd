#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int solve(int **board, int row, int n);
int isSafe(int **board, int row, int col, int n);

int main(int argc, char *argv[]) {
    int n, solutions;
    n = atoi(argv[1]);

    int t;
    if (argc < 3)
        t = 0;
    else
        t = atoi(argv[2]);

    omp_set_num_threads(t);

    int **board = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    double start_time = omp_get_wtime();
    #pragma omp parallel reduction(+:solutions)
    {
        printf("oi da tred %d\n",omp_get_thread_num());
        int **board_copy = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            board_copy[i] = (int *) malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                board_copy[i][j] = 0;
            }
        }

        #pragma omp for
        for (int col = 0; col < n; col++) {
            board_copy[0][col] = 1;
            solutions += solve(board_copy, 1, n);
            board_copy[0][col] = 0;
        }

        for (int i = 0; i < n; i++) {
            free(board_copy[i]);
        }
        free(board_copy);
    }
    double end_time = omp_get_wtime();

    printf("Solucoes: %d\n", solutions);
    printf("Tempo de execucao: %fs\n", end_time - start_time);

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

int solve(int **board, int row, int n) {
    int solutions = 0;

    if (row == n) {
        return 1;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solutions += solve(board, row + 1, n);
            board[row][col] = 0;
        }
    }

    return solutions;
}

int isSafe(int **board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return 0;
    }

    return 1;
}