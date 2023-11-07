/**************************************************
* Название: third_task.c                          *
* Задание: Шестая программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdlib.h>
#include <time.h>
#include "third_struct.h"

#define cols_amount 6
#define rows_amount 6

void main_algorithm(Array array)
{
    srand(time(NULL));
    int a[cols_amount];
    for (int row = 0; row < array.rows; row++) {
            int sum_values = 0;
            a[row] = array.data[row][row];
            if (a[row] != 0 && row != 5){
                for (int col = (row + 1); col < array.cols; col++) {
                    sum_values += array.data[row][col];
                }
                array.data[row][row] = sum_values;
        }
    }
    printf("  - Modificated Array: \n");
    output(array);
    printf("  - Vector A (here placed old values of main diagonal): (");
    for(int i = 0; i < cols_amount; ++i)
    {
        printf(" %d,", a[i]);
    }
    printf(")\n");
}


int main(void)
{
    int loop_indicator = 1, rand_man_indicator = 1;
    Array array;
    printf("  Vsevolod Rybnik test 2 task 3 var 26\n");
    while (loop_indicator)
    {
        printf("  - Wanna specify values yourself or get random ones? (`any num` - random, 0 - manually): ");
		rand_man_indicator = GetInt();
        array = make_array(rows_amount, cols_amount, rand_man_indicator);
        printf("  - Original Array: \n");
        output(array);
        main_algorithm(array);
        clean_space(&array);
        printf("  - Wanna new data input? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
