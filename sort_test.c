/*
-----------------------------------
Algorithm class2 Homework2
Student name : Son Tae Hee 32182235
-----------------------------------
*/

/* Test num : 100 500 1000 5000 10000 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort.h"

int main(void)
{
    

    int num[5] = { 100,
                  500,
                  1000,
                  5000,
                  10000 };

    int arr1[100] = { 0 };
    int arr2[500] = { 0 };
    int arr3[1000] = { 0 };
    int arr4[5000] = { 0 };
    int arr5[10000] = { 0 };

    printf("Radix Sort\n");
    time_test(1, arr1, num[0]);
    printf("Exchange Sort\n");
    time_test(5, arr1, num[0]);
    //printf("Merge Sort\n");
    //time_test(2, arr1, num[0]);
    //printf("Quick Sort\n");
    //time_test(3, arr1, num[0]);
    //printf("Heap Sort\n");
    //time_test(4, arr1, num[0]);
    /*
    time_test(1, arr2, num[1]);
    time_test(1, arr3, num[2]);
    time_test(1, arr4, num[3]);
    time_test(1, arr5, num[4]);
    putchar('\n');
    */
    /*
    printf("Merge Sort\n");
    time_test(2, arr1, num[0]);
    time_test(2, arr2, num[1]);
    time_test(2, arr3, num[2]);
    time_test(2, arr4, num[3]);
    time_test(2, arr5, num[4]);
    putchar('\n');
    
    printf("Quick Sort\n");
    time_test(3, arr1, num[0]);
    time_test(3, arr2, num[1]);
    time_test(3, arr3, num[2]);
    time_test(3, arr4, num[3]);
    time_test(3, arr5, num[4]);
    putchar('\n');

    printf("Heap Sort\n");
    time_test(4, arr1, num[0]);
    time_test(4, arr2, num[1]);
    time_test(4, arr3, num[2]);
    time_test(4, arr4, num[3]);
    time_test(4, arr5, num[4]);
    putchar('\n');

    printf("Exchange Sort\n");
    time_test(5, arr1, num[0]);
    time_test(5, arr2, num[1]);
    time_test(5, arr3, num[2]);
    time_test(5, arr4, num[3]);
    time_test(5, arr5, num[4]);
    putchar('\n');
    */

    return 0;
}