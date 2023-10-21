/**************************************************
* Название: second_module.h                       *
* Задание: Вторая программа в осеннем семестре    *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <math.h>

double first_expression_method(double x, double y, double z){
    return sin(x) + 0.5 * sqrt(x + fabs(y*z));
};

double second_expression_method(double x, double y, double z){
    return 2 * y * sqrt(pow(x, 2) + z);
};

double third_expression_method(double x, double y, double z){
    return 3 * pow(x, 3) - 2 * pow(y, 2) + z;
};
