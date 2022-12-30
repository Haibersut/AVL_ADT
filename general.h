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
    QueuePtr front;		//��ͷָ��
    QueuePtr rear;		//��βָ��
}LQueue;

typedef struct BBSTNode {
    RcdType data;
    int height;		//���߶ȣ����ڼ���ƽ������
    struct BBSTNode* lchild, * rchild;
}BBSTNode, * BBSTree;