/*
 * @Author: victor 
 * @Date: 2017-12-17 05:11:12 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-17 05:11:12 
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define DataType char
// 节点域
typedef struct NODE {
    DataType data;          //数据域
    struct NODE *next; //指针域
} *Node, sNode;

typedef struct STACK {
    Node top;    //栈顶指针
    Node bottom; //栈底指针
    int length;  //栈的长度
} *Stack;

int initStack(Stack *);

int push(Stack, DataType);

int pop(Stack, DataType *);

int stackEmpty(Stack);

DataType getTop(Stack);

void clear(Stack);

void printAll(Stack);

#endif