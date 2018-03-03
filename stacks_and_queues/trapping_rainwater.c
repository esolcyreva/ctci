/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
 * it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

#include <stdio.h>
#include <stdlib.h>

int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};

void trap_water_brute_force(int length) {
    int ans = 0;
    int i;
    for (i=1 ; i<(length-1) ; i++) {
        int max_left = 0;
        int max_right = 0;
        int min_ht = 0;
        int j;
        for (j=i-1 ; j> 0 ; j--) {
            if (a[j] > max_left) {
                max_left = a[j];
            }
        }
        for (j=i+1 ; j<(length) ; j++) {
            if (a[j] > max_right) {
                max_right = a[j];
            }
        }
        min_ht = max_right < max_left ? max_right : max_left;
        if (min_ht > a[i]) {
            ans += min_ht - a[i];
        }
        printf("\nElement = %d, min_ht=%d, ans = %d\n",a[i], min_ht, ans);
    }
    printf("\nAmt of water trapped = %d\n", ans);
}

void trap_water_smart(int length) {
    int ans = 0;
    int i;
    int left_max[length];
    int right_max[length];
    for (i=0 ; i< length; i++) {
        if (i == 0) {
            left_max[i] = a[i];
            continue;
        }
        if(left_max[i-1] < a[i]) {
            left_max[i] = a[i];
        } else {
            left_max[i] = left_max[i-1];
        }
    }
    for (i=length-1 ; i>0; i--) {
        if (i == length - 1) {
            right_max[i] = a[i];
            continue;
        }
        if(right_max[i+1] < a[i]) {
            right_max[i] = a[i];
        } else {
            right_max[i] = right_max[i+1];
        }
    }
    for (i=1 ; i<length-1 ;i++) {
        int min_ht = right_max[i+1] < left_max[i-1] ? right_max[i+1] : left_max[i-1];
        if (min_ht > a[i]) {
            ans += min_ht - a[i];
        }
    }
    printf("\nAmt of water trapped = %d\n", ans);
}

int main()
{
    int length = sizeof(a)/sizeof(a[0]);
    trap_water_brute_force(length);
    trap_water_smart(length);
}
