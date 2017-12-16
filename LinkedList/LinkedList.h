/*
 * @Author: victor 
 * @Date: 2017-12-01 19:33:56 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-01 19:33:56 
 */

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1   //操作正确
#define ERROR 0 //操作发生错误
#define TRUE 1 //函数返回true
#define FALSE 0 //函数返回false
#define  INFEASTABLE -1 //操作不可行
#define OVERFLOW -2 //栈溢出


typedef int ElemType; //线性表中的数据类型定义为int类型

typedef int status; //函数执行后返回的状态值


//线性表信息定义
typedef struct LINKEDLIST {
    struct LINKEDLIST *next;
    ElemType data;
} LinkedList;

status InitList(LinkedList **); //初始化线性表

status DestroyList(LinkedList **); //销毁线性表

status ClearList(LinkedList *); //清空线性表

int ListEmpty(LinkedList *); //判断线性表是否为空

int ListLength(LinkedList *); //得到线性表的长度

status GetElem(LinkedList *, int, ElemType *); //获取线性表上指定位置上的元素

int LocateElem(LinkedList *, ElemType, int (ElemType, ElemType)); //定位元素(根据自定义的compare函数)

status PriorElem(LinkedList *, ElemType, ElemType *); //得到指定元素的前驱

status NextElem(LinkedList *, ElemType, ElemType *); //得到指定元素的后继

status ListInsert(LinkedList *, int, ElemType); //在指定位置插入元素

status ListDelete(LinkedList *, int, ElemType *); //删除指定位置的元素

status ListTraverse(LinkedList *, void (ElemType)); //遍历元素

status WriteListToFile(LinkedList *, char *); //将线性表的内容写入到文件中

status getDataFromFile(LinkedList *, char *); //从文件中写入内容到线性表中

int Equals(ElemType, ElemType); //自定义的一个compare函数，简单的判读两个数是否相等

#endif //DATASTRUCTURE_LINKEDLIST_H
