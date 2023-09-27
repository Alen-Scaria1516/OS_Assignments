#include <stdio.h>
#include <pthread.h>

#define MAX_M 100
#define MAX_N 100

int m, n; // Dimensions of the matrices
int matrix1[MAX_M][MAX_N], matrix2[MAX_M][MAX_N], result[MAX_M][MAX_N];

// Structure to pass arguments to the thread function
struct ThreadArgs
{
    int row;
};

// Function to add two matrices, each thread computes a row
void *addMatrixRow(void *arg)
{
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    int row = args->row;

    for (int j = 0; j < n; j++)
    {
        result[row][j] = matrix1[row][j] + matrix2[row][j];
    }

    pthread_exit(NULL);
}

int main()
{
    printf("Enter the number of rows (m) and columns (n) for the matrices: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    pthread_t threads[MAX_M];
    struct ThreadArgs threadArgs[MAX_M];

    // Create m threads
    for (int i = 0; i < m; i++)
    {
        threadArgs[i].row = i;
        pthread_create(&threads[i], NULL, addMatrixRow, &threadArgs[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < m; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}