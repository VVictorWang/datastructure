/*
 * @Author: victor
 * @Date: 2017-12-17 05:31:41
 * @Last Modified by: victor
 * @Last Modified time: 2017-12-17 05:32:04
 */

#include "Sort.h"

/**
 * @brief  insert sort
 * @note
 * @param  *E: the data list to be sorted
 * @param  n: the number of the data to be sorted
 * @retval None
 */
void InsertionSort(ElemType *E, int n) {
  int j, k;
  ElemType temp;
  for (j = 1; j < n; j++) {
    temp = E[j];
    for (k = j; k > 0 && E[k - 1].key > temp.key; k--) {
      E[k] = E[k - 1];
    }
    E[k] = temp;
  }
}

/**
 * @brief  binary insertion sort
 * @note
 * @param  *E: the data list
 * @param  n: the number of the data
 * @retval None
 */
void BinaryInsertionSort(ElemType *E, int n) {
  int j, k;
  ElemType temp;
  for (j = 0; j < n; j++) {
    temp = E[j];
    int low = 0;
    int high = j - 1;
    int mid = (low + high) / 2;
    while (low <= high) {
      if (E[mid].key > temp.key)
        high = mid - 1;
      else
        low = mid + 1;
      mid = (low + high) / 2;
    }
    for (k = j; k > high + 1; k--)
      E[k] = E[k - 1];
    E[k] = temp;
  }
}

/**
 * @brief  2 routes insertion sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void TwoRoutesInsertionSort(ElemType *E, int n) {
  int j, k, first = 0, last = 0;
  ElemType temp[n];
  temp[0] = E[0];
  for (j = 1; j < n; j++) {
    if (E[j].key < temp[first].key) {
      first = (first - 1 + n) % n;
      temp[first] = E[j];
    } else if (E[j].key >= temp[last].key) {
      last = (last + 1) % n;
      temp[last] = E[j];
    } else {
      for (k = last + 1; E[j].key < temp[(k - 1 + n) % n].key;
           k = (k - 1 + n) % n)
        temp[k] = temp[(k - 1 + n) % n];
      temp[k] = E[j];
      last = (last + 1) % n;
    }
  }
  for (j = 0; j < n; j++) {
    E[j] = temp[(j + first) % n];
  }
}