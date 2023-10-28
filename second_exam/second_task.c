#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TwoDimensionalArray {
    int rows;
    int cols;
    int **data;
};


int main(void)
{
    srand(time(NULL));
    struct TwoDimensionalArray array;
    array.rows = 6;
    array.cols = 6;
    array.data = (int **) malloc(array.rows * sizeof(int *));
    for (int i = 0; i < array.rows; i++) {
        array.data[i] = (int *) malloc(array.cols * sizeof(int));
    }

    for (int i = 0; i < array.rows; i++) {
        for (int j = 0; j < array.cols; j++) {
            array.data[i][j] = -9 + rand()%(10+9);
        }
    }
    printf("_______________________________________________\n");
    for (int i = 0; i < array.rows; i++) {
        for (int j = 0; j < array.cols; j++) {
            if (j == 0)
                printf("|");
            printf("%d ", array.data[i][j]);
        }
        printf("|\n");
    }
    printf("_______________________________________________\n");
    for (int i = 0; i < array.rows; i++) {
        free(array.data[i]);
    }
    free(array.data);

    return EXIT_SUCCESS;
}
