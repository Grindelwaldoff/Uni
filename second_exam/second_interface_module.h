#include "second_hash_table_module.h"

int GetInt(void);

double GetDouble(char *label, int position);

void output(char *name, int left_border, int right_border, double order[]);

double* input(double order[], double (*input_type)(char *, int), HashTable* min_max_table, char *label, int ARRAY_SIZE);
