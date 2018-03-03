/*
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area
 * of largest rectangle in the histogram.
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 */


#include <stdio.h>
#include <stdlib.h>

//int a[] = {6, 2, 5, 4, 5, 1, 6};
int a[] = {2,1,5,6,2,3};
int width_of_block = 1;

void largest_rectangle(int length) {
    int ans = 0;
    int min = 999;
    int i;
    int min_area = 0;
    int max_total_area = 0;
    /* Calculate min of all the integers */
    for (i=0; i<length ; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    min_area = min * (length*width_of_block);
    printf("\nArea due to min height = %d\n",min_area);
    max_total_area = min_area;

    for (i=1;i<length-1;i++) {
        int j;
        int max_left = 0;
        int max_right = 0;
        int min_ht_left = 0;
        int min_ht_right = 0;
        /* if height i > prev, calculate max recurring area */
        j = i - 1;
        if (a[i] >= a[j]) {
            min_ht_left = a[j];
            while (j>0) {
                if (a[j] < min_ht_left) {
                    break;
                } else {
                    max_left += width_of_block*min_ht_left;
                }
                j--;
            }
            /* Add self areaa */
            max_left += width_of_block*min_ht_left;
        } else {
            max_left += a[i]*width_of_block;
            /* Add self areaa */
            max_left += a[i]*width_of_block;
        }
        /* if height is > next, calculate max recurring area */
        j = i + 1;
        if (a[i] >= a[j]) {
            min_ht_right = a[j];
            while (j < length) {
                if (a[j] < min_ht_right) {
                    break;
                }else {
                    max_right += width_of_block*min_ht_right;
                }
                j++;
            }
            /* Add self areaa */
            max_right += width_of_block*min_ht_right;
        } else {
            max_right += a[i]*width_of_block;
            /* Add self areaa */
            max_right += a[i]*width_of_block;
        }
        printf("\nElement = %d, max_right = %d, max_left = %d\n", a[i], max_right, max_left);
        if (max_right > max_total_area) {
            max_total_area = max_right;
        }
        if (max_left > max_total_area) {
            max_total_area = max_left;
        }
    }
    printf("\nMax aread = %d\n", max_total_area);
}

int main()
{
    int length = sizeof(a)/sizeof(a[0]);
    largest_rectangle(length);
    return 0;
}
