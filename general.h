#pragma once
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef int RcdType;

typedef struct LQNode
{
    ElemType data;
    struct LQNode* next;
}LQNode, * QueuePtr;

typedef struct {
    QueuePtr front;		//队头指针
    QueuePtr rear;		//队尾指针
}LQueue;

typedef struct BBSTNode {
    RcdType data;
    int height;		//结点高度，用于计算平衡因子
    struct BBSTNode* lchild, * rchild;
}BBSTNode, * BBSTree;