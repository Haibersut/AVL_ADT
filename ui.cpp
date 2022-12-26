#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef int RcdType;
typedef struct BBSTNode {
	RcdType data;
	int height;		//���߶ȣ����ڼ���ƽ������
	struct BBSTNode* lchild, * rchild;
}BBSTNode, * BBSTree;

//
void GeneralCheck(int& value, int range);
//
BBSTree newNode(RcdType value);
void DestroyBBSTree(BBSTree& root);
Status BBSTreeDepth(BBSTree T);
void CountLeaf(BBSTree T, RcdType& count);
BBSTree SearchAVL(BBSTree root, ElemType target);
Status ChangeNode(BBSTree& root, ElemType value1, ElemType value2);
BBSTree DeleteNode(BBSTree& root, RcdType value);
Status InsertNode(BBSTree& root, RcdType value);
BBSTree CreateAVL(ElemType* data, int n);
void LayerOrder(BBSTree root);
Status CopyBBSTree(BBSTree T, BBSTree& newT);
Status MergeBBSTree(BBSTree& T1, BBSTree& T2);
BBSTree SplitBBSTree(BBSTree& T, ElemType value);
void printTree(BBSTNode* treePtr);
int numcheck(void);

void newtreeui(BBSTree& T)
{
    int arr[30] = { 0 };
    int cycle = 0;
    system("cls");
    printf("+----------------------------------------+\n|            ");
    printf("\033[32m��ǰ����Ϊ���½���\033[0m          |\n");
    printf("+----------------------------------------+\n");
    printf("���֧��30��Ԫ�ص�ƽ�������\n");
    printf("�����������Ľ����:");
    GeneralCheck(cycle, 30);
    for (int i = 0; i < cycle; i++)
    {
        system("cls");
        printf("\033[32m------��%d�����뿪ʼ------\033[0m\n������:", i + 1);
        arr[i] = numcheck();
    }
    T = CreateAVL(arr, 30);
    system("cls");
    printf("\033[32m¼����ɣ�������������ϼ��˵�\033[0m\n");
    system("pause");
}

void searchui(BBSTree T1,BBSTree T2)
{
    int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ������\033[0m\n");
    if (T2 == NULL)
    {
        printf("��ǰ���Ҷ���Ϊ");
        printf("\033[32mTree1\033[0m\n");
        printf("������Ҫ���ҵ�����:");
        num = numcheck();
        if (SearchAVL(T1, num))
        {
            printf("��ǰ������ƽ�������T1��\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
        }
        else
        {
            printf("��ǰ���ݲ���ƽ�������T1��\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
        }
    }

}


void printOrder(BBSTNode* T, int* row)
{
    if (T != NULL)
    {
        (*row)++;
        printOrder(T->rchild, row);
        int i;
        for (i = 0; i < (*row); i++)
            printf("\t");
        printf("%d\n", T->data);
        printOrder(T->lchild, row);
        (*row)--;
    }
}

void printTree(BBSTNode* treePtr)
{
    int row = 0;
    printOrder(treePtr, &row);
}


void mainui()
{
    int choose = 0;
    BBSTree T1 = NULL;
    BBSTree T2 = NULL;
    TAG:system("cls");
    printf("+----------------------------------------+\n");
    printf("|           ƽ��������Ĳ�����ʾ         |\n");
    printf("+----------------------------------------+\n");
    if (T1 == NULL)
    {
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("1.�½��� 2.�˳�\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        switch (choose)
        {
            case 1:newtreeui(T1);
            break;
            case 2:goto TAG2;
            break;
        }
        goto TAG;
    }
    if (T1 != NULL)
    {
        printf("Tree1\n");
        printf("------------------------------------------\n");
        printTree(T1);
        printf("------------------------------------------\n");
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("1.���� 2.���� 3.ɾ�� 4.�޸� 5.���� 6.�˳�\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 6);
        switch (choose)
        {
        case 1:searchui(T1, T2);
            break;
        case 6:goto TAG2;
            break;
        }
        goto TAG;
    }
    if (T1 != NULL && T2 != NULL)
    {
        printf("��ǰ����ִ�еĲ���:1.���� 2.���� 3.ɾ�� 4.�޸� 5.�ϲ� 6.�˳�\n");
    }

    TAG2:return;
}

