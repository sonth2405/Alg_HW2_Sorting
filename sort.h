#pragma once
/*
-----------------------------------
Algorithm class2 Homework2
Student name : Son Tae Hee 32182235
-----------------------------------
*/

#ifndef _SORT_H
#define _SORT_H

double avg_time(double* time_arr);
void set_rand_arr(int* arr, int num);
void swap(int* x, int* y);

void time_test(int type_of_sort, int* arr, int num);

void exchange_sort(int* arr, int num);

void merge(int* arr, int left, int mid, int right);
void merge_sort(int* arr, int left, int right);

void quick_sort(int* arr, int left, int right);

void downheap(int* arr, int left, int right);
void heap_sort(int* arr, int num);

int find_max(int* arr, int num);
void radix_sort(int* arr, int num);

void Print_arr(int* arr, int num);

#endif /* _SORT_H*/