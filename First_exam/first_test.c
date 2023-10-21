/**************************************************
* Название: first_test.c                          *
* Задание: Первая программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "first_module.h"


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
            printf("Error: Invalid value for double variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}


int main(void){
	srand(time(NULL)); // NULL - seconds - Указатель на объект типа time_t, где хранится кол-во секунд.
    double x = 0.0, y = 0.0, z = 0.0, result = 0;
  	int loop_indicator = 1;
	int rand_manually_indicator = 1;
	char temprem = "f";
	printf("Vsevolod Rybnik Test 1 task 1 var. 26\n");
  	while (loop_indicator) {
		printf("Wanna specify values yourself or get random ones? (`any num` - random, 0 - manually): ");
		scanf("%d", &rand_manually_indicator);
		if (rand_manually_indicator)
		{
			x = -100 + rand()%(100 + 99);
			printf("Value for x is %f\n", x);
			y = -100 + rand()%(100 + 99);
			printf("Value for y is %f\n", y);
			z = -100 + rand()%(100 + 99);
			printf("Value for z is %f\n", z);
		}
		else
		{
    	printf("Specify values for x: ");
		x = GetDouble();
		printf("Specify values for y: ");
		y = GetDouble();
		printf("Specify values for z: ");
		z = GetDouble();
		}
		if (!RAV(x, y, z)) {
    		printf("Wrong values that dont fit RAV of this expression.\n");
			continue;
		}
		result = log_formula(x, y, z);
    	printf("Result: %f \n", result);
     	printf("Wanna new data input? (`any num` - yep, 0 - nope): ");
        scanf("%d", &loop_indicator);
  	}
    return EXIT_SUCCESS;
}
