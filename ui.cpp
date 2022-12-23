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
	int height;		//结点高度，用于计算平衡因子
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
    printf("\033[32m当前操作为：新建树\033[0m          |\n");
    printf("+----------------------------------------+\n");
    printf("最大支持30个元素的平衡二叉树\n");
    printf("请输入新树的结点数:");
    GeneralCheck(cycle, 30);
    for (int i = 0; i < cycle; i++)
    {
        system("cls");
        printf("\033[32m------第%d次输入开始------\033[0m\n请输入:", i + 1);
        arr[i] = numcheck();
    }
    T = CreateAVL(arr, 30);
    system("cls");
    printf("\033[32m录入完成，按任意键返回上级菜单\033[0m\n");
    system("pause");
}

void searchui(BBSTree T1,BBSTree T2)
{
    int num = 0;
    system("cls");
    printf("\033[32m当前操作为：查找\033[0m\n");
    if (T2 == NULL)
    {
        printf("当前查找对象为");
        printf("\033[32mTree1\033[0m\n");
        printf("请输入要查找的数据:");
        num = numcheck();
        if (SearchAVL(T1, num))
        {
            printf("当前数据在平衡二叉树T1中\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
            system("pause");
        }
        else
        {
            printf("当前数据不在平衡二叉树T1中\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
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
    printf("|           平衡二叉树的操作演示         |\n");
    printf("+----------------------------------------+\n");
    if (T1 == NULL)
    {
        printf("\033[32m当前可以执行的操作:\033[0m");
        printf("1.新建树 2.退出\n");
        printf("请选择:");
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
        printf("\033[32m当前可以执行的操作:\033[0m");
        printf("1.查找 2.插入 3.删除 4.修改 5.分裂 6.退出\n");
        printf("请选择:");
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
        printf("当前可以执行的操作:1.查找 2.插入 3.删除 4.修改 5.合并 6.退出\n");
    }

    TAG2:return;
}

