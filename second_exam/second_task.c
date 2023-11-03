/**************************************************
* Название: second_task.c                         *
* Задание: Пятая программа в осеннем семестре     *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <string.h>
#include <time.h>
#include "second_input_modules.h"
#include "second_struct.h"

#define ARRAY_SIZE 7


enum MENU {ManualInput=1, RandomInput=2, Quit =3};


HashTable* max_min_finder(double element, HashTable* min_max_table, int i)
{
    insert(min_max_table, "min", ((element < get(min_max_table, "min"))? element : (i == 1)? element : get(min_max_table, "min")));
    insert(min_max_table, "max", ((element > get(min_max_table, "max"))? element : (i == 1)? element : get(min_max_table, "max")));
    insert(min_max_table, "min_index", ((element == get(min_max_table, "min"))? i : get(min_max_table, "min_index")));
    insert(min_max_table, "max_index", ((element == get(min_max_table, "max"))? i : get(min_max_table, "max_index")));
    return min_max_table;
}


void Calculation(double order[], HashTable* min_max_table)
{
    printf("Original order: (");
    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%f, ", order[i]);
    printf(")\n");
    int slice = (((int) get(min_max_table, "min_index")) + ((int) get(min_max_table, "max_index"))) /2;
    printf("X order: (");
    for (int i = 0; i <= slice; i++)
        printf("%f, ", order[i]);
    printf(")\n");
    printf("Y order: (");
    for (int i = slice + 1; i < ARRAY_SIZE; i++)
        printf("%f, ", order[i]);
    printf(")\n");
}


int main(void)
{
    srand(time(NULL));
    int options = 1, loop_indicator = 1;
    double order[ARRAY_SIZE];
    printf("  Vsevolod Rybnik test 2 task 3 var 26\n");
    while (loop_indicator)
    {
        HashTable* min_max_table = createHashTable();
        puts("  1 - Manuale inpute\n  2 - Randome inpute\n  3 - Quite");
        options = GetInt();
        switch (options)
        {
            case ManualInput:
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    printf("%d array element:", i+1);
                    order[i] = GetDouble();
                    min_max_table = max_min_finder(order[i], min_max_table, i);
	            }
                destroyHashTable(min_max_table);
                continue;
            case RandomInput:
                for (int i = 0; i < ARRAY_SIZE; i++)
                    {
                        order[i] = -99 + rand()%(100 + 98);
                        min_max_table = max_min_finder(order[i], min_max_table, i);
	                }
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
