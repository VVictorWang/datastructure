/*
 * @Author: victor 
 * @Date: 2017-12-19 21:34:12 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-19 21:34:12 
 */

#include "BinaryTree.h"

/**
 * 自定义的遍历函数，简单地打印元素值
 * @param e 要打印的元素值
 */
void visit(ElemType e) {
    printf("key: %d\t data:%c\n", e.key, e.others);
}

void start(BTree *L, int excel_length) {
    int op = 1;
    int excel = 1;
    printf("请选择你要操作的二叉树： (1~%d): ", excel_length);
    scanf("%d", &excel);
    while (op) {
        printf("\n\n");
        printf("      Menu for Linear Table On BinaryTree Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitTree            2. DestroyTree\n");
        printf("    	  3. ClearTree           4. TreeEmpty\n");
        printf("    	  5. TreeDepth           6. CreateTree \n");
        printf("    	  7. getRoot             8. getValue\n");
        printf("    	  9. assignValue         10. getParent\n");
        printf("    	  11. getLeftChild       12. getRightChild\n");
        printf("    	  13. getLeftSibling     14. getRightSibling\n");
        printf("    	  15. InsertChild        16. DeleteChild\n");
        printf("    	  17. PreOrderTraverse   18. InOrderTraverse\n");
        printf("    	  19. PostOrderTraverse  20. LevelOrderTraverse\n");
        printf("    	  21. SwitchForm         22. WriteDataToFile\n");
        printf("    	  23. GetDataFromFile\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~23]:");
        scanf("%d", &op);
        int isEmpty;
        int status1;
        char filename[50];
        switch (op) {
            case 1:
                status1 = InitBiTree(&(L[excel - 1]));
                if (status1 == OK) {
                    printf("空二叉树表创建成功！\n");
                } else
                    printf("空二叉树创建失败！\n");
                getchar();
                break;
            case 2:
                if (DestroyBiTree(&(L[excel - 1])) == OK)
                    printf("\n----二叉树已销毁！\n");
                else
                    printf("\n----销毁失败!\n");
                getchar();
                break;
            case 3:
                if (ClearBiTree(&(L[excel - 1])) == OK) {
                    printf("\n----二叉树已清空！\n");
                } else {
                    printf("\n----清空失败！\n");
                }
                getchar();
                break;
            case 4:
                isEmpty = BiTreeEmpty(L[excel - 1]);
                if (isEmpty) {
                    printf("\n---二叉树是空的!\n");
                } else {
                    printf("\n---二叉树不是空的!\n");
                }
                getchar();
                break;
            case 5:
                printf("\n----二叉树的深度度是:%d\n", BiTreeDepth(L[excel - 1]));
                getchar();
                break;
            case 6:
                printf("please enter the key(an interger) and value(a char)(ends when both key and value are 0):");
                ElemType e[100];
                int key, ei = 0;
                char vaule;
                scanf("%d %c", &key, &vaule);
                while (key != 0 && vaule != '0') {
                    e[ei].key = key;
                    e[ei].others = vaule;
                    ei++;
                    scanf("%d %c", &key, &vaule);
                }
                e[ei].key = 0;
                e[ei].others = '0';
                CreateBiTree(&(L[excel - 1]), e);
                printf("creat tree successfully!\n");
                getchar();
                break;
            case 7:
                if (L[excel - 1] == NULL) {
                    printf("the tree does not exists!\n");
                } else if (L[excel - 1]->root == NULL) {
                    printf("the tree is empty!\n");
                } else {
                    printf("the root is:\n");
                    visit(L[excel - 1]->root->data);
                }
                getchar();
                break;
            case 8:
                printf("please input the key:");
                scanf("%d", &key);
                vaule = Value(L[excel - 1], key);
                if (vaule == NOTFOUND) {
                    printf("the key is not in the tree!\n");
                } else {
                    printf("the value is:%c\n", vaule);
                }
                getchar();
                break;
            case 9:
                printf("please input the key and the new value(seprates with space charater):");
                scanf("%d %c", &key, &vaule);
                Assign(L[excel - 1], key, vaule);
                getchar();
                break;
            case 10:
                printf("please input the key:");
                scanf("%d", &key);
                BNode node = Parent(L[excel - 1], key);
                if (node != NULL) {
                    printf("the parent node is:\n");
                    visit(node->data);
                }
                getchar();
                break;
            case 11:
                printf("please input the key:");
                scanf("%d", &key);
                node = LeftChild(L[excel - 1], key);
                if (node != NULL) {
                    printf("the left child is:\n");
                    visit(node->data);
                }
                getchar();
                break;
            case 12:
                printf("please input the key:");
                scanf("%d", &key);
                node = RightChild(L[excel - 1], key);
                if (node != NULL) {
                    printf("the right child is:\n");
                    visit(node->data);
                }
                getchar();
                break;
            case 13:
                printf("please input the key:");
                scanf("%d", &key);
                node = LeftSibling(L[excel - 1], key);
                if (node != NULL) {
                    printf("the left sibling is:\n");
                    visit(node->data);
                }
                getchar();
                break;
            case 14:
                printf("please input the key:");
                scanf("%d", &key);
                node = RightSibling(L[excel - 1], key);
                if (node != NULL) {
                    printf("the right sibling is:\n");
                    visit(node->data);
                }
                getchar();
                break;
            case 15:
                printf("please input the key:");
                int insertkey;
                scanf("%d", &insertkey);
                printf("please choose whether you want to insert it as left child or right child(0 for left 1 for right):");
                int LR;
                scanf("%d", &LR);
                printf("input the tree without right child(input key and values):\n");
                scanf("%d %c", &key, &vaule);
                ei = 0;
                while (key != 0 && vaule != '0') {
                    e[ei].key = key;
                    e[ei].others = vaule;
                    ei++;
                    scanf("%d %c", &key, &vaule);
                }
                e[ei].key = 0;
                e[ei].others = '0';
                BTree C;
                CreateBiTreeWithoutRightChild(&C, e);
                if (InsertChild(&L[excel - 1], insertkey, LR, C) == OK) {
                    printf("insert child successfully!\n");
                }
                getchar();
                break;
            case 16:
                printf("please input the key:");
                scanf("%d", &key);
                printf("please choose whether you want to delete it as left child or right child(0 for left 1 for right):");
                scanf("%d", &LR);
                if (DeleteChild(&(L[excel - 1]), key, LR) == OK) {
                    printf("delete child successfully!\n");
                }
                getchar();
                break;
            case 17:
                PreOrderTraverse(L[excel - 1], visit);
                getchar();
                break;
            case 18:
                InOrderTraverse(L[excel - 1], visit);
                getchar();
                break;
            case 19:
                PostOrderTraverse(L[excel - 1], visit);
                getchar();
                break;
            case 20:
                LevelOrderTraverse(L[excel - 1], visit);
                getchar();
                break;
            case 21:
                printf("input the form index(1~%d): ", excel_length);
                scanf("%d", &excel);
                getchar();
                break;
            case 22:
                printf("请输入文件名（保存在当前文件夹下):");
                scanf("%s", filename);
                if (WriteDataToFile(L[excel - 1], filename) == OK) {
                    printf("\n---写入文件%s成功！\n", filename);
                } else
                    printf("\n---写入文件失败!\n");
                getchar();
                break;
            case 23:
                printf("请输入文件名（保存在当前文件夹下):");
                scanf("%s", filename);
                if (GetDataFromFile(L[excel - 1], filename) == OK) {
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
}