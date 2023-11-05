/**************************************************
* Название: first_task.c                          *
* Задание: Четвертая программа в осеннем семестре *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "first_module.h"

#define SIGMA_AMOUNT 150


int main(void)
{
    int loop_indicator = 1;
    while (loop_indicator)
    {
        printf("  Vsevolod Rybnik Test 2 task 1 var. 26\n");
        printf("  - Result: %f \n", formula(SIGMA_AMOUNT));
     	printf("  - Wanna see output again? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
