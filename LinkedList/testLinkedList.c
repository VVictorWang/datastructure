/*
 * @Author: victor 
 * @Date: 2017-12-01 19:35:05 
 * @Last Modified by: victor
 * @Last Modified time: 2017-12-01 19:42:24
 */
#include "LinkedList.h"

/**
 * 自定义的遍历函数，简单地打印元素值
 * @param e 要打印的元素值
 */
void visit(ElemType e) {
    printf("%d\t", e);
}

int main() {
    int excel_length;
    printf("请输入要操作的表的数量: ");
    scanf("%d", &excel_length);
    LinkedList *L[excel_length];
    int k = 0;
    for (k = 0; k < excel_length; k++) {
        L[k] = NULL;
    }
    int op = 1;
    int excel = 1;
    printf("请选择你要操作的表： (1~%d): ", excel_length);
    scanf("%d", &excel);
    while (op) {
        printf("\n\n");
        printf("      Menu for Linear Table On LinkedList Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("    	  13. TraverseAllList 14. SwitchList\n");
        printf("    	  15. WirteListToFile 16. getDataFromFile\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~16]:");
        scanf("%d", &op);
        int isEmpty, location_get, item_get, location_insert, item_insert, location_delete, item_delete;
        int status1;
        char filename[50];
        switch (op) {
            case 1:
                status1 = InitList(&(L[excel - 1]));
                if (status1 == INFEASTABLE) {
                    printf("线性表已存在!\n");
                } else if (status1 == OK) {
                    printf("线性表创建成功！\n");
                } else
                    printf("线性表创建失败！\n");
                getchar();
                break;
            case 2:
                if (DestroyList(&(L[excel - 1])) == OK)
                    printf("\n----线性表已销毁！\n");
                else
                    printf("\n----销毁失败!\n");
                getchar();
                break;
            case 3:
                if (ClearList(L[excel - 1]) == OK) {
                    printf("\n----线性表已清空！\n");
                } else {
                    printf("\n----清空失败！\n");
                }
                getchar();
                break;
            case 4:
                isEmpty = ListEmpty(L[excel - 1]);
                if (isEmpty) {
                    printf("\n---线性表是空的!\n");
                } else {
                    printf("\n---线性表不是空的!\n");
                }
                getchar();
                break;
            case 5:
                printf("\n----线性表的长度是:%d\n", ListLength(L[excel - 1]));
                getchar();
                break;
            case 6:
                printf("请输入要得到的元素位号（大于0小于%d)：", ListLength(L[excel - 1]) + 1);
                int i;
                scanf("%d", &i);
                ElemType e;
                int getstatus = GetElem(L[excel - 1], i, &e);
                if(getstatus == OK)
                    printf("\n----得到的元素是%d\n", e);
                getchar();
                break;
            case 7:
                printf("请输入要得到的元素：");
                int e1;
                scanf("%d", &e1);
                int location = LocateElem(L[excel - 1], e1, Equals);
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
                if (PriorElem(L[excel - 1], e2, &temp) == OK) {
                    printf("\n----元素的前驱是:%d\n", temp);
                }
                getchar();
                break;
            case 9:
                printf("请输入当前元素：");
                int e3;
                scanf("%d", &e3);
                ElemType temp2;
                if (NextElem(L[excel - 1], e3, &temp2) == OK) {
                    printf("\n----元素的后继是:%d\n", temp2);
                }
                getchar();
                break;
            case 10:
                printf("请输入要插入的元素:");
                scanf("%d", &item_insert);
                printf("请输入要插入的位号(1~%d)", ListLength(L[excel - 1]) + 1);
                scanf("%d", &location_insert);
                if (ListInsert(L[excel - 1], location_insert, item_insert) == OK) {
                    printf("\n----插入成功!\n");
                } else
                    printf("\n----插入失败!\n");
                getchar();
                break;
            case 11:
                printf("请输入要删除的位号(1~%d)", ListLength(L[excel - 1]) + 1);
                scanf("%d", &location_delete);
                ElemType delete_item;
                if (ListDelete(L[excel - 1], location_delete, &delete_item) == OK) {
                    printf("\n----删除成功!\n");
                } else
                    printf("\n----删除失败!\n");
                getchar();
                break;
            case 12:
                ListTraverse(L[excel - 1], visit);
                getchar();
                break;
            case 13:
                for (k = 0; k < excel_length; k++) {
                    printf("\n---表%d: \n", k + 1);
                    ListTraverse(L[k], visit);
                }
                getchar();
                break;
            case 14:
                printf("请选择你要操作的表： (1~%d): ", excel_length);
                scanf("%d", &excel);
                getchar();
                break;
            case 15:
                getchar();
                printf("请输入文件名（保存在当前文件夹下):");
                scanf("%s", filename);
                if (WriteListToFile(L[excel - 1], filename) == OK) {
                    printf("\n---写入文件%s成功！\n", filename);
                } else
                    printf("\n---写入文件失败!\n");
                getchar();
                break;
            case 16:
                getchar();
                printf("请输入文件名（保存在当前文件夹下):");
                scanf("%s", filename);
                if (getDataFromFile(L[excel - 1], filename) == OK) {
                    printf("\n---读取文件%s成功！\n", filename);
                } else
                    printf("\n---读取文件失败!\n");
                getchar();
                break;
            case 0:
                break;
        } // end of switch
    }   // end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main