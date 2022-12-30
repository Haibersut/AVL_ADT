#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "operation.h"
#include "numcheck.h"
#include "queue.h"

void printOrder(BBSTNode* T, int* row)
{
    if (T != NULL)
    {
        (*row)++;
        printOrder(T->rchild, row);
        for (int i = 0; i < (*row); i++)
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

void traversalui(BBSTree T1, BBSTree T2)
{
    TAG10:system("cls");
    printf("\033[32m当前操作为：遍历\033[0m\n");
    if (T1 != NULL && T2 == NULL)
    {
        int choose = 0;
        printf("请选择遍历对象或者返回:1.Tree1 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前遍历对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("先序遍历:");
            PreOrderTraverse(T1, visit);
            printf("\n");
            printf("中序遍历:");
            InOrderTraverse(T1, visit);
            printf("\n");
            printf("后序遍历:");
            PostOrderTraverse(T1, visit);
            printf("\n");
            printf("层次遍历:");
            LayerOrder(T1);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n遍历完成\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
            system("pause");
            goto TAG10;  //返回修改界面
    
        }
        else
        {
            return;
        }
    }
    else if (T1 == NULL && T2 != NULL)
    {
        int choose = 0;
        printf("请选择遍历对象或者返回:1.Tree2 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前遍历对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("先序遍历:");
            PreOrderTraverse(T2, visit);
            printf("\n");
            printf("中序遍历:");
            InOrderTraverse(T2, visit);
            printf("\n");
            printf("后序遍历:");
            PostOrderTraverse(T2, visit);
            printf("\n");
            printf("层次遍历:");
            LayerOrder(T2);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n遍历完成\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
            system("pause");
            goto TAG10;  //返回修改界面
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("请选择遍历对象或者返回:1.Tree1 2.Tree2 3.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n当前遍历对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("先序遍历:");
            PreOrderTraverse(T1, visit);
            printf("\n");
            printf("中序遍历:");
            InOrderTraverse(T1, visit);
            printf("\n");
            printf("后序遍历:");
            PostOrderTraverse(T1, visit);
            printf("\n");
            printf("层次遍历:");
            LayerOrder(T1);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n遍历完成\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
            system("pause");
            goto TAG10;  //返回修改界面
        }
        else if (choose == 2)
        {
            printf("\n当前遍历对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("先序遍历:");
            PreOrderTraverse(T2, visit);
            printf("\n");
            printf("中序遍历:");
            InOrderTraverse(T2, visit);
            printf("\n");
            printf("后序遍历:");
            PostOrderTraverse(T2, visit);
            printf("\n");
            printf("层次遍历:");
            LayerOrder(T2);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n遍历完成\n");
            printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
            system("pause");
            goto TAG10;  //返回修改界面
        }
        return; //返回
    }
}

void newtreeui(BBSTree& T)
{
    int arr[30] = { 0 };
    int cycle = 0;
    LQueue Q;
    InitQueue_LQ(Q);
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
        EnQueue_LQ(Q, numcheck());
    }
    T = CreateAVL(Q);
    system("cls");
    printf("\033[32m录入完成，按任意键返回上级菜单\033[0m\n");
    system("pause");
}

void mergeui(BBSTree& T1, BBSTree& T2)
{
    int num = 0;
    system("cls");
    printf("\033[32m当前操作为：合并\033[0m\n");
    int choose = 0;
    printf("请选择合并对象或者返回:1.Tree1<-Tree2 2.返回\n");
    printf("请选择:");
    GeneralCheck(choose, 2);
    if (choose == 1)
    {
        printf("\n当前合并对象为");
        printf("\033[32mTree1<-Tree2\033[0m\n");
        MergeBBSTree(T1, T2);
        printf("已将平衡二叉树T2合并至平衡二叉树T1中\n");
        printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
        system("pause");
    }
    return; //返回
}

void splitui(BBSTree& T1, BBSTree& T2)
{
    TAG8:int num = 0;
    system("cls");
    printf("\033[32m当前操作为：分裂\033[0m\n");
    int choose = 0;
    printf("请选择分裂对象或者返回:1.Tree1 2.返回\n");
    printf("请选择:");
    GeneralCheck(choose, 2);
    if (choose == 1)
    {
       printf("\n当前分裂对象为");
       printf("\033[32mTree1\033[0m\n");
       printf("请输入要分裂的结点数据:");
       num = numcheck();
       BBSTree p = T1;
       if (SearchAVL(p, num))
       {
           T2 = SplitBBSTree(T1, num);
           printf("已将该结点以及其子树从平衡二叉树T1中分裂\n");
           printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
           system("pause");
       }
       else
       {
           printf("\n\033[31m错误:当前数据不在平衡二叉树T1中\033[0m\a\n");
           printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
           system("pause");
           goto TAG8;  //返回分裂界面
       }
    }
    return; //返回
}


void changeui(BBSTree& T1, BBSTree& T2)
{
    TAG7:int num1 = 0;
    system("cls");
    printf("\033[32m当前操作为：修改\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("请选择修改对象或者返回:1.Tree1 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前修改对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要修改的数据:");
            num1 = numcheck();
            if (SearchAVL(T1, num1))
            {
                int num2 = 0;
                printf("请输入新的数据:");
                num2 = numcheck();
                ChangeNode(T1, num1, num2);
                printf("已将该数据从平衡二叉树T1中修改\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7;  //返回修改界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7;  //返回修改界面
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("请选择修改对象或者返回:1.Tree1 2.Tree2 3.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n当前修改对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要修改的数据:");
            num1 = numcheck();
            if (SearchAVL(T1, num1))
            {
                int num2 = 0;
                printf("请输入新的数据:");
                num2 = numcheck();
                ChangeNode(T1, num1, num2);
                printf("已将该数据从平衡二叉树T1中修改\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7;  //返回查找界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7;  //返回查找界面
            }
        }
        else if (choose == 2)
        {
            printf("\n当前修改对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("请输入要修改的数据:");
            num1 = numcheck();
            if (SearchAVL(T2, num1))
            {
                int num2 = 0;
                printf("请输入新的数据:");
                num2 = numcheck();
                ChangeNode(T2, num1, num2);
                printf("已将该数据从平衡二叉树T2中修改\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7;  //返回查找界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T2中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG7; //返回查找界面
            }
        }
        return; //返回
    }
}



void deleteui(BBSTree& T1, BBSTree& T2)
{
    TAG6:int num = 0;
    system("cls");
    printf("\033[32m当前操作为：删除\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("请选择删除对象或者返回:1.Tree1 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前删除对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要删除的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                DeleteNode(T1, num);
                printf("已将该数据从平衡二叉树T1中删除\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6;  //返回查找界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6;  //返回查找界面
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("请选择删除对象或者返回:1.Tree1 2.Tree2 3.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n当前删除对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要删除的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                DeleteNode(T1, num);
                printf("已将该数据从平衡二叉树T1中删除\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6;  //返回删除界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6;  //返回删除界面
            }
        }
        else if (choose == 2)
        {
            printf("\n当前删除对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("请输入要删除的数据:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                DeleteNode(T2, num);
                printf("已将该数据从平衡二叉树T2中删除\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6; //返回删除界面
            }
            else
            {
                printf("\n\033[31m错误:当前数据不在平衡二叉树T2中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG6; //返回删除界面
            }
        }
        return; //返回
    }
}


void insertui(BBSTree &T1, BBSTree &T2)
{
    TAG5:int num = 0;
    system("cls");
    printf("\033[32m当前操作为：插入\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("请选择插入对象或者返回:1.Tree1 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前插入对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要插入的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("\n\033[31m错误:当前数据在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5;  //返回插入界面
            }
            else
            {
                InsertNode(T1, num);
                printf("已将该数据插入平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5;  //返回插入界面
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("请选择插入对象或者返回:1.Tree1 2.Tree2 3.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n当前插入对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要插入的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("\n\033[31m错误:当前数据在平衡二叉树T1中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5;  //返回插入界面
            }
            else
            {
                InsertNode(T1, num);
                printf("已将该数据插入平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5;  //返回插入界面
            }
        }
        else if (choose == 2)
        {
            printf("\n当前插入对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("请输入要插入的数据:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                printf("\n\033[31m错误:当前数据在平衡二叉树T2中\033[0m\a\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5; //返回插入界面
            }
            else
            {
                InsertNode(T2, num);
                printf("已将该数据插入平衡二叉树T2中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG5; //返回插入界面
            }
        }
        return; //返回
    }
}

void searchui(BBSTree T1,BBSTree T2)
{
    TAG4:int num = 0;
    system("cls");
    printf("\033[32m当前操作为：查找\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("请选择查找对象或者返回:1.Tree1 2.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n当前查找对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要查找的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("当前数据在平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG4;  //返回查找界面
            }
            else
            {
                printf("当前数据不在平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG4;
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("请选择查找对象或者返回:1.Tree1 2.Tree2 3.返回\n");
        printf("请选择:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n当前查找对象为");
            printf("\033[32mTree1\033[0m\n");
            printf("请输入要查找的数据:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("当前数据在平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG4;  //返回查找界面
            }
            else
            {
                printf("当前数据不在平衡二叉树T1中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                goto TAG4;
            }
        }
        else if (choose == 2)
        {
            printf("\n当前查找对象为");
            printf("\033[32mTree2\033[0m\n");
            printf("请输入要查找的数据:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                printf("当前数据在平衡二叉树T2中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                return;
            }
            else
            {
                printf("当前数据不在平衡二叉树T2中\n");
                printf("\n\033[32m按任意键返回上级菜单\033[0m\n");
                system("pause");
                return;
            }
        }
        return;
    }
}

void mainui()
{
    int choose = 0;
    BBSTree T1 = NULL;
    BBSTree T2 = NULL;
    TAG:system("cls");
    printf("+----------------------------------------+\n");
    printf("|           平衡二叉树的操作演示         |\n");
    printf("|              21计科2 贺畅              |\n");
    printf("+----------------------------------------+\n");
    if (T1 != NULL && T2 == NULL)
    {
        int leaf = 0;
        printf("|                  Tree1                 |\n");
        printf("------------------------------------------\n");
        printf("该树的深度为:%d\n", BBSTreeDepth(T1));
        CountLeaf(T1, leaf);
        printf("该树的叶子数为:%d\n\n", leaf);
        printTree(T1);
        printf("------------------------------------------\n");
        printf("\033[32m当前可以执行的操作:\033[0m");
        printf("1.查找 2.插入 3.删除 4.修改 5.分裂 6.遍历 7.退出\n");
        printf("请选择:");
        GeneralCheck(choose, 7);
        switch (choose)
        {
        case 1:searchui(T1, T2);
            break;
        case 2:insertui(T1, T2);
            break;
        case 3:deleteui(T1, T2);
            break;
        case 4:changeui(T1, T2);
            break;
        case 5:splitui(T1, T2);
            break;
        case 6:traversalui(T1, T2);
            break;
        case 7:goto TAG2;
        }
        goto TAG;
    }
    if (T1 == NULL && T2 != NULL)
    {
        int leaf = 0;
        printf("|                  Tree2                 |\n");
        printf("------------------------------------------\n");
        printf("该树的深度为:%d\n", BBSTreeDepth(T2));
        CountLeaf(T2, leaf);
        printf("该树的叶子数为:%d\n\n", leaf);
        printTree(T2);
        printf("------------------------------------------\n");
        printf("\033[32m当前可以执行的操作:\033[0m");
        printf("1.查找 2.插入 3.删除 4.修改 5.合并 6.遍历 7.退出\n");
        printf("请选择:");
        GeneralCheck(choose, 7);
        switch (choose)
        {
        case 1:searchui(T1, T2);
            break;
        case 2:insertui(T1, T2);
            break;
        case 3:deleteui(T1, T2);
            break;
        case 4:changeui(T1, T2);
            break;
        case 5:mergeui(T1, T2);
            break;
        case 6:traversalui(T1, T2);
            break;
        case 7:goto TAG2;
        }
        goto TAG;
    }
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
        }
        goto TAG;
    }
    if (T1 != NULL && T2 != NULL)
    {
        int leaf1 = 0;
        int leaf2 = 0;
        printf("|                  Tree1                 |\n");
        printf("------------------------------------------\n");
        printf("该树的深度为:%d\n", BBSTreeDepth(T1));
        CountLeaf(T1, leaf1);
        printf("该树的叶子数为:%d\n\n", leaf1);
        printTree(T1);
        printf("------------------------------------------\n");
        printf("|                  Tree2                 |\n");
        printf("------------------------------------------\n");
        printf("该树的深度为:%d\n", BBSTreeDepth(T2));
        CountLeaf(T2, leaf2);
        printf("该树的叶子数为:%d\n\n", leaf2);
        printTree(T2);
        printf("------------------------------------------\n");
        printf("\033[32m当前可以执行的操作:\033[0m");
        printf("当前可以执行的操作:1.查找 2.插入 3.删除 4.修改 5.合并 6.遍历 7.退出\n");
        printf("请选择:");
        GeneralCheck(choose, 7);
        switch (choose)
        {
        case 1:searchui(T1, T2);
            break;
        case 2:insertui(T1, T2);
            break;
        case 3:deleteui(T1, T2);
            break;
        case 4:changeui(T1, T2);
            break;
        case 5:mergeui(T1, T2);
            break;
        case 6:traversalui(T1, T2);
            break;
        case 7:goto TAG2;
        }
        goto TAG;
    }

    TAG2:return;
}

