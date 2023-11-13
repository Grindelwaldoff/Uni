#include <math.h>
#include <locale.h>
#include <stdio.h>
#include "third_interface.h"


#define upper_left_border 218
#define upper_right_border 191
#define lower_left_border 192
#define lower_right_border 217
#define underline 196
#define underline_amount 38
#define aside_border 179


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
                printf("  - Specify %d %d element of Matrix: ", row+1, col+1);
                array.data[row][col] = GetInt();
            }
    }
    }
    return array;
}


void clean_space(Array *array)
{
    for (int row_index = 0; row_index < array->rows; row_index++) {
        free(array->data[row_index]);
        array->data[row_index] = NULL;
    }
    free(array->data);
    array->data = NULL;
}


void output(Array array)
{
    printf("  %c", upper_left_border);
	for (int i = 1; i < underline_amount; i++)
		printf("%c", underline);
	printf("%c\n", upper_right_border);
    for (int row = 0; row < array.rows; row++) {
        for (int col = 0; col < array.cols; col++) {
            if (col == 0)
                printf("  %c", aside_border);
			if (array.data[row][col] >= 0)
				printf(" ");
			double digits = floor(log10(abs(array.data[row][col]))) + 1;
			printf("%*s", digits == 2? 2 : digits == 3? 1 : 3, " ");
            printf("%d ", array.data[row][col]);
        }
        printf(" %c\n", aside_border);
    }
	printf("  %c", lower_left_border);
	for (int i = 1; i < underline_amount; i++)
		printf("%c", underline);
	printf("%c\n", lower_right_border);
}
