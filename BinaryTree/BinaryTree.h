/*
 * @Author: victor 
 * @Date: 2017-12-19 21:32:20 
 * @Last Modified by: victor
 * @Last Modified time: 2017-12-19 21:35:07
 */

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1   //操作正确
#define ERROR 0 //操作发生错误
#define TRUE 1 //函数返回true
#define FALSE 0 //函数返回false
#define  INFEASTABLE -1 //操作不可行
#define OVERFLOW -2 //栈溢出
#define NOTFOUND -3

typedef int Status;

typedef struct ELEMTYPE {
    int key;
    char others;
} ElemType;

typedef struct BINARYNODE {
    ElemType data;
    struct BINARYNODE *left;
    struct BINARYNODE *right;
} *BNode, BNODE;

typedef struct BINARYTREE {
    BNode root;
} *BTree, BTREE;


void start(BTree *, int);

Status InitBiTree(BTree *);  //创建一颗空树

Status DestroyBiTree(BTree *); //销毁一颗树

void InsertData(BNode *, ElemType); //在树中插入节点

void CreateBiTree(BTree *, const ElemType *); //创建一颗二叉树,输入0中止

void CreateBiTreeWithoutRightChild(BTree *, const ElemType *);

Status ClearBiTree(BTree *); //清空二叉树

int BiTreeEmpty(BTree); //判定二叉树是否为空树

int BiTreeDepth(BTree); //求二叉树的深度

//BTree Root(BTree); //返回根
BNode findNode(BNode node, int key);

char Value(BTree T, int key);

Status Assign(BTree T, int e, char value);

BNode Parent(BTree T, int e);

BNode LeftChild(BTree T, int e);

BNode RightChild(BTree T, int e);

BNode RightSibling(BTree T, int e);

BNode LeftSibling(BTree T, int e);

Status InsertChild(BTree *T, int p, int LR, BTree c);

Status DeleteChild(BTree *T, int p, int LR);

Status PreOrderTraverse(BTree, void (ElemType));

Status InOrderTraverse(BTree, void (ElemType));

Status PostOrderTraverse(BTree, void (ElemType));

Status LevelOrderTraverse(BTree T, void (ElemType));

Status WriteDataToFile(BTree, char *);

Status GetDataFromFile(BTree, char *);

#endif //DATASTRUCTURE_BINARYTREE_H
