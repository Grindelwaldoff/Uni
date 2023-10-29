#include <stdlib.h>
#include "third_struct.h"


void main_algorithm(Array array)
{
    int a[6] = {};
    int pointer = 0;
    for (int col = 0; col < array.cols; col++) {
        if (col == pointer)
        {
            int sum_values = 0;
            a[pointer] = array.data[pointer][pointer];
            if (a[pointer] != 0){
                for (int row = (pointer + 1); row < array.rows; row++) {
                    sum_values += array.data[col][row];
                }
                array.data[pointer][pointer] = sum_values;
            }
            pointer += 1;
        }
    }
    printf("Modificated Array: \n");
    output(array);
    printf("Vector a (here placed old values of main diagonal): (");
    for(int i = 0; i < 6; ++i)
    {
        printf(" %d, ", a[i]);
    }
    printf(")\n");
}


int main(void)
{
    int loop_indicator = 1, rand_man_indicator = 1;
    Array array;
    printf("Vsevolod Rybnik test 2 task 3 var 26\n");
    while (loop_indicator)
    {
        printf("Wanna specify values yourself or get random ones? (`any num` - random, 0 - manually): ");
		scanf("%d", &rand_man_indicator);
        array = make_array(6, 6, rand_man_indicator);
        printf("Original Array: \n");
        output(array);
        main_algorithm(array);
        clean_space(array);
        printf("Wanna new data input? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
    }

    return EXIT_SUCCESS;
}
