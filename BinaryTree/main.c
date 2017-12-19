#include "BinaryTree.h"

int main() {
    int excel_length;
    printf("请输入要操作的树的数量: ");
    scanf("%d", &excel_length);
    BTree L[excel_length];
    int k = 0;
    for (k = 0; k < excel_length; k++) {
        L[k] = NULL;
    }
    start(L, excel_length);
}//end of main