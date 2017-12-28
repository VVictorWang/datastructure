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

// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void BubbleSort(ElemType *, int);             //冒泡排序

// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void SelectionSort(ElemType *, int);          //选择排序

// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定
void MergeSort(ElemType *, int);              //归并排序

// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void InsertionSort(ElemType *, int);          //插入排序(O(n^2))

// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void BinaryInsertionSort(ElemType *, int);    //折半插入排序(O(n^2))
void TwoRoutesInsertionSort(ElemType *, int); // 2路插入排序(O(n^2))

// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void ShellSort(ElemType *, int);              //希尔排序

// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void HeapSort(ElemType *, int);               //堆排序

// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定
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
// 所需辅助空间 ------ O(n + bucket_size)
// 稳定性 ----------- 稳定
void BucketSort(ElemType *, int); //桶排序

#endif