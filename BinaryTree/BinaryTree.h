
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>


#define OK 1   //操作正确
#define ERROR 0 //操作发生错误
#define TRUE 1 //函数返回true
#define FALSE 0 //函数返回false
#define  INFEASTABLE -1 //操作不可行
#define OVERFLOW -2 //栈溢出

typedef  int ElemType;

typedef struct BINARYTREE{
 ElemType data;
 struct BINARYTREE *left;
 struct BINARYTREE *right;
} *BTree;



#endif