/*
 * @Author: victor
 * @Date: 2017-12-17 05:26:56
 * @Last Modified by: victor
 * @Last Modified time: 2017-12-17 05:30:59
 */

#ifndef SORT_H
#define SORT_H
#include <stdio.h>

typedef struct NODE {
  int idata;
} Node;
typedef int KeyType;
typedef struct ELEMTYPE {
  KeyType key;
  Node data;
} ElemType;

void BubbleSort(ElemType *,int); //冒泡排序
void SelectionSort(ElemType *,int); //选择排序
void MergeSort(ElemType *,int);  //归并排序
void InsertionSort(ElemType *, int);          //插入排序(O(n^2))
void BinaryInsertionSort(ElemType *, int);    //折半插入排序(O(n^2))
void TwoRoutesInsertionSort(ElemType *, int); // 2路插入排序(O(n^2))
void ShellSort(ElemType *, int);              //希尔排序
void HeapSort(ElemType *,int);  //堆排序
void QuickSort(ElemType *,int,int); //快速排序

#endif