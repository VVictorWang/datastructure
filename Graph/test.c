/*
 * @Author: victor 
 * @Date: 2017-12-30 14:30:01 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-30 14:30:01 
 */
#include "Graph.h"

int main() {
    int excel_length;
    printf("input the number of the graphs you want to operate: ");
    scanf("%d", &excel_length);
    Graph L[excel_length];
    int k = 0;
    for (k = 0; k < excel_length; k++) {
        L[k] = NULL;
    }
    start(L, excel_length);
    return 0;
}//end of main