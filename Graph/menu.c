/*
 * @Author: victor 
 * @Date: 2017-12-30 14:27:42 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-30 14:27:42 
 */

#include "Graph.h"

///**
// * 自定义的遍历函数，简单地打印元素值
// * @param e 要打印的元素值
// */
void visit(VertexType e) {
    if (e.key != 0) {
        printf("key: %d\t data:%c\n", e.key, e.value);
    }
}

void start(Graph *G, int excel_length) {
    int op = 1;
    int excel = 1;
    printf("please select the graph index you want to operate： (1~%d): ", excel_length);
    scanf("%d", &excel);
    while (op) {
        printf("\n\n");
        printf("      Menu for Operation On Graph Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitGraph           2. DestroyGraph\n");
        printf("    	  3. LocateVex           4. GetVex \n");
        printf("    	  5. PutVex              6. FirstAdjVex \n");
        printf("    	  7. NextAdjVex          8. InsertVex\n");
        printf("    	  9. DeleteVex           10. InsertArc\n");
        printf("    	  11. DeleteArc          12. DFSTraverse\n");
        printf("    	  13. BFSTraverse        14. SwitchForm\n");
        printf("    	  15. WriteDataToFile    16. GetDataToFile\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    please choose your operation[0~16]:");
        scanf("%d", &op);
        int status1;
        char filename[50];
        int i, j;
        switch (op) {
            case 1:
                i = j = 0;
                int edges[30][2];
                VertexType vertexes[30];
                printf("please input the vertexes(key and value end with 0):");
                int vertex = 0;
                char value = '0';
                do {
                    scanf("%d %c", &vertex, &value);
                    vertexes[i].key = vertex;
                    vertexes[i++].value = value;

                } while (vertex != 0);
                vertexes[i++].key = 0;
                int from = 0, to = 0;
                printf("please input the edges(end with 0 0):");
                do {
                    scanf("%d%d", &from, &to);
                    edges[j][0] = from;
                    edges[j++][1] = to;
                } while (from != 0);
                edges[j][0] = 0;
                edges[j++][1] = 0;
                status1 = CreateGraph(&(G[excel - 1]), vertexes, edges);
                if (status1 == OK) {
                    printf("the graph created successfully!\n");
                } else
                    printf("the graph created failure!\n");
                getchar();
                break;
            case 2:
                if (DestroyGraph(&(G[excel - 1])) == OK)
                    printf("\n----the graph has been destroyed！\n");
                else
                    printf("\n----destroy failure!\n");
                getchar();
                break;
            case 3:
                printf("input the vertex's key:");
                scanf("%d", &vertex);
                int location = LocateVex(G[excel - 1], vertex);
                if (location != NOTFOUND && location != INFEASTABLE) {
                    printf("the location of the vertex is: %d\n", location);
                } else {
                    printf("the graph does not contain the vertex!\n");
                }
                getchar();
                break;
            case 4:
                printf("input the vertex's key:");
                scanf("%d", &vertex);
                location = GetVex(G[excel - 1], vertex);
                if (location != ERROR && location != INFEASTABLE) {
                    printf("the value of the vertex is: %c\n", location);
                }
                getchar();
                break;
            case 5:
                printf("input the vertex's key:");
                scanf("%d", &vertex);
                getchar();
                printf("input the new value:");
                scanf("%c", &value);
                status1 = PutVex(G[excel - 1], vertex, value);
                if (status1 == OK) {
                    printf("change the value of the vertex successfully!\n");
                }
                getchar();
                break;
            case 6:
                printf("input the vertex's key:");
                scanf("%d", &vertex);
                VertexType myVertex = FirstAdjVex(G[excel - 1], vertex);
                if (myVertex.key == 0) {
                    printf("the vertex does not have adj vertex!\n");
                } else {
                    printf("the first adj vertex is:\n");
                    visit(myVertex);
                }
                getchar();
                break;
            case 7:
                printf("input the vertex's key:");
                scanf("%d", &vertex);
                printf("input the adj vertex's key:");
                int adjVertex;
                scanf("%d", &adjVertex);
                myVertex = NextAdjVex(G[excel - 1], vertex, adjVertex);
                if (myVertex.key == 0) {
                    printf("the vertex does not have next adj vertex!\n");
                } else {
                    printf("the next adj vertex is:\n");
                    visit(myVertex);
                }
                getchar();
                break;
            case 8:
                printf("please input the new vertex(key and value):");
                scanf("%d %c", &vertex, &value);
                myVertex.key = vertex;
                myVertex.value = value;
                if (InsertVex(&(G[excel - 1]), myVertex) == OK) {
                    printf("insert vertex successfully!\n");
                }
                getchar();
                break;
            case 9:
                printf("please input the vertex's key :");
                scanf("%d", &vertex);
                if (DeleteVex(&(G[excel - 1]), vertex) == OK) {
                    printf("delete vertex successfully!\n");
                }
                getchar();
                break;
            case 10:
                printf("please input the start key:");
                int startKey, endKey;
                scanf("%d", &startKey);
                printf("please input the end key:");
                scanf("%d", &endKey);
                if (InsertArc(&(G[excel - 1]), startKey, endKey) == OK) {
                    printf("insert arc successfully!\n");
                }
                getchar();
                break;
            case 11:
                printf("please input the start key:");
                scanf("%d", &startKey);
                printf("please input the end key:");
                scanf("%d", &endKey);
                if (DeleteArc(&(G[excel - 1]), startKey, endKey) == OK) {
                    printf("delete arc successfully!\n");
                }
                getchar();
                break;
            case 12:
                DFSTraverse(G[excel - 1], visit);
                getchar();
                break;
            case 13:
                BFSTraverse(G[excel - 1], visit);
                getchar();
                break;
            case 14:
                printf("input the form index(1~%d): ", excel_length);
                scanf("%d", &excel);
                getchar();
                break;
            case 15:
                printf("please input the file name:");
                scanf("%s", filename);
                if (WriteDataToFile(G[excel - 1], filename) == OK) {
                    printf("\n---write to file % successfully！\n", filename);
                } else
                    printf("\n---unexpected error happened!\n");
                getchar();
                break;
            case 16:
                printf("please input the file name:");
                scanf("%s", filename);
                if (GetDataFromFile(&(G[excel - 1]), filename) == OK) {
                    printf("\n---get data from file %s successfully！\n", filename);
                } else
                    printf("\n---unexpected error happened!\n");
                getchar();
                break;
            case 0:
                break;
        } // end of switch
    }   // end of while
    printf("Good Bye!\n");
}