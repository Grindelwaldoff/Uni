#include "third_interface.h"

typedef struct TwoDimensionalArray {
    int rows;
    int cols;
    int **data;
} Array;

Array random_values_for_array(Array array);

Array make_array(int rows, int cols, int rand_man_indicator);

void clean_space(Array *array);

void output(Array array);


