#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    time_t t;
    int **a;
    srand((unsigned) time(&t));
    //create_binary_matrix(&a, N_ROWS, N_COLUMNS, false);
    create_matrix(&a, N_ROWS, N_COLUMNS);
    print_matrix(a, N_ROWS, N_COLUMNS);
}
