//
// Created by victor on 12/15/17.
// email: chengyiwang@hustunique.com
// blog:  www.victorwang.science
//

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
#define NOTFOUND -3 //未找到

typedef int Status; //函数执行后返回的状态

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


void start(BTree *, int); //程序开始

Status InitBiTree(BTree *);  //创建一颗空树

Status DestroyBiTree(BTree *); //销毁一颗树

void InsertData(BNode *, ElemType); //在树中插入节点

void CreateBiTree(BTree *, const ElemType *); //创建一颗二叉树,输入0中止

void CreateBiTreeWithoutRightChild(BTree *, const ElemType *);

Status ClearBiTree(BTree *); //清空二叉树

int BiTreeEmpty(BTree); //判定二叉树是否为空树

int BiTreeDepth(BTree); //求二叉树的深度

BNode findNode(BNode node, int key);  //根据指定的key查找节点

char Value(BTree T, int key); //返回key节点的值

Status Assign(BTree T, int e, char value); //重新给key节点赋值为value

BNode Parent(BTree T, int e); //返回key为e的节点的父节点

BNode LeftChild(BTree T, int e); //返回key为e的节点的左孩子节点

BNode RightChild(BTree T, int e); //返回key为e的节点的右孩子节点

BNode RightSibling(BTree T, int e); //返回key为e的节点的右兄弟节点

BNode LeftSibling(BTree T, int e); //返回key为e的节点的左兄弟节点

Status InsertChild(BTree *T, int p, int LR, BTree* c); //插入子树

Status DeleteChild(BTree *T, int p, int LR); //删除子树

Status PreOrderTraverse(BTree, void (ElemType)); //前序遍历

Status InOrderTraverse(BTree, void (ElemType)); //中序遍历

Status PostOrderTraverse(BTree, void (ElemType)); //后序遍历

Status LevelOrderTraverse(BTree T, void (ElemType)); //层序遍历

Status WriteDataToFile(BTree, char *); //文件保存

Status GetDataFromFile(BTree, char *); //文件恢复
#endif; //DATASTRUCTURE_BINARYTREE_H
