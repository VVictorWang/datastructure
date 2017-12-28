/*
 * @Author: victor 
 * @Date: 2017-12-22 20:26:48 
 * @Last Modified by:   victor 
 * @Last Modified time: 2017-12-22 20:26:48 
 */

#include "BinaryTree.h"

/** 
 * @brief  allocate space to the node and assign it with e
 * @param  *node: the node to be allocated
 * @param  e: the value to be assigned
 * @retval None
 */
void allocateNode(BNode *node, ElemType e) {
    *node = (BNode) malloc(sizeof(BNODE));
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->data = e;
}

/** 
 * @brief  init an empty tree
 * @note   
 * @param  *T: the tree to be inited
 * @retval 
 */
Status InitBiTree(BTree *T) {
    if (*T) {
        printf("the tree already exists!");
        return INFEASTABLE;
    }
    (*T) = (BTree) malloc(sizeof(BTREE));
    (*T)->root = NULL;
    return OK;
}

/** 
 * @brief  destroy the node and all of its children
 * @note   
 * @param  *node: the node to be destroyed
 * @retval None
 */
void DestroyNode(BNode *node) {
    if (!*node) {
        return;
    }
    DestroyNode(&(*node)->left);
    DestroyNode(&(*node)->right);
    free(*node);
    *node = NULL;
}

/** 
 * @brief  destroy a tree
 * @note   
 * @param  *T: the tree to be destroyed
 * @retval 
 */
Status DestroyBiTree(BTree *T) {
    if (!(*T)) {
        printf("the tree doesn't exists!\n");
        return INFEASTABLE;
    }
    DestroyNode(&(*T)->root);
    free(*T);
    (*T) = NULL;
    return OK;
}

/** 
 * @brief  
 * @note   
 * @param  *node: 
 * @param  e: 
 * @retval None
 */
void InsertData(BNode *node, ElemType e) {
    if (*node == NULL) {
        allocateNode(node, e);
        return;
    }
    if (e.key < (*node)->data.key) {
        InsertData(&(*node)->left, e);
    } else if (e.key > (*node)->data.key) {
        InsertData(&(*node)->right, e);
    }
}

/**
 * 创建一颗二叉树, 输入key为0的值中止
 * @param T the root of the tree
 * @param data the data list, ends with 0
 */
void CreateBiTree(BTree *T, const ElemType *data) {
    int i = 0;
    InitBiTree(T);
    while (data[i].key != 0) {
        InsertData(&((*T)->root), data[i]);
        i++;
    }
}

void InsertDataWithoutRightC(BNode *node, ElemType e) {
    if (*node == NULL) {
        allocateNode(node, e);
        return;
    }
    InsertDataWithoutRightC(&(*node)->left, e);
}


void CreateBiTreeWithoutRightChild(BTree *T, const ElemType *data) {
    int i = 0;
    printf("ok1");
    InitBiTree(T);
    while (data[i].key != 0) {
        InsertDataWithoutRightC(&(*T)->root, data[i]);
        i++;
    }
}

/**
 * 清空二叉树
 * @param T the root of the tree
 */
Status ClearBiTree(BTree *T) {
    if (!(*T)) {
        printf("the tree doesn't exists!\n");
        return INFEASTABLE;
    }
    DestroyNode(&(*T)->root);
    return OK;
}

int BiTreeEmpty(BTree T) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    return (T->root == NULL) ? TRUE : FALSE;
}

int BNodeDepth(BNode node) {
    if (node == NULL) {
        return 1;
    } else {
        int leftHeight = BNodeDepth(node->left) + 1;
        int rightHeight = BNodeDepth(node->right) + 1;
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
}

int BiTreeDepth(BTree T) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    return BNodeDepth(T->root) - 1;
}

BNode findNode(BNode node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data.key) {
        return node;
    } else {
        BNode temp = findNode(node->left, key);
        if (temp == NULL) {
            return findNode(node->right, key);
        } else {
            return temp;
        }
    }
}

char Value(BTree T, int key) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    BNode node = findNode(T->root, key);
    if (node != NULL) {
        return node->data.others;
    } else {
        return NOTFOUND;
    }
}

Status Assign(BTree T, int e, char value) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    BNode node = findNode(T->root, e);
    if (node == NULL) {
        printf("the node not exists in the tree");
        return ERROR;
    }
    node->data.others = value;
    return OK;
}

BNode getParent(BNode node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if ((node->left != NULL && key == node->left->data.key) ||
        (node->right != NULL && key == node->right->data.key)) {
        return node;
    } else {
        BNode t = getParent(node->left, key);
        if (t == NULL) {
            return getParent(node->right, key);
        }
        return t;
    }
}


BNode Parent(BTree T, int e) {
    if (!T) {
        printf("the tree not exists!\n");
        return NULL;
    }
    return getParent(T->root, e);
}

BNode LeftChild(BTree T, int e) {
    if (!T) {
        printf("the tree not exists!\n");
        return NULL;
    }
    BNode node = findNode(T->root, e);
    if (node == NULL) {
        printf("the node not exists in the tree");
        return NULL;
    } else {
        return node->left;
    }
}

BNode RightChild(BTree T, int e) {
    if (!T) {
        printf("the tree not exists!\n");
        return NULL;
    }
    BNode node = findNode(T->root, e);
    if (node == NULL) {
        printf("the node not exists in the tree");
        return NULL;
    } else {
        return node->right;
    }
}

BNode RightSibling(BTree T, int e) {
    BNode parent = Parent(T, e);
    if (parent == NULL || parent->right->data.key == e) {
        return NULL;
    } else {
        return parent->right;
    }
}

BNode LeftSibling(BTree T, int e) {
    BNode parent = Parent(T, e);
    if (parent == NULL || parent->left->data.key == e) {
        return NULL;
    } else {
        return parent->left;
    }
}

Status InsertChild(BTree *T, int p, int LR, BTree* c) {
    if (!*T || !c) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    BNode node = findNode((*T)->root, p);
    if (node == NULL) {
        printf("the node not exists in the tree");
        return ERROR;
    }
    if (LR == 0) {
        (*c)->root->right = node->left;
        node->left = (*c)->root;
    } else {
        (*c)->root->right = node->right;
        node->right = (*c)->root;
    }
    return OK;
}

Status DeleteChild(BTree *T, int p, int LR) {
    if (!*T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    BNode node = findNode((*T)->root, p);
    if (node == NULL) {
        printf("the node not exists in the tree");
        return ERROR;
    }
    if (LR == 0) {
        DestroyNode(&node->left);
        node->left = NULL;
    } else {
        DestroyNode(&node->right);
        node->right = NULL;
    }
    return OK;
}

void PreOrderTraverseNode(BNode node, void visit(ElemType)) {
    if (node == NULL) {
        return;
    }
    visit(node->data);
    PreOrderTraverseNode(node->left, visit);
    PreOrderTraverseNode(node->right, visit);
}

Status PreOrderTraverse(BTree T, void visit(ElemType)) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    PreOrderTraverseNode(T->root, visit);
    return OK;
}

void InOrderTraverseNode(BNode node, void visit(ElemType)) {
    if (node == NULL) {
        return;
    }
    InOrderTraverseNode(node->left, visit);
    visit(node->data);
    InOrderTraverseNode(node->right, visit);
}

Status InOrderTraverse(BTree T, void visit(ElemType)) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    InOrderTraverseNode(T->root, visit);
    return OK;
}

void PostOrderTraverseNode(BNode node, void visit(ElemType)) {
    if (node == NULL) {
        return;
    }
    PostOrderTraverseNode(node->left, visit);
    PostOrderTraverseNode(node->right, visit);
    visit(node->data);
}

Status PostOrderTraverse(BTree T, void visit(ElemType)) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    PostOrderTraverseNode(T->root, visit);
    return OK;
}

void LevelOrder(BNode node, int level, void visit(ElemType)) {
    if (node == NULL || level < 1) {
        return;
    }
    if (level == 1) {
        visit(node->data);
        return;
    }
    LevelOrder(node->left, level - 1, visit);
    LevelOrder(node->right, level - 1, visit);
}

Status LevelOrderTraverse(BTree T, void visit(ElemType)) {
    if (!T) {
        printf("the tree not exists!\n");
        return INFEASTABLE;
    }
    int depth = BiTreeDepth(T);
    int i = 0;
    for (i = 1; i <= depth; i++) {
        LevelOrder(T->root, i, visit);
    }
}

void WriteData(BNode node, FILE *p) {
    if (node == NULL) {
        return;
    }
    if (fwrite(&(node->data), sizeof(ElemType), 1, p) != 1) {
        printf("write file error!\n");
        exit(0);
    }
    WriteData(node->left, p);
    WriteData(node->right, p);
}

Status WriteDataToFile(BTree T, char *filename) {
    if (!T) {
        printf("the tree not exists!\n");
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
    FILE *p = fopen(current_file, "wb+");
    if (p == NULL) {
        printf("open file error!\n");
        return ERROR;
    }
    WriteData(T->root, p);
    fclose(p);
    return OK;
}

Status GetDataFromFile(BTree T, char *filename) {
    if (!T) {
        printf("the tree not exists!\n");
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
    FILE *p = fopen(current_file, "rb");
    if (p == NULL) {
        printf("open file error!\n");
        return ERROR;
    }
    ElemType data;
    while (fread(&data, sizeof(ElemType), 1, p) == 1) {
        InsertData(&(T->root), data);
    }
    fclose(p);
    return OK;
}


