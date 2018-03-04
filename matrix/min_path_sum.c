/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
 * sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example 1:
 * [[1,3,1],
 *  [1,5,1],
 *   [4,2,1]]
 *   Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
 *
 */

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int **a;

static int
dyn_prog_sum(int **a, int r, int c) {
    int i,j;
    int min[r+1][c+1];
    min[0][0] = a[0][0];
    printf("row=%d, col=%d\n",r,c);
    for(i=1 ; i<=r ; i++) {
        min[i][0] = min[i-1][0] + a[i][0];
    }
    for (j=1 ; j<=c ; j++) {
        min[0][j] = min[0][j-1] + a[0][j];
    }

    for (i=1 ; i<=r ; i++) {
        for (j=1 ; j<=c ; j++) {
            int m = 999;
            if (min[i-1][j] < m) {
                m = min[i-1][j];
            }
            if (min[i][j-1] < m) {
                m = min[i][j-1];
            }
            min[i][j] = m + a[i][j];
        }
    }
    return min[r][c];
}

static int
min_path_sum(int **a, int r, int c) {
    int dpath = 0;
    int rpath = 0;
    if (r >= N_ROWS || c >= N_COLUMNS) {
        return 0;
    }
    if (r == N_ROWS-1 && c == N_COLUMNS-1) {
        return a[r][c];
    }
    rpath = a[r][c] + min_path_sum(a, r, c+1);
    dpath = a[r][c] + min_path_sum(a, r+1, c);
    if (rpath < dpath) {
        return rpath;
    } else {
        return dpath;
    }
}

int main()
{
    int ans = 0;
    create_matrix(&a, N_ROWS, N_COLUMNS, 3);
    print_matrix(a, N_ROWS, N_COLUMNS);
   // ans = min_path_sum(a, 0, 0);
   ans = dyn_prog_sum(a, N_ROWS-1, N_COLUMNS-1);
    printf("\nMin path sum = %d\n",ans);
}
