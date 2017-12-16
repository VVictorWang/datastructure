/*
 * @Author: victor 
 * @Date: 2017-12-01 19:34:27 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-01 19:34:27 
 */

#include "LinkedList.h"

/**
 * 初始化线性表
 * @param head the head address of the list
 * @return whether the function has executed rightly
 */
status InitList(LinkedList **head) {
    if (*head) {
        return INFEASTABLE;
    }
    if (!(*head = (LinkedList *) malloc(sizeof(struct LINKEDLIST)))) {
        return OVERFLOW;
    }
    (*head)->data = 0;
    return OK;
}

/**
 * 销毁线性表
 * @param head the head of the list
 * @return whether the function has executed rightly
 */
status DestroyList(LinkedList **head) {
    if (*head != NULL) {
        free(*head);
        (*head) = NULL;
    }
    return OK;
}

/**清空线性表
 *
 * @param head the head of the list
 * @return whether the function has executed rightly
 */
status ClearList(LinkedList *head) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    LinkedList *p = head->next;
    while (p != NULL) {
        LinkedList *temp = p->next;
        free(p);
        p = temp;
    }
    head->next = NULL;
    return OK;
}

/**
 * 判断线性表是否为空
 * @param head the head of the list
 * @return whether the list is empty
 */
int ListEmpty(LinkedList *head) {
    if (!head) {
        printf("表没有创建!\n");
        return INFEASTABLE;
    }
    return (head->next == NULL) ? TRUE : FALSE;
}

/**
 * 得到线性表的长度
 * @param head the head of the list
 * @return the length of the list
 */
int ListLength(LinkedList *head) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    int length = 0;
    LinkedList *p = head;
    while ((p = p->next) != NULL) {
        length++;
    }
    return length;
}

/**
 * 获取线性表上指定位置上的元素
 * @param head the head of the list
 * @param i the location of the item to be gotten
 * @param e the address of the data to save the element
 * @return whether the function has executed rightly
 */
status GetElem(LinkedList *head, int i, ElemType *e) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    if (i <= 0 || i > ListLength(head)) {
        printf("location i is not in the proper area");
        return ERROR;
    }
    int current_position = 0;
    LinkedList *p = head->next;
    while (++current_position < i && p != NULL) {
        p = p->next;
    }
    if (p == NULL) {
        return ERROR;
    } else {
        *e = p->data;
    }
    return OK;
}

/**
 * 定位元素(根据自定义的compare函数)
 * @param head the head of the list
 * @param e the element to be located
 * @param compare the compare function
 * @return whether the fuction has executed rightly
 */
int LocateElem(LinkedList *head, ElemType e, int compare(ElemType, ElemType)) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    int i = 0;
    LinkedList *p = head->next;
    while (p != NULL) {
        if (compare(p->data, e)) {
            return i + 1;
        }
        p = p->next;
        i++;
    }
    return 0;
}

/**
 * 比较两个元素是否相等
 * @param e1 the first item
 * @param e2 the second item
 * @return whether the two items equals
 */
int Equals(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}

/**
 * 得到指定元素的前驱
 * @param head the head of the list
 * @param cur_e the current element
 * @param e the address of the data to save the prior item of the current item
 * @return whether the function has executed rightly
 */
status PriorElem(LinkedList *head, ElemType cur_e, ElemType *e) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    LinkedList *p = head->next;
    LinkedList *q = head;
    while (p != NULL) {
        if (p->data == cur_e && q != head) {
            (*e) = q->data;
            return OK;
        }
        q = p;
        p = p->next;
    }
    if (p == NULL || q == head) {
        printf("cur_e is not in list or cur_e is the first item!\n");
        return ERROR;
    }
    return OK;

}

/**
 * 得到指定元素的后继
 * @param head the head of the list
 * @param cur_e the current element
 * @param next_e the address of the data to save the next item of the current item
 * @return whether the function has executed rightly
 */
status NextElem(LinkedList *head, ElemType cur_e, ElemType *next_e) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    LinkedList *p = head->next;
    while (p != NULL) {
        if (p->data == cur_e && p->next != NULL) {
            (*next_e) = p->next->data;
            return OK;
        }
        p = p->next;
    }
    if (p == NULL) {
        printf("cur_e is not in list or cur_e is the last item!\n");
        return ERROR;
    }
    return OK;

}

/**
 * 在指定位置插入元素
 * @param head the head of the list
 * @param i the position of the element to be inserted
 * @param e the element to be inserted
 * @return whether the function has executed rightly
 */
status ListInsert(LinkedList *head, int i, ElemType e) {
    if (head == NULL) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    if (i <= 0 || (i > ListLength(head) + 1)) {
        printf("location i is not in the proper area\n");
        return ERROR;
    }
    int j = 1;
    LinkedList *p = (LinkedList *) malloc(sizeof(struct LINKEDLIST));
    p->data = e;
    LinkedList *now = head->next;
    LinkedList *pre = now;
    while (j < i) {
        pre = now;
        now = now->next;
        j++;
    }
    if (now == head->next) {
        p->next = head->next;
        head->next = p;
        return OK;
    }
    pre->next = p;
    p->next = now;
    return OK;
}

/**
 * 删除指定位置的元素
 * @param L the head of the list
 * @param i the position of the element to be deleted
 * @param e the address of the data of save the deleting element
 * @return whether the function has executed rightly
 */
status ListDelete(LinkedList *head, int i, ElemType *e) {
    if (head == NULL) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    if (i <= 0 || (i > ListLength(head) + 1)) {
        printf("location i is not in the proper area\n");
        return ERROR;
    }
    int j = 1;
    LinkedList *now = head->next;
    LinkedList *pre = head;
    while (j < i) {
        pre = now;
        now = now->next;
        j++;
    }
    if (now == head->next) {
        *e = head->next->data;
        LinkedList *temp = head->next;
        head->next = head->next->next;
        free(temp);
        return OK;
    }
    LinkedList *temp = now;
    *e = now->data;
    pre->next = now->next;
    free(temp);
    return OK;
}

/**
 * 遍历线性表中元素
 * @param head the head of the list
 * @param visit the traverse function
 * @return whether the function has executed rightly
 */
status ListTraverse(LinkedList *head, void visit(ElemType)) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    LinkedList *p = head;
    while ((p = p->next) != NULL) {
        visit(p->data);
    }
    return OK;
}

/**
 * 将线性表的内容写入到文件中
 * @param head the head of the list
 * @param filename  the name of the file
 * @return whether the function has executed rightly
 */
status WriteListToFile(LinkedList *head, char *filename) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    char current_file[100];
    strcpy(current_file, "/home/victor/CLionProjects/datastructure/");
    int length = (int) strlen(current_file);
    int i = length;
    for (; i < length + strlen(filename); i++) {
        current_file[i] = filename[i - length];
    }
    current_file[i] = '\0';
    printf("%s\n", current_file);
    FILE *p = fopen(current_file, "wb+");
    if (p == NULL) {
        printf("打开文件失败!\n");
        return INFEASTABLE;
    }
    LinkedList *now = head;
    while ((now = now->next) != NULL) {
        fprintf(p, "%d  ", now->data);
    }
    fprintf(p, "\n");
    fclose(p);
    return OK;
}

/**
 * 从文件中写入内容到线性表中
 * @param head the head of the list
 * @param filename  the name of the file
 * @return whether the function has executed rightly
 */
status getDataFromFile(LinkedList *head, char *filename) {
    if (!head) {
        printf("表为空!\n");
        return INFEASTABLE;
    }
    char current_file[100];
    strcpy(current_file, "/home/victor/CLionProjects/datastructure/");
    int length = (int) strlen(current_file);
    int i = length;
    for (; i < length + strlen(filename); i++) {
        current_file[i] = filename[i - length];
    }
    current_file[i] = '\0';
    printf("%s\n", current_file);
    FILE *p = fopen(current_file, "r");
    if (p == NULL) {
        printf("打开文件失败或文件不存在!\n");
        return INFEASTABLE;
    }
    int temp;
    i = ListLength(head);
    while (fscanf(p, "%d", &temp) != EOF) {
        ListInsert(head, i + 1, temp);
        i = ListLength(head);
    }
    fclose(p);
    return OK;
}