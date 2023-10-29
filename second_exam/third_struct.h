#include <time.h>
#include <math.h>
#include "third_interface.h"


struct TwoDimensionalArray {
    int rows;
    int cols;
    int **data;
};


typedef struct TwoDimensionalArray Array;


Array random_values_for_array(Array array)
{
    for (int row = 0; row < array.rows; row++) {
        for (int col = 0; col < array.cols; col++) {
            array.data[row][col] = -99 + rand()%(100 + 98);
        }
    }
    return array;
}


Array make_array(int rows, int cols, int rand_man_indicator)
{
    srand(time(NULL));
    Array array;
    array.rows = rows;
    array.cols = cols;
    array.data = (int **) malloc(array.rows * sizeof(int *));
    for (int row = 0; row < array.rows; row++) {
        array.data[row] = (int *) malloc(array.cols * sizeof(int));
    }
    if (rand_man_indicator){
        return random_values_for_array(array);
    }
    else
    {
        for (int row = 0; row < array.rows; row++) {
            for (int col = 0; col < array.cols; col++) {
                printf("Specify %d %d element of Matrix: ", col, row);
                array.data[row][col] = GetInt();
            }
    }
    }
    return array;
}


void clean_space(Array array)
{
    for (int row_index = 0; row_index < array.rows; row_index++) {
        free(array.data[row_index]);
    }
    free(array.data);
}


void output(Array array)
{
    printf(" _____________________________________\n");
    for (int row = 0; row < array.rows; row++) {
        for (int col = 0; col < array.cols; col++) {
            if (col == 0)
                printf("|");
            if (array.data[row][col] < 0 && floor(log10(abs(array.data[row][col]))) + 1 == 1)
                printf("   ");
            else if (array.data[row][col] < 0 && floor(log10(abs(array.data[row][col]))) + 1 == 2)
                printf("  ");
            else if (array.data[row][col] > 0 && floor(log10(abs(array.data[row][col]))) + 1 == 2)
                printf("   ");
            else if (array.data[row][col] > 0 && floor(log10(abs(array.data[row][col]))) + 1 == 3)
                printf("  ");
            else if (array.data[row][col] < 0 && floor(log10(abs(array.data[row][col]))) + 1 == 3)
                printf(" ");
            else
                printf("    ");
            printf("%d ", array.data[row][col]);
        }
        printf(" |\n");
    }
    printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}
