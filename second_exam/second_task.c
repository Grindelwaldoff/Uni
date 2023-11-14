/**************************************************
* Название: second_task.c                         *
* Задание: Пятая программа в осеннем семестре     *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "second_interface_module.h"

#define ARRAY_SIZE 5


enum MENU {ManualInput=1, RandomInput=2, Quit =3};


void Calculation(double order[], HashTable* min_max_table)
{
    output("Original", 0, ARRAY_SIZE, order);
    int slice = (((int) get(min_max_table, "min_index")) + ((int) get(min_max_table, "max_index"))) /2;
    printf("%d %d\n", (int) get(min_max_table, "min_index"), (int) get(min_max_table, "max_index"));
    output("X", 0, slice, order);
    output("Y", slice, ARRAY_SIZE, order);
}


double random_value(char *name, int i)
{
    return round(-9999 + rand()%(10000 + 9800))/100;
}



int main(void)
{
    srand(time(NULL));
    int options = 1, loop_indicator = 1;
    double order[ARRAY_SIZE];
    printf("  Vsevolod Rybnik test 2 task 3 var 26\n");
    while (loop_indicator)
    {
        // printf("%d %d %d", hash("hel"), hash("leh"), hash("cau"));
        HashTable* min_max_table = createHashTable();
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = GetInt();
        switch (options)
        {
            case ManualInput:
                input(order, GetDouble, min_max_table, "Specify array element №", ARRAY_SIZE);
                Calculation(order, min_max_table);
                destroyHashTable(min_max_table);
                continue;
            case RandomInput:
                input(order, random_value, min_max_table, NULL, ARRAY_SIZE);
                Calculation(order, min_max_table);
                destroyHashTable(min_max_table);
                continue;
            case Quit:
                return EXIT_SUCCESS;
            default:
                puts("Dis value is not akceptabele\n");
        }
    }
}
