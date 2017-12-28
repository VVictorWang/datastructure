/*
 * @Author: victor
 * @Date: 2017-12-17 05:31:41
 * @Last Modified by: victor
 * @Last Modified time: 2017-12-17 05:32:04
 */

#include "Sort.h"

/**
 * @brief  swap two elements in the data list
 * @note
 * @param  *E: the data list
 * @param  i:
 * @param  j:
 * @retval None
 */
void Swap(ElemType *E, int i, int j) {
  ElemType temp = E[i];
  E[i] = E[j];
  E[j] = temp;
}
/**
 * @brief bubble sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void BubbleSort(ElemType *E, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (E[j].key > E[j + 1].key) {
        ElemType e = E[j];
        E[j] = E[j + 1];
        E[j + 1] = e;
      }
    }
  }
}

/**
 * @brief  selection sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void SelectionSort(ElemType *E, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (E[min].key > E[j].key) {
        min = j;
      }
    }
    ElemType e = E[i];
    E[i] = E[min];
    E[min] = e;
  }
}
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

/**
 * @brief  shell sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void ShellSort(ElemType *E, int n) {
  int j, k, increment;
  ElemType temp;
  for (increment = n / 2; increment > 0; increment /= 2) {
    for (j = increment; j < n; j++) {
      temp = E[j];
      for (k = j - increment; E[k].key > temp.key && k >= 0; k -= increment) {
        E[k + increment] = E[k];
      }
      E[k + increment] = temp;
    }
  }
}

/**
 * @brief  merge two sorted data list
 * @note
 * @param  *E: the data list
 * @param  left:
 * @param  mid:
 * @param  right:
 * @retval None
 */
void Merge(ElemType *E, int left, int mid, int right) {
  int length = right - left + 1;
  int i = left, j = mid + 1;
  ElemType temp[length];
  int k = 0;
  while (i <= mid && j <= right) {
    temp[k++] = E[i].key > E[j].key ? E[j++] : E[i++];
  }
  while (i <= mid) {
    temp[k++] = E[i++];
  }
  while (j <= right) {
    temp[k++] = E[j++];
  }
  for (k = 0; k < length; k++)
    E[left++] = temp[k];
}

/**
 * @brief  merge sort with iteration
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void MergeSort(ElemType *E, int n) {
  int left, mid, right;
  int i;
  for (i = 1; i < n; i *= 2) {
    left = 0;
    while (left + i < n) {
      mid = left + i - 1;
      right = mid + i < n ? mid + i : n - 1;
      Merge(E, left, mid, right);
      left = right + 1;
    }
  }
}

/**
 * @brief  adjust the heap from E[i]
 * @note
 * @param  *E: the heap
 * @param  i:
 * @param  size:
 * @retval None
 */
void Heapify(ElemType *E, int i, int size) {
  int left_child = 2 * i + 1;  // 左孩子索引
  int right_child = 2 * i + 2; // 右孩子索引
  int max = i; // 选出当前结点与其左右孩子三者之中的最大值
  if (left_child < size && E[left_child].key > E[max].key)
    max = left_child;
  if (right_child < size && E[right_child].key > E[max].key)
    max = right_child;
  if (max != i) {
    Swap(E, i, max); // 把当前结点和它的最大(直接)子节点进行交换
    Heapify(E, max, size); // 递归调用，继续从当前结点向下进行堆调整
  }
}

/**
 * @brief  Build heap
 * @note
 * @param  *E: the data list
 * @param  n:
 * @retval None
 */
void BuildHeap(ElemType *E, int n) {
  int i;
  for (i = n / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
    Heapify(E, i, n);
}

/**
 * @brief  heap sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void HeapSort(ElemType *E, int n) {
  BuildHeap(E, n);
  while (n > 1) {
    // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
    // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
    Swap(E, 0, --n);
    Heapify(E, 0, n);
  }
}

/**
 * @brief
 * @note
 * @param  *E:
 * @param  left:
 * @param  right:
 * @retval
 */
int Partition(ElemType *E, int left, int right) {
  ElemType pivot = E[right];
  int tail = left - 1, i;
  for (i = left; i < right; i++) {
    if (E[i].key <= pivot.key) {
      tail++;
      if (tail != i)
        Swap(E, tail, i);
    }
  }
  Swap(E, ++tail, right);
  return tail;
}

/**
 * @brief  quick sort
 * @note
 * @param  *E: the data list
 * @param  left:
 * @param  right:
 * @retval None
 */
void QuickSort(ElemType *E, int left, int right) {
  if (left >= right)
    return;
  int pivot = Partition(E, left, right);
  QuickSort(E, left, pivot - 1);
  QuickSort(E, pivot + 1, right);
}

/**
 * @brief  count sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void CountSort(ElemType *E, int n) {
  int i = 0;
  int max = E[0].key;
  for (i = 0; i < n; i++)
    if (E[i].key > max)
      max = E[i].key;
  int count[max + 1];
  for (i = 0; i <= max; i++)
    count[i] = 0;
  for (i = 0; i < n; i++)
    count[E[i].key]++;
  for (i = 1; i <= max; i++)
    count[i] += count[i - 1];
  ElemType temp[n];
  for (i = n - 1; i >= 0; i--)
    temp[--count[E[i].key]] = E[i];
  for (i = 0; i < n; i++)
    E[i] = temp[i];
}

/**
 * @brief  get the d th number of x
 * @note
 * @param  x: the number
 * @param  d: the digit
 * @retval
 */
int getDigit(int x, int d) {
  if (d == 1)
    return x % 10;
  return (x / ((d - 1) * 10)) % 10;
}

/**
 * @brief  sort the array by the d th number
 * @note
 * @param  *E:
 * @param  n:
 * @param  d:
 * @retval None
 */
void CountingSort(ElemType *E, int n, int d) {
  int i = 0;
  int count[10];
  for (i = 0; i < 10; i++)
    count[i] = 0;
  for (i = 0; i < n; i++)
    count[getDigit(E[i].key, d)]++;
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];
  ElemType temp[n];
  for (i = n - 1; i >= 0; i--)
    temp[--count[getDigit(E[i].key, d)]] = E[i];
  for (i = 0; i < n; i++)
    E[i] = temp[i];
}

/**
 * @brief  radix sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void RadixSort(ElemType *E, int n) {
  int i = 0;
  int max = E[0].key;
  for (i = 0; i < n; i++)
    if (E[i].key > max)
      max = E[i].key;
  int digit = 0;
  while (max != 0) {
    max /= 10;
    digit++;
  }
  for (i = 1; i <= digit; i++)
    CountingSort(E, n, i);
}

int MapToBucket(int x) {
  return x /
         10; // 映射函数f(x)，作用相当于快排中的Partition，把大量数据分割成基本有序的数据块
}

#define BUCKET_SIZE 5    // the size of the bucket
int BUCKET[BUCKET_SIZE]; // the buckets

/** using count sort to get the buckets
 * @brief
 * @note
 * @param  *E:
 * @param  n:
 * @retval None
 */
void CountingSortBucket(ElemType *E, int n) {
  int i = 0;
  for (i = 0; i < BUCKET_SIZE; i++)
    BUCKET[i] = 0;
  for (i = 0; i < n; i++)
    BUCKET[MapToBucket(E[i].key)]++;
  for (i = 1; i < BUCKET_SIZE; i++)
    BUCKET[i] += BUCKET[i - 1];
  ElemType temp[n];
  for (i = n - 1; i >= 0; i--)
    temp[--BUCKET[MapToBucket(E[i].key)]] = E[i];
  for (i = 0; i < n; i++)
    E[i] = temp[i];
}

/**
 * @brief  bucket sort
 * @note
 * @param  *E: the data list
 * @param  n: the size of the data list
 * @retval None
 */
void BucketSort(ElemType *E, int n) {
  CountingSortBucket(E, n); // 利用计数排序确定各个桶的边界（分桶）
  int i = 0;
  for (; i < BUCKET_SIZE; i++) {
    int left = BUCKET[i]; // C[i]为i号桶第一个元素的位置
    int right = (i == BUCKET_SIZE - 1)
                    ? (n - 1)
                    : (BUCKET[i + 1] - 1); // C[i+1]-1为i号桶最后一个元素的位置
    if (left < right) // 对元素个数大于1的桶进行桶内快速排序
      QuickSort(E, left, right);
  }
}