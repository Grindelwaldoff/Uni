/**************************************************
* Название: second_test.c                         *
* Задание: Вторая программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "second_module.h"


double GetDouble(void)
{
    char temprem, tempclear;
    double input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%lf%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("Error: Invalid value for double variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}


bool RAV_for_first(double x, double y, double z)
{
	return (x + fabs(y*z)) > 0;
}

bool RAV_for_second(double x, double z)
{
	return (pow(x, 2) + z) > 0;
}


int main(void){
    srand(time(NULL));
    double x = 0.0, y = 0.0, z = 0.0, result;
    int loop_indicator = 1, rand_man_indicator = 1;
	printf("Vsevolod Rybnik Test 1 task 2 var. 26\n");
    while (loop_indicator)
	{
    	result = 0.0;
        printf("Wanna specify values yourself or get random ones? (`any num` - random, 0 - manually): ");
		scanf("%d", &rand_man_indicator);
        if (!rand_man_indicator)
        {
            printf("Specify values for x: ");
            x = GetDouble();
            printf("Specify values for y: ");
            y = GetDouble();
            printf("Specify values for z: ");
            z = GetDouble();
        }
        else
        {
            x = -100 + rand()%(100 + 99);
			printf("Value for x is %f\n", x);
			y = -100 + rand()%(100 + 99);
			printf("Value for y is %f\n", y);
			z = -100 + rand()%(100 + 99);
			printf("Value for z is %f\n", z);
        }
        if (y < -3)
		{
			if (!RAV_for_first(x, y, z))
			{
				printf("Wrong values that dont fit RAV of first expression.\n");
				continue;
			}
            result = first_expression_method(x, y, z);
            printf("Result: %f \n", result);
    	}
        if (-3 <= y && y <= 1)
		{
			if (!RAV_for_second(x, z))
			{
				printf("Wrong values that dont fit RAV of second expression.\n");
				continue;
			}
            result = second_expression_method(x, y, z);
            printf("Result: %f \n", result);
    	}
        if (y > 1)
		{
            result = third_expression_method(x, y, z);
            printf("Result: %f \n", result);
    	}
        printf("Wanna new data input? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
    }
    return EXIT_SUCCESS;
}
