#include <math.h>


double formula(int iteration_max)
{
    double result = 3.5, result_past_2_moves = 1.5, result_past_1_moves = 2, dif_move = 0.0;
    int iteration;
    for (iteration = 3; iteration <= iteration_max; iteration++)
    {
        dif_move = 2.5 * sin(result_past_1_moves - result_past_2_moves) + 3 * cos(result_past_1_moves + result_past_2_moves); // dif_move - иной ход(different)
        result += dif_move;
        result_past_2_moves = result_past_1_moves;
        result_past_1_moves = dif_move;
    }
    return result;
}
