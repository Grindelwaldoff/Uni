/**************************************************
* Название: second_task.c                          *
* Задание: Пятая программа в осеннем семестре *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 7


double * slice(double *arr, size_t start, size_t end)
{
    return memcpy(malloc(sizeof(int)*(end-start)), arr+start, sizeof(int)*(end-start));
}


double GetDouble(void)
{
    char temprem, tempclear; // временный остаток
    double input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%lf%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("  - Error: Invalid value for double variables.\n  - One more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}


double find_endpoints(double *order)
{
    double *first_array, *second_array;
    int border = ARRAY_SIZE / 2;
    first_array = order(0, border);
    second_array = slice(order, border, ARRAY_SIZE+1);
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%f ", first_array[i]);
    printf("\n");
    for (int i = 0; i < 4; i++)
        printf("%f ", second_array[i]);
    printf("\n");
}


void main_algorithm(double *order)
{
    double min, max;
    find_endpoints(order);
}



int main(void)
{
    int rand_man_indicator = 1, loop_indicator = 1;
    NSArray *order = {1, 2, 3, 4, 5, 6, 7};
    printf("  Vsevolod Rybnik test 2 task 3 var 26\n");
    while (loop_indicator)
    {
        // for (int digit = 0; digit < ARRAY_SIZE; digit++)
        // {
        //     printf("  - Specify %i value: ", digit+1);
        //     order[digit] = GetDouble();
        // }
        main_algorithm(order);
        printf("  - Wanna new data input? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
