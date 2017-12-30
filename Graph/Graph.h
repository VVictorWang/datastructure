/*
 * @Author: victor 
 * @Date: 2017-12-30 14:25:16 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-30 14:25:16 
 */

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1   //操作正确
#define ERROR 0 //操作发生错误
#define TRUE 1 //函数返回true
#define FALSE 0 //函数返回false
#define  INFEASTABLE  -1 //操作不可行
#define NOTFOUND -3

typedef int Status;

int visited[100];

typedef struct EDGE {
    int from;
    int to;
    struct EDGE *nextEdge;
} *Edge;

typedef struct VERTEXTYPE {
    int key;
    char value;
} VertexType;

typedef struct VERTEX {
    VertexType data;
    Edge firstEdge;
} *Vertex, VerTEX;

typedef struct GRAPH {
    Vertex vertexes;
    int vertexNum;
    int edgeNum;
} *Graph;

void start(Graph *G, int excel_length); //开始函数

Status CreateGraph(Graph *, const VertexType *, int (*)[2]); //创建一个图

Status DestroyGraph(Graph *); //销毁图

int LocateVex(Graph G, int u); //定位图中节点的位置

char GetVex(Graph, int);

Status PutVex(Graph, int, char);

VertexType FirstAdjVex(Graph, int);

VertexType NextAdjVex(Graph, int, int);

Status InsertVex(Graph *, VertexType);

Status DeleteVex(Graph *, int);

Status InsertArc(Graph *, int, int);

Status DeleteArc(Graph *, int, int);

Status DFSTraverse(Graph, void (VertexType));

Status BFSTraverse(Graph, void (VertexType));

Status WriteDataToFile(Graph, char *);

Status GetDataFromFile(Graph *, char *);

#endif //DATASTRUCTURE_GRAPH_H
