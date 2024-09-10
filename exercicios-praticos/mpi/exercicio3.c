/**
 *   Giovana Nogueira Oliveira - 2022.1.08.005
**/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Função para preencher a matriz com números aleatórios de 0 a 9
void fill_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i * cols + j] = rand() % 10; 
        }
    }
}

// Função para imprimir a matriz
void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Função para somar duas submatrizes
void sum_matrices(int* sub_matrix_A, int* sub_matrix_B, int dimension, int* sub_result) {
    for (int i = 0; i < dimension; ++i) {
        sub_result[i] = sub_matrix_A[i] + sub_matrix_B[i];
    }
}


// Função para calcular send_counts e displs para MPI_Scatterv e MPI_Gatherv
void calculate_send_counts_and_displs(int world_size, int rows, int cols, int rows_per_proc, int extra_rows, int *send_counts, int *displs) {
    int offset = 0;
    for (int i = 0; i < world_size; ++i) {
        if (i < extra_rows) {
            send_counts[i] = (rows_per_proc + 1) * cols;
        } else {
            send_counts[i] = rows_per_proc * cols;
        }
        displs[i] = offset;
        offset += send_counts[i];
    }
}


int main(int argc, char *argv[]) 
{
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Lê as dimensões da matriz
    int rows, cols;
    if (argc != 3) {
        if (world_rank == 0) {
            fprintf(stderr, "Usage: %s <rows> <cols>\n", argv[0]);
        }
        MPI_Finalize();
        return EXIT_FAILURE;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    int total_elements = rows * cols;
    int rows_per_proc = rows / world_size;
    int extra_rows = rows % world_size;

    // Calcula send_counts e displs
    int *send_counts = (int *)malloc(world_size * sizeof(int));
    int *displs = (int *)malloc(world_size * sizeof(int));

    // Calcula quantos elementos cada processo receberá e os deslocamentos
    calculate_send_counts_and_displs(world_size, rows, cols, rows_per_proc, extra_rows, send_counts, displs);
    
    // Aloca memória para matrizes e resultado
    int *matrix_A = NULL;
    int *matrix_B = NULL;
    int *matrix_C = NULL;
    int *sub_matrix_A, *sub_matrix_B, *sub_result;

    if (world_rank == 0) {
        matrix_A = (int *)malloc(total_elements * sizeof(int));
        matrix_B = (int *)malloc(total_elements * sizeof(int));
        matrix_C = (int *)malloc(total_elements * sizeof(int));

        fill_matrix(matrix_A, rows, cols);
        fill_matrix(matrix_B, rows, cols);

        printf("Matrix A:\n");
        print_matrix(matrix_A, rows, cols);

        printf("Matrix B:\n");
        print_matrix(matrix_B, rows, cols);
    }

    // Aloca memória para as submatrizes e o resultado
    int sub_rows = (world_rank < extra_rows) ? (rows_per_proc + 1) : rows_per_proc;
    sub_matrix_A = (int *)malloc(sub_rows * cols * sizeof(int));
    sub_matrix_B = (int *)malloc(sub_rows * cols * sizeof(int));
    sub_result = (int *)malloc(dimension * sizeof(int));

    // Dispersa as submatrizes para todos os processos
    MPI_Scatterv(matrix_A, send_counts, displs, MPI_INT, sub_matrix_A, sub_rows * cols, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatterv(matrix_B, send_counts, displs, MPI_INT, sub_matrix_B, sub_rows * cols, MPI_INT, 0, MPI_COMM_WORLD);
    sum_matrices(sub_matrix_A, sub_matrix_B, sub_rows * cols, sub_result);

    // Reúne o resultado de todos os processos no processo 0
    MPI_Gatherv(sub_result, sub_rows * cols, MPI_INT, matrix_C, send_counts, displs, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printf("Matrix C:\n");
        print_matrix(matrix_C, rows, cols);
    
        // Liberar a memória
        free(matrix_A);
        free(matrix_B);
        free(matrix_C);
    }

    // Liberar a memória
    free(sub_matrix_A);
    free(sub_matrix_B);
    free(sub_result);
    free(send_counts);
    free(displs);

    MPI_Finalize();
    return EXIT_SUCCESS;
}