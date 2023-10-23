/**************************************************
* Название: third_test.c                          *
* Задание: Третья программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "third_module.h"


void calculator(void)
{
	double x = -1;
    const double h = 0.2;
	while (x <= 2)
	{
		if (0 < x && x <= 2) {
            printf("Result: (%.3f, %.3f)\n", x, first_expression(x, M_PI));
        }
        else if (-1 <= x && x < 0) {
            printf("Result: (%.3f, %.3f)\n", x, second_expression(x, M_PI));
        }
        else if (x == 0)
        {
            printf("Result: (0.000, 0.000)\n");
        }
        x = round((x + h) * 1000) / 1000;  // округление до 3 знаков после запятой
	}
}

int main(void) {
    int loop_indicator = 1;
	printf("Vsevolod Rybnik Test 1 task 3 var. 26\n");
    while (loop_indicator) {
        calculator();
        printf("Wanna keep entering values? (`any num` - yep, 0-nope) ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
