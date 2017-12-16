/*
 * @Author: victor
 * @Date: 2017-12-17 05:16:19
 * @Last Modified by:   victor
 * @Last Modified time: 2017-12-17 05:16:19
 */
#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define DataType int

typedef struct DEQUEUE {
  DataType *data; //队列元素
  int front;      //队首指针
  int rear;       //队尾指针
  int maxSize;
} * Dequeue;

int initQueue(Dequeue *o, int);

int enQueue(Dequeue, DataType);

int deQueue(Dequeue, DataType *);

int queueEmpty(Dequeue);

int queueFull(Dequeue);

void clear(Dequeue);

void printAll(Dequeue);

#endif