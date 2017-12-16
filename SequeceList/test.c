
#include "SequenceList.h"

void visit(ElemType e) {
    printf("%d\t", e);
}

int main() {
    List *L;
    L = NULL;
    int op = 1;
    while (op) {
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d", &op);
        int isEmpty, location_get, item_get, location_insert, item_insert, location_delete, item_delete;
        int status1;
        switch (op) {
            case 1:
                status1 = InitList(&L);
                if (status1 == OK) {
                    printf("线性表创建成功！\n");
                } else
                    printf("线性表创建失败！\n");
                getchar();
                break;
            case 2:
                DestroyList(&L);
                printf("\n----线性表已销毁！\n");
                getchar();
                break;
            case 3:
                ClearList(L);
                printf("\n----线性表已清空！\n");
                getchar();
                break;
            case 4:
                isEmpty = ListEmpty(L);
                if (isEmpty) {
                    printf("\n---线性表是空的!\n");
                } else {
                    printf("\n---线性表不是空的!\n");
                }
                getchar();
                break;
            case 5:
                printf("\n----线性表的长度是:%d\n", ListLength(L));
                getchar();
                break;
            case 6:
                printf("请输入要得到的元素位号（大于0小于%d)：", ListLength(L) + 1);
                int i;
                scanf("%d", &i);
                ElemType e;
                GetElem(L, i, &e);
                printf("\n----得到的元素是%d\n", e);
                getchar();
                break;
            case 7:
                printf("请输入要得到的元素：");
                int e1;
                scanf("%d", &e1);
                int location = LocateElem(L, e1, Equals);
                if (!location) {
                    printf("\n----元素不存在！\n");
                } else
                    printf("\n----元素的位号是:%d\n", location);
                getchar();
                break;
            case 8:
                printf("请输入当前元素：");
                int e2;
                scanf("%d", &e2);
                ElemType temp;
                if (PriorElem(L, e2, &temp) == OK) {
                    printf("\n----元素的前驱是:%d\n", temp);
                }
                getchar();
                break;
            case 9:
                printf("请输入当前元素：");
                int e3;
                scanf("%d", &e3);
                ElemType temp2;
                if (NextElem(L, e3, &temp2) == OK) {
                    printf("\n----元素的后继是:%d\n", temp2);
                }
                getchar();
                break;
            case 10:
                printf("请输入要插入的元素:");
                scanf("%d", &item_insert);
                printf("请输入要插入的位号(1~%d)", ListLength(L) + 1);
                scanf("%d", &location_insert);
                if (ListInsert(L, location_insert, item_insert) == OK) {
                    printf("\n----插入成功!\n");
                } else
                    printf("\n----插入失败!\n");
                getchar();
                break;
            case 11:
                printf("请输入要删除的位号(1~%d)", ListLength(L) + 1);
                scanf("%d", &location_delete);
                ElemType delete_item;
                if (ListDelete(L, location_delete, &delete_item) == OK) {
                    printf("\n----删除成功!\n");
                } else
                    printf("\n----删除失败!\n");
                getchar();
                break;
            case 12:
                ListTraverse(L, visit);
                getchar();
                break;
            case 0:
                break;
        } // end of switch
    }   // end of while
    printf("欢迎下次再使用本系统！\n");
}   //end of main