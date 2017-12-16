/*
 * @Author: victor 
 * @Date: 2017-12-17 05:11:32 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-17 05:11:32 
 */

#include "Stack.h"

int initStack(Stack *pStack) {
    (*pStack) = (Stack) malloc(sizeof(struct STACK));
    (*pStack)->top = (Node) malloc(sizeof(sNode));
    if ((*pStack)->top == NULL)
        return FALSE;
    (*pStack)->bottom = (*pStack)->top;
    (*pStack)->top->next = NULL;
    (*pStack)->length = 0;
    return TRUE;
}

int push(Stack pStack, DataType data) {
    Node newNode = (Node) malloc(sizeof(sNode));
    if (newNode == NULL)
        return FALSE;
    newNode->data = data;
    newNode->next = pStack->top;
    pStack->top = newNode;
    return TRUE;
}

int stackEmpty(Stack pStack) {
    return pStack->bottom == pStack->top ? TRUE : FALSE;
}

int pop(Stack pStack, DataType *data) {
    if (stackEmpty(pStack)) {
        printf("the Stack is empty, cannot pop!");
        return FALSE;
    }
    *data = pStack->top->data;
    Node temp = pStack->top;
    pStack->top = pStack->top->next;
    free(temp);
    return TRUE;
}

DataType getTop(Stack pStack) {
    return pStack->top->data;
}

void clear(Stack pStack) {
    Node temp;
    while (pStack->top != pStack->bottom) {
        temp = pStack->top;
        pStack->top = pStack->top->next;
        free(temp);
    }
}

void printAll(Stack pStack) {
    if (stackEmpty(pStack)) {
        printf("the stack is empty");
        return;
    }
    Node temp = pStack->top;
    while (temp != pStack->bottom) {
        printf("%5d", temp->data);
        temp = temp->next;
    }
}