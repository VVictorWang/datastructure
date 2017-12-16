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

void InsertionSort(ElemType *, int);  //插入排序(O(n^2))
void BinaryInsertionSort(ElemType *,int ); //折半插入排序(O(n^2))
void TwoRoutesInsertionSort(ElemType *,int ); //2路插入排序(O(n^2))
#endif