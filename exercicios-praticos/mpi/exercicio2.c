/**
 *   Giovana Nogueira Oliveira - 2022.1.08.005
 */

#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int MAX_NUMBERS = 2000;
    int numbers[MAX_NUMBERS];
    int result_sum = 0;
    int number_amount;

    MPI_Status status;

    if (world_rank == 0) {
        
        srand(time(NULL));

        for (int j = 1; j < world_size; j++) {
            number_amount = number_amount = (rand() % 1001) + 1000;

            for (int i = 0; i < number_amount; i++) {
                numbers[i] = rand() % 100;
            }

            MPI_Send(&number_amount, 1, MPI_INT, j, 0, MPI_COMM_WORLD);
            MPI_Send(numbers, MAX_NUMBERS, MPI_INT, j, 0, MPI_COMM_WORLD);
        }

        for (int i = 1; i < world_size * 4; i++) {
            int value;
            MPI_Recv(&value, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            number_amount = number_amount = (rand() % 1001) + 1000;

            for (int i = 0; i < number_amount; i++) {
                numbers[i] = rand() % 100;
            }

            MPI_Send(&number_amount, 1, MPI_INT, status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD);
            MPI_Send(numbers, MAX_NUMBERS, MPI_INT, status.MPI_SOURCE, status.MPI_TAG, MPI_COMM_WORLD);

            result_sum += value;
        }

        for (int j = 1; j < world_size; j++) {
            MPI_Send(&number_amount, 1, MPI_INT, j, 1, MPI_COMM_WORLD);
        }

        printf("Final sum: %d\n", result_sum);
    }
    else{
        do
        {
            MPI_Recv(&number_amount, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            if (number_amount != -1) {
                MPI_Recv(numbers, 2000, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                for (int i = 0; i < number_amount; i++) {
                    result_sum += numbers[i];
                }
                MPI_Send(&result_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }

        } while (status.MPI_TAG != 1);
    }

    MPI_Finalize();
}