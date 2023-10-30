/**************************************************
* Название: first_module.c                        *
* Задание: Четвертая программа в осеннем семестре *
* Автор: в.с. рыбник, СПбГТИ (ТУ), 2023           *
**************************************************/

#include <math.h>


double formula(int iteration_max)
{
    double result = 0.0, result_past_2_moves = 0.0, result_past_1_moves = 0.0, dif_move = 0.0;
    int iteration = 1;
    for (iteration = 1; iteration <= iteration_max; iteration++)
    {
        if (iteration == 1)
        {
            result += 1.5;
            result_past_2_moves = 1.5;
        }
        else if (iteration == 2)
        {
            result += 2;
            result_past_1_moves = 2;
        }
        else
        {
            dif_move = 2.5 * sin(result_past_1_moves - result_past_2_moves) + 3 * cos(result_past_1_moves + result_past_2_moves); // dif_move - иной ход(different)
            result += dif_move;
            result_past_2_moves = result_past_1_moves;
            result_past_1_moves = dif_move;
        }
    }
    return result;
}

