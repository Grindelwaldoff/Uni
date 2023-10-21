/**************************************************
* Название: third_test.c                          *
* Задание: Третья программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "third_module.h"


int calculator(double x, double p, double h)
{
	while (x <= 2)
	{
		if (0 < x && x <= 2) {
            printf("Result: (%.3f, %.3f)\n", x, first_expression(x, p));
        }
        else if (-1 <= x && x < 0) {
            printf("Result: (%.3f, %.3f)\n", x, second_expression(x, p));
        }
        else if (x == 0)
        {
            printf("Result: (0.000, 0.000)\n");
        }
        x = round((x + h) * 1000) / 1000;  // округление до 3 знаков после запятой
	}
	return EXIT_SUCCESS;
}

int main(void) {
    double x = -1;
    const double p = M_PI;
    const double h = 0.2;
    int loop_indicator = 1;
	printf("Vsevolod Rybnik Test 1 task 3 var. 26\n");
    while (loop_indicator) {
        calculator(x, p, h);
        printf("Wanna keep entering values? (`any num` - yep, 0-nope) ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
