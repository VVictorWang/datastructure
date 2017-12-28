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

void BubbleSort(ElemType *, int);             //冒泡排序
void SelectionSort(ElemType *, int);          //选择排序
void MergeSort(ElemType *, int);              //归并排序
void InsertionSort(ElemType *, int);          //插入排序(O(n^2))
void BinaryInsertionSort(ElemType *, int);    //折半插入排序(O(n^2))
void TwoRoutesInsertionSort(ElemType *, int); // 2路插入排序(O(n^2))
void ShellSort(ElemType *, int);              //希尔排序
void HeapSort(ElemType *, int);               //堆排序
void QuickSort(ElemType *, int, int);         //快速排序
// 最差时间复杂度 ---- O(n + k) (k为数组E的关键字的取值范围)
// 最优时间复杂度 ---- O(n + k)
// 平均时间复杂度 ---- O(n + k)
// 所需辅助空间 ------ O(n + k)
void CountSort(ElemType *, int); //计数排序

// 最差时间复杂度 ---- O(n * dn) (dn为E中最大数的位数)
// 最优时间复杂度 ---- O(n * dn)
// 平均时间复杂度 ---- O(n * dn)
// 所需辅助空间 ------ O(n * dn)
// 稳定性 ----------- 稳定
void RadixSort(ElemType *, int); //基数排序

// 最差时间复杂度 ---- O(nlogn)或O(n^2)，只有一个桶，取决于桶内排序方式
// 最优时间复杂度 ---- O(n)，每个元素占一个桶
// 平均时间复杂度 ---- O(n)，保证各个桶内元素个数均匀即可
// 所需辅助空间 ------ O(n + bn)
// 稳定性 ----------- 稳定
void BucketSort(ElemType *, int); //桶排序

#endif