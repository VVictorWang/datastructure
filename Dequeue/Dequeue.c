/*
 * @Author: victor
 * @Date: 2017-12-17 05:16:06
 * @Last Modified by:   victor
 * @Last Modified time: 2017-12-17 05:16:06
 */

#include "Dequeue.h"

int initQueue(Dequeue *qQueue, int maxSize) {
  (*qQueue)->data = (DataType *)malloc(sizeof(DataType) * maxSize);
  if (*qQueue == NULL)
    return FALSE;
  (*qQueue)->front = 0;
  (*qQueue)->rear = 0;
  //    qQueue->data[0]不存数据
  (*qQueue)->maxSize = maxSize + 1;
  return TRUE;
}

int queueFull(Dequeue qQueue) {
  return (qQueue->front) == ((qQueue->rear + 1) % qQueue->maxSize) ? TRUE
                                                                   : FALSE;
}

//进栈操作
int enQueue(Dequeue qQueue, DataType data) {
  if (queueFull(qQueue)) {
    printf("the queue is full! Cannot enqueue!");
    return FALSE;
  }
  qQueue->data[qQueue->rear] = data;
  qQueue->rear = (qQueue->rear + 1) % (qQueue->maxSize);
  return TRUE;
}

//判断栈是否为空
int queueEmpty(Dequeue qQueue) {
  return qQueue->front == qQueue->rear ? TRUE : FALSE;
}

//出栈操作
int deQueue(Dequeue qQueue, DataType *data) {
  if (queueEmpty(qQueue)) {
    printf("the Dequeue is empty, cannot dequeue!");
    return FALSE;
  }
  *data = qQueue->data[qQueue->front];
  qQueue->front = (qQueue->front + 1) % qQueue->maxSize;
  return TRUE;
}

//清空栈
void clear(Dequeue qQueue) { qQueue->front = qQueue->rear = 0; }

//打印栈中所有元素
void printAll(Dequeue qQueue) {
  if (queueEmpty(qQueue)) {
    printf("the queue is empty");
    return;
  }
  int temp = qQueue->front;
  while (temp != qQueue->rear) {
    printf("%5d", qQueue->data[temp]);
    temp++;
  }
}