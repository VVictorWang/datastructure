/*
 * @Author: victor 
 * @Date: 2017-11-16 00:00:15 
 * @Last Modified by: victor
 * @Last Modified time: 2017-11-16 00:02:56
 */

#include "SequenceList.h"

status InitList(List **L) {
    if (!(*L = (List *) malloc(sizeof(struct LIST)))) {
        return OVERFLOW;
    }
    if (!((*L)->data = (ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE))) {
        return OVERFLOW;
    }
    (*L)->length = 0;
    int i = 0;
    for (i = 0; i < LIST_INIT_SIZE; i++) {
        (*L)->data[i] = 0;
    }
    (*L)->listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(List **L) {
    if (*L != NULL) {
        (*L)->listsize = 0;
        free((*L)->data);
        free(*L);
        (*L) = NULL;
    }
    return OK;
}

status ClearList(List *L) {
    if (!L) {
        return INFEASTABLE;
    }
    int i = 0;
    for (i = 0; i < (*L).length; ++i) {
        (*L).data[i] = 0;
    }
    (*L).length = 0;
    return OK;
}

int ListEmpty(List *L) {
    if (!L) {
        return INFEASTABLE;
    }
    return (L->length == 0) ? TRUE : FALSE;
}

int ListLength(List *L) {
    if (!L) {
        return INFEASTABLE;
    }
    return L->length;
}

status GetElem(List *L, int i, ElemType *e) {
    if (!L) {
        return INFEASTABLE;
    }
    if (i <= 0 || i > ListLength(L)) {
        printf("location i is not in the proper area");
        return ERROR;
    }
    (*e) = L->data[i - 1];
    return OK;
}

int LocateElem(List *L, ElemType e, int compare(ElemType, ElemType)) {
    if (!L) {
        return INFEASTABLE;
    }
    int i = 0;
    for (i = 0; i < ListLength(L); i++) {
        if (compare(L->data[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

int Equals(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}

status PriorElem(List *L, ElemType cur_e, ElemType *e) {
    if (!L) {
        return INFEASTABLE;
    }
    int i = LocateElem(L, cur_e, Equals);
    if (i == 0 || i == 1) {
        printf("cur_e is not in list or cur_e is the first item!\n");
        return ERROR;
    }
    (*e) = L->data[i - 2];
    return OK;
}

status NextElem(List *L, ElemType cur_e, ElemType *next_e) {
    if (!L) {
        return INFEASTABLE;
    }
    int i = LocateElem(L, cur_e, Equals);
    if (i == 0 || i == ListLength(L)) {
        printf("cur_e is not in list or cur_e is the last item!\n");
        return ERROR;
    }
    (*next_e) = L->data[i];
    return OK;
}

status ListInsert(List *L, int i, ElemType e) {
    if (L == NULL) {
        return INFEASTABLE;
    }
    if (i <= 0 || (i > ListLength(L) + 1)) {
        printf("location i is not in the proper area\n");
        return ERROR;
    }
    if (ListLength(L) >= L->listsize) {
        ElemType *temp = L->data;
        L->data = (ElemType *) realloc(L->data, sizeof(ElemType) * (L->listsize + LISTINCREMENT));
        int j = 0;
        for (; j < ListLength(L); j++) {
            L->data[j] = temp[j];
        }
        L->listsize += LISTINCREMENT;
    }
    int j = ListLength(L);
    for (; j >= i; j--) {
        (*L).data[j] = (*L).data[j - 1];
    }
    (*L).data[i - 1] = e;
    (*L).length++;
    return OK;
}

status ListDelete(List *L, int i, ElemType *e) {
    if (!L) {
        return INFEASTABLE;
    }
    if (i <= 0 || i > ListLength(L)) {
        printf("location i is not in the proper area\n");
        return ERROR;
    }
    if (ListEmpty(L)) {
        printf("the list is empty!\n");
        return ERROR;
    }
    (*e) = (*L).data[i - 1];
    int j = i - 1;
    for (; j < ListLength(L) - 1; j++) {
        (*L).data[j] = (*L).data[j + 1];
    }
    (*L).length--;
    return OK;
}

status ListTraverse(List *L, void visit(ElemType)) {
    if (!L) {
        return INFEASTABLE;
    }
    int i = 0;
    for (; i < ListLength(L); i++) {
        visit(L->data[i]);
    }
    return OK;
}
