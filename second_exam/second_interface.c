#include <stdio.h>
#include <stdbool.h>
#include "second_hash_table_module.h"


int GetInt(void)
{
    char temprem, tempclear;
    int input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%d%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("  - Error: Invalid value for int variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}


double GetDouble(char *label, int position)
{
    char temprem, tempclear; // временный остаток
    double input  = 0;
    while(true)
    {
        printf("%s%d: ", label, position+1);
        temprem = 0;
        tempclear = 0;
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


void output(char *name, int left_border, int right_border, double order[])
{
    printf("%s order: (%0.2f", name, order[left_border]);
    if (right_border != 0)
    {
        for (int i = left_border+1; i < right_border; i++)
            printf(", %0.2f", order[i]);
    }
    printf(")\n");
}



double* input(double order[], double (*input_type)(char *, int), HashTable* min_max_table, char *label, int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        order[i] = input_type(label, i);
        min_max_table = max_min_finder(order[i], min_max_table, i);
    }
    return order;
}
