/**************************************************
* Название: first_module.h                        *
* Задание: Первая программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool RAV(double x, double y, double z) {
	return (((z + pow(x, 2)/4) != 0) && (y - sqrt(fabs(x))) * (x - y / (z + pow(x, 2)/4)) != 0);
}


double log_formula(double x, double y, double z){
	return log(fabs((y - sqrt(fabs(x))) * (x - y / (z + pow(x, 2)/4))));
}
