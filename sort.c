/*
-----------------------------------
Algorithm class2 Homework2
Student name : Son Tae Hee 32182235
-----------------------------------
*/

/* Sorting function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#include "sort.h"

void set_rand_arr(int* arr, int num)
{
    srand(time(NULL));
    
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % 30000 + 1;
    }
    Sleep(1000);
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

double avg_time(double* time_arr)
{
    double avg = 0;
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += time_arr[i];
    }

    avg = total / 5;
    return avg;
}

void exchange_sort(int* arr, int num)
{
    int i, j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = num - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

void merge(int* arr, int left, int mid, int right)
{
    int i, j, k, l;
    
    i = left;
    j = mid + 1;
    k = left;
    
    int* forSort;
    forSort = (int*)calloc(right+1, sizeof(int));
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            forSort[k++] = arr[i++];
        else
            forSort[k++] = arr[j++];
    }

    if (i > mid)
    {
        for (l = j; l <= right; l++)
            forSort[k++] = arr[l];
    }

    else
    {
        for (l = i; l <= mid; l++)
            forSort[k++] = arr[l];
    }

    for (l = left; l <= right; l++)
    {
        arr[l] = forSort[l];
    }
    free(forSort);
}

void merge_sort(int* arr, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void quick_sort(int* arr, int left, int right)
{
    
    int pl = left;
    int pr = right;
    int piv = arr[(pl + pr) / 2];

    do
    {
        while (arr[pl] < piv)
        {
            pl++;
        }
        while (arr[pr] > piv)
        {
            pr--;
        }
        if (pl <= pr)
        {
            swap(&arr[pl], &arr[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr)
    {
        quick_sort(arr, left, pr);
    }
    if (pl < right)
    {
        quick_sort(arr, pl, right);
    }
}

void downheap(int* arr, int left, int right)
{
    int temp = arr[left];
    int parent, child;
    for (parent = left; parent < (right + 1) / 2; parent = child)
    {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && arr[cr] > arr[cl]) ? cr : cl;
        if (temp >= arr[child])
        {
            break;
        }
        arr[parent] = arr[child];
    }
    arr[parent] = temp;
}

void heap_sort(int* arr, int num)
{
    int i;
    for (i = (num - 1) / 2; i >= 0; i--)
    {
        downheap(arr, i, num - 1);
    }
    for (i = num - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        downheap(arr, 0, i - 1);
    }
}

int find_max(int* arr, int num)
{

    int i;
    int max = -1;

    for (i = 0; i < num; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void radix_sort(int* arr, int num)
{

    int i;
    int* forSort;
    forSort = (int*)calloc(num, sizeof(int));

    int digit = 1;
    int max = find_max(arr, num);

    while (max / digit > 0)
    {
        int bucket[10] = { 0 };

        for (i = 0; i < num; i++)
            bucket[(arr[i] / digit) % 10]++;

        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (i = num - 1; i >= 0; i--)
            forSort[--bucket[(arr[i] / digit) % 10]] = arr[i];

        for (i = 0; i < num; i++)
            arr[i] = forSort[i];

        digit *= 10;
    }
    free(forSort);
    
}

void time_test(int type_of_sort, int* arr, int num)
{
    double time_arr[5] = {0};

    double result = 0;

    for (int i = 0; i < 5; i++)
    {
        
        clock_t start, end;
        switch (type_of_sort)
        {
        case 1:
            set_rand_arr(arr, num);
            printf("Before\n");
            Print_arr(arr, 50);
            start = clock();
            radix_sort(arr, 50);
            end = clock();
            rintf("After\n");
            Print_arr(arr, num);
            time_arr[i] = (double)(end - start) / CLOCKS_PER_SEC;
            break;

        case 2:
            start = clock();
            merge_sort(arr, 0, num - 1);
            end = clock();
            time_arr[i] = (double)(end - start) / CLOCKS_PER_SEC;
            break;
            
     

        case 3:
            start = clock();
            quick_sort(arr, 0, num - 1);
            end = clock();
            time_arr[i] = (double)(end - start) / CLOCKS_PER_SEC;
            break;

        case 4:
            start = clock();
            heap_sort(arr, num);
            end = clock();
            time_arr[i] = (double)(end - start) / CLOCKS_PER_SEC;
            break;

        case 5:
            start = clock();
            exchange_sort(arr, num);
            end = clock();
            time_arr[i] = (double)(end - start) / CLOCKS_PER_SEC;
            break;
        default:
            break;
        }
    }
    printf("TestNum %d : %0.8fs\n", num, avg_time(time_arr));
}


void Print_arr(int* arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n\n");
}