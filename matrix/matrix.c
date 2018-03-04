#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void
create_binary_matrix(int ***arr, int rows, int columns, bool negative)
{
    int i,j;
    int **a = *arr;
    a = (int **) malloc(sizeof(int*)*rows);
    for (i=0 ; i<rows ; i++) {
        a[i]= malloc(sizeof(int) * columns);
    }
    for (i=0 ; i<rows ; i++) {
        for (j=0 ; j<columns ; j++) {
            int ran = rand();
            if (negative && (ran%10==0)) {
                a[i][j] = -1;
            } else {
                a[i][j] = ran % 2;
            }
        }
    }
    *arr = a;
}

void
create_matrix(int ***arr, int rows, int columns)
{
    int i,j;
    int **a = *arr;
    a = (int **) malloc(sizeof(int*)*rows);
    for (i=0 ; i<rows ; i++) {
        a[i]= malloc(sizeof(int) * columns);
    }
    for (i=0 ; i<rows ; i++) {
        for (j=0 ; j<columns ; j++) {
            int ran = rand();
            a[i][j] = ran/10000000;
        }
    }
    *arr = a;
}

void
print_matrix(int **a, int m, int n) {
    int i,j;
    printf("\n");
    for (i=0 ; i<m ; i++) {
        printf("|\t");
        for (j=0 ; j<n ; j++) {
            printf("%d\t",a[i][j]);
        }
        printf("|\n");
    }
}
