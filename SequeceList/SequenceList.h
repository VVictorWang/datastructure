/*
 * @Author: victor 
 * @Date: 2017-11-15 22:20:48 
 * @Last Modified by: victor
 * @Last Modified time: 2017-11-16 00:02:56
 */

#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define  INFEASTABLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 1
#define LISTINCREMENT  10

typedef int ElemType;
typedef int status;

typedef struct LIST {
    int length;
    ElemType *data;
    int listsize;
} List;

status InitList(List **);
status DestroyList(List **);
status ClearList(List *);
int ListEmpty(List *);
int ListLength(List *);
status GetElem(List *, int, ElemType *);
int LocateElem(List *, ElemType, int (ElemType,ElemType));
status PriorElem(List *, ElemType, ElemType *);
status NextElem(List *, ElemType, ElemType *);
status ListInsert(List *, int, ElemType);
status ListDelete(List *, int, ElemType *);
status ListTraverse(List *, void (ElemType));

int Equals(ElemType , ElemType );
#endif 