
#include "Sort.h"

void visit(ElemType *A, int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("key: %6d\tvalue:%6d \n", A[i].key, A[i].data.idata);
  }
}

int main() {
  ElemType test[10] = {{20, {40}}, {2, {5}},  {5, {89}},  {19, {45}}, {3, {90}},
                       {89, {2}},  {16, {8}}, {34, {56}}, {11, {81}}};

  printf("before sort:\n");
  visit(test, 9);
  BucketSort(test, 9);
  printf("after sort:\n");
  visit(test, 9);
}