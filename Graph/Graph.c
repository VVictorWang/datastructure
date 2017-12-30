/*
 * @Author: victor 
 * @Date: 2017-12-30 14:26:10 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-30 14:26:10 
 */

#include "Graph.h"
#include "../Dequeue/Dequeue.h"

const VertexType nullVertex = {0, '0'};

/**
 *
 * @param G
 * @param vertexes
 * @param egdes
 * @return
 */
Status CreateGraph(Graph *G, const VertexType *vertexes, int (*egdes)[2]) {
    if (*G) {
        printf("the graph already exists!\n");
        return INFEASTABLE;
    }
    int i = 0, from = 0, to;
    int va, vb;
    Edge p;
    *G = (Graph) malloc(sizeof(struct GRAPH));
    (*G)->edgeNum = (*G)->vertexNum = 0;
    int vertexNum = 0;
    while (vertexes[i].key != 0) {
        vertexNum++;
        i++;
    }
    (*G)->vertexNum = vertexNum;
    (*G)->vertexes = (Vertex) malloc(sizeof(struct VERTEX) * vertexNum);
    i = 0;
    while (vertexes[i].key != 0) {
        (*G)->vertexes[i].data = vertexes[i];
        (*G)->vertexes[i].firstEdge = NULL;
        i++;
    }
    i = 0;
    int edgeNum = 0;
    while (egdes[i][0] != 0 && egdes[i][1] != 0) {
        edgeNum++;
        i++;
    }
    (*G)->edgeNum = edgeNum;
    for (i = 0; i < edgeNum; i++) {
        va = egdes[i][0];
        vb = egdes[i][1];
        from = LocateVex(*G, va);
        to = LocateVex(*G, vb);
        p = (Edge) malloc(sizeof(struct EDGE));
        p->from = from;
        p->to = to;
        p->nextEdge = (*G)->vertexes[from].firstEdge;
        (*G)->vertexes[from].firstEdge = p;
    }
    return OK;
}

/**
 * destroy the graph
 * @param G
 * @return
 */
Status DestroyGraph(Graph *G) {
    if (!*G) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int i;
    Edge p, q;
    for (i = 0; i < (*G)->vertexNum; i++) {
        p = (*G)->vertexes[i].firstEdge;
        while (p) {
            q = p->nextEdge;
            free(p);
            p = q;
        }
    }
    free((*G)->vertexes);
    (*G)->edgeNum = (*G)->edgeNum = 0;
    free(*G);
    return OK;
}

/**
 * locate the vertex
 * @param G
 * @param u
 * @return
 */
int LocateVex(Graph G, int u) {
    if (!G) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int i;
    for (i = 0; i < G->vertexNum; i++)
        if (u == G->vertexes[i].data.key) {
            return i;
        }
    return NOTFOUND;
}

char GetVex(Graph G, int key) {
    if (!G) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return ERROR;
    }
    return G->vertexes[location].data.value;
}

Status PutVex(Graph G, int key, char value) {
    if (!G) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return ERROR;
    }
    G->vertexes[location].data.value = value;
    return OK;
}

VertexType FirstAdjVex(Graph G, int key) {
    if (!G) {
        printf("the graph does not exists!\n");
        return nullVertex;
    }
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return nullVertex;
    }
    if (G->vertexes[location].firstEdge == NULL) {
        return nullVertex;
    }
    return G->vertexes[G->vertexes[location].firstEdge->to].data;
}

VertexType NextAdjVex(Graph G, int key, int w) {
    if (!G) {
        printf("the graph does not exists!\n");
        return nullVertex;
    }
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return nullVertex;
    }
    Edge p = G->vertexes[location].firstEdge;
    while (p != NULL && p->to != LocateVex(G, w)) {
        p = p->nextEdge;
    }
    if (p == NULL || p->nextEdge == NULL) {
        return nullVertex;
    }
    return G->vertexes[p->nextEdge->to].data;
}

Status InsertVex(Graph *G, VertexType newVertex) {
    if (!(*G)) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    Vertex newVertexes = (Vertex) realloc((*G)->vertexes,
                                          sizeof(struct VERTEX) * ((*G)->vertexNum + 1));
    if (newVertexes != NULL) {
        VerTEX myNew;
        myNew.data = newVertex;
        myNew.firstEdge = NULL;
        (*G)->vertexes = newVertexes;
        (*G)->vertexes[(*G)->vertexNum] = myNew;
        (*G)->vertexNum++;
        return OK;
    } else {
        return INFEASTABLE;
    }
}

Status DeleteVex(Graph *G, int key) {
    if (!(*G)) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int location = LocateVex(*G, key);
    if (location == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return ERROR;
    }
    int i = 0;
    Edge p = (*G)->vertexes[location].firstEdge, q = p;
    while (p != NULL) {
        q = p;
        p = p->nextEdge;
        free(q);
        (*G)->edgeNum--;
    }
    for (i = location + 1; i < (*G)->vertexNum; i++) {
        (*G)->vertexes[i - 1] = (*G)->vertexes[i];
    }
    (*G)->vertexNum--;
    for (i = 0; i < (*G)->vertexNum; i++) {
        p = (*G)->vertexes[i].firstEdge;
        while (p != NULL) {
            if (p->to == location) {
                if (p == (*G)->vertexes[i].firstEdge) // 待删结点是第1个结点
                {
                    (*G)->vertexes[i].firstEdge = p->nextEdge;
                    free(p);
                    p = (*G)->vertexes[i].firstEdge;
                    (*G)->edgeNum--;  // 弧或边数减1
                } else {
                    q->nextEdge = p->nextEdge;
                    free(p);
                    p = q->nextEdge;
                    (*G)->edgeNum--;  // 弧或边数减1

                }
            } else {
                if (p->to > location) {
                    p->to--;
                }
                q = p;
                p = p->nextEdge;
            }
        }
    }
    return OK;
}

Status InsertArc(Graph *G, int from, int to) {
    if (!(*G)) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int i = LocateVex(*G, from);
    int j = LocateVex(*G, to);
    if (i == NOTFOUND || j == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return ERROR;
    }
    Edge p = (Edge) malloc(sizeof(struct EDGE));
    if (p == NULL) {
        printf("cannot malloc space!\n");
        return ERROR;
    }
    p->from = i;
    p->to = j;
    p->nextEdge = (*G)->vertexes[i].firstEdge;
    (*G)->vertexes[i].firstEdge = p;
    (*G)->edgeNum++;
    return OK;
}

Status DeleteArc(Graph *G, int from, int to) {
    if (!(*G)) {
        printf("the graph does not exists!\n");
        return INFEASTABLE;
    }
    int i = LocateVex(*G, from);
    int j = LocateVex(*G, to);
    if (i == NOTFOUND || j == NOTFOUND) {
        printf("the graph does not contain the vertex!\n");
        return ERROR;
    }
    Edge p = (*G)->vertexes[i].firstEdge;
    Edge q = p;
    while (p != NULL) {
        if (p->to == j) {
            break;
        }
        q = p;
        p = p->nextEdge;
    }
    if (p == NULL) {
        return ERROR;
    }
    if (q != p) {
        q->nextEdge = p->nextEdge;
    } else {
        (*G)->vertexes[i].firstEdge = p->nextEdge;
    }
    (*G)->edgeNum--;
    free(p);
    return OK;
}

int FirstAdjVexForDFS(Graph G, int key) {
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        return -1;
    }
    if (G->vertexes[location].firstEdge == NULL) {
        return -1;
    }
    return G->vertexes[G->vertexes[location].firstEdge->to].data.key;
}

int NextAdjVexForDFS(Graph G, int key, int w) {
    int location = LocateVex(G, key);
    if (location == NOTFOUND) {
        return -1;
    }
    Edge p = G->vertexes[location].firstEdge;
    while (p != NULL && p->to != LocateVex(G, w)) {
        p = p->nextEdge;
    }
    if (p == NULL || p->nextEdge == NULL) {
        return -1;
    }
    return G->vertexes[p->nextEdge->to].data.key;
}


void DFS(Graph G, int v, void visit(VertexType)) {
    visited[v] = 1;
    visit(G->vertexes[v].data);
    int w = FirstAdjVexForDFS(G, G->vertexes[v].data.key);
    for (; w >= 0; w = NextAdjVexForDFS(G, G->vertexes[v].data.key, w)) {
        if (!visited[LocateVex(G, w)]) {
            DFS(G, LocateVex(G, w), visit);
        }
    }
}

Status DFSTraverse(Graph G, void visit(VertexType)) {
    if (!G) {
        printf("the graph not exists!\n");
        return INFEASTABLE;
    }
    int v;
    for (v = 0; v < G->vertexNum; v++) {
        visited[v] = 0;
    }
    for (v = 0; v < G->vertexNum; v++) {
        if (!visited[v]) {
            DFS(G, v, visit);
        }
    }
    return OK;
}

Status BFSTraverse(Graph G, void visit(VertexType)) {
    if (!G) {
        printf("the graph not exists!\n");
        return INFEASTABLE;
    }
    int v = 0, u = 0;
    for (v = 0; v < G->vertexNum; v++) {
        visited[v] = 0;
    }
    Dequeue q;
    q = NULL;
    initQueue(&q, G->vertexNum);
    for (v = 0; v < G->vertexNum; v++) {
        if (!visited[v]) {
            visited[v] = 1;
            visit(G->vertexes[v].data);
            enQueue(q, v);
            while (!queueEmpty(q)) {
                deQueue(q, &u);
                int w = FirstAdjVexForDFS(G, G->vertexes[u].data.key);
                for (; w >= 0; w = NextAdjVexForDFS(G, G->vertexes[u].data.key, w)) {
                    int location = LocateVex(G, w);
                    if (!visited[location]) {
                        visited[location] = 1;
                        visit(G->vertexes[location].data);
                        enQueue(q, location);
                    }
                }
            }
        }
    }
    clear(q);
    return OK;
}

Status WriteDataToFile(Graph G, char *filename) {
    if (!G) {
        printf("the graph not exists!\n");
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
    FILE *p = fopen(current_file, "w+");
    if (p == NULL) {
        printf("open file error!\n");
        return ERROR;
    }
    int edges[G->edgeNum][2];
    int v = 0;
    i = 0;
    for (v = 0; v < G->vertexNum; v++) {
        Edge edge = G->vertexes[v].firstEdge;
        while (edge != NULL) {
            edges[i][0] = G->vertexes[edge->from].data.key;
            edges[i++][1] = G->vertexes[edge->to].data.key;
            edge = edge->nextEdge;
        }
        fprintf(p, "%d %c", G->vertexes[v].data.key, G->vertexes[v].data.value);
    }
    fprintf(p, "%d\n", -1);
    for (v = 0; v < G->edgeNum; v++) {
        fprintf(p, "%d %d ", edges[v][0], edges[v][1]);
    }
    fprintf(p, "%d\n", -1);
    fclose(p);
    return OK;
}

Status GetDataFromFile(Graph *G, char *filename) {
    if (*G) {
        printf("the graph already  exists!\n");
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
        printf("open file error!\n");
        return INFEASTABLE;
    }
    VertexType myVertex[30];
    int key;
    i = 0;
    char space, value;
    fscanf(p, "%d", &key);
    while (key != -1) {
        if (feof(p)) {
            break;
        }
        fscanf(p, "%c%c", &space, &value);
        myVertex[i].key = key;
        myVertex[i++].value = value;
        if (feof(p)) {
            break;
        }
        fscanf(p, "%d", &key);
    }
    myVertex[i].key = 0;
    myVertex[i++].value = 0;
    int from, to;
    int edges[30][2];
    i = 0;
    fscanf(p, "%d%d", &from, &to);
    while (from != -1) {
        edges[i][0] = from;
        edges[i++][1] = to;
        fscanf(p, "%d%d", &from, &to);
    }
    edges[i][0] = 0;
    edges[i++][1] = 0;
    CreateGraph(G, myVertex, edges);
    fclose(p);
    return OK;
}