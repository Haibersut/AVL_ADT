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
    printf("\033[32m��ǰ����Ϊ������\033[0m\n");
    if (T1 != NULL && T2 == NULL)
    {
        int choose = 0;
        printf("��ѡ�����������߷���:1.Tree1 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰ��������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("�������:");
            PreOrderTraverse(T1, visit);
            printf("\n");
            printf("�������:");
            InOrderTraverse(T1, visit);
            printf("\n");
            printf("�������:");
            PostOrderTraverse(T1, visit);
            printf("\n");
            printf("��α���:");
            LayerOrder(T1);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n�������\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
            goto TAG10;  //�����޸Ľ���
    
        }
        else
        {
            return;
        }
    }
    else if (T1 == NULL && T2 != NULL)
    {
        int choose = 0;
        printf("��ѡ�����������߷���:1.Tree2 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰ��������Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("�������:");
            PreOrderTraverse(T2, visit);
            printf("\n");
            printf("�������:");
            InOrderTraverse(T2, visit);
            printf("\n");
            printf("�������:");
            PostOrderTraverse(T2, visit);
            printf("\n");
            printf("��α���:");
            LayerOrder(T2);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n�������\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
            goto TAG10;  //�����޸Ľ���
        }
        else
        {
            return;
        }
    }
    else
    {
        int choose = 0;
        printf("��ѡ�����������߷���:1.Tree1 2.Tree2 3.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n��ǰ��������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("�������:");
            PreOrderTraverse(T1, visit);
            printf("\n");
            printf("�������:");
            InOrderTraverse(T1, visit);
            printf("\n");
            printf("�������:");
            PostOrderTraverse(T1, visit);
            printf("\n");
            printf("��α���:");
            LayerOrder(T1);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n�������\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
            goto TAG10;  //�����޸Ľ���
        }
        else if (choose == 2)
        {
            printf("\n��ǰ��������Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("+----------------------------------------+\n");
            printf("�������:");
            PreOrderTraverse(T2, visit);
            printf("\n");
            printf("�������:");
            InOrderTraverse(T2, visit);
            printf("\n");
            printf("�������:");
            PostOrderTraverse(T2, visit);
            printf("\n");
            printf("��α���:");
            LayerOrder(T2);
            printf("\n");
            printf("+----------------------------------------+\n");
            printf("\n�������\n");
            printf("\n\033[32m������������ϼ��˵�\033[0m\n");
            system("pause");
            goto TAG10;  //�����޸Ľ���
        }
        return; //����
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
    printf("\033[32m��ǰ����Ϊ���½���\033[0m          |\n");
    printf("+----------------------------------------+\n");
    printf("���֧��30��Ԫ�ص�ƽ�������\n");
    printf("�����������Ľ����:");
    GeneralCheck(cycle, 30);
    for (int i = 0; i < cycle; i++)
    {
        system("cls");
        printf("\033[32m------��%d�����뿪ʼ------\033[0m\n������:", i + 1);
        EnQueue_LQ(Q, numcheck());
    }
    T = CreateAVL(Q);
    system("cls");
    printf("\033[32m¼����ɣ�������������ϼ��˵�\033[0m\n");
    system("pause");
}

void mergeui(BBSTree& T1, BBSTree& T2)
{
    int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ���ϲ�\033[0m\n");
    int choose = 0;
    printf("��ѡ��ϲ�������߷���:1.Tree1<-Tree2 2.����\n");
    printf("��ѡ��:");
    GeneralCheck(choose, 2);
    if (choose == 1)
    {
        printf("\n��ǰ�ϲ�����Ϊ");
        printf("\033[32mTree1<-Tree2\033[0m\n");
        MergeBBSTree(T1, T2);
        printf("�ѽ�ƽ�������T2�ϲ���ƽ�������T1��\n");
        printf("\n\033[32m������������ϼ��˵�\033[0m\n");
        system("pause");
    }
    return; //����
}

void splitui(BBSTree& T1, BBSTree& T2)
{
    TAG8:int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ������\033[0m\n");
    int choose = 0;
    printf("��ѡ����Ѷ�����߷���:1.Tree1 2.����\n");
    printf("��ѡ��:");
    GeneralCheck(choose, 2);
    if (choose == 1)
    {
       printf("\n��ǰ���Ѷ���Ϊ");
       printf("\033[32mTree1\033[0m\n");
       printf("������Ҫ���ѵĽ������:");
       num = numcheck();
       BBSTree p = T1;
       if (SearchAVL(p, num))
       {
           T2 = SplitBBSTree(T1, num);
           printf("�ѽ��ý���Լ���������ƽ�������T1�з���\n");
           printf("\n\033[32m������������ϼ��˵�\033[0m\n");
           system("pause");
       }
       else
       {
           printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T1��\033[0m\a\n");
           printf("\n\033[32m������������ϼ��˵�\033[0m\n");
           system("pause");
           goto TAG8;  //���ط��ѽ���
       }
    }
    return; //����
}


void changeui(BBSTree& T1, BBSTree& T2)
{
    TAG7:int num1 = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ���޸�\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("��ѡ���޸Ķ�����߷���:1.Tree1 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰ�޸Ķ���Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ�޸ĵ�����:");
            num1 = numcheck();
            if (SearchAVL(T1, num1))
            {
                int num2 = 0;
                printf("�������µ�����:");
                num2 = numcheck();
                ChangeNode(T1, num1, num2);
                printf("�ѽ������ݴ�ƽ�������T1���޸�\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7;  //�����޸Ľ���
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7;  //�����޸Ľ���
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
        printf("��ѡ���޸Ķ�����߷���:1.Tree1 2.Tree2 3.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n��ǰ�޸Ķ���Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ�޸ĵ�����:");
            num1 = numcheck();
            if (SearchAVL(T1, num1))
            {
                int num2 = 0;
                printf("�������µ�����:");
                num2 = numcheck();
                ChangeNode(T1, num1, num2);
                printf("�ѽ������ݴ�ƽ�������T1���޸�\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7;  //���ز��ҽ���
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7;  //���ز��ҽ���
            }
        }
        else if (choose == 2)
        {
            printf("\n��ǰ�޸Ķ���Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("������Ҫ�޸ĵ�����:");
            num1 = numcheck();
            if (SearchAVL(T2, num1))
            {
                int num2 = 0;
                printf("�������µ�����:");
                num2 = numcheck();
                ChangeNode(T2, num1, num2);
                printf("�ѽ������ݴ�ƽ�������T2���޸�\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7;  //���ز��ҽ���
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T2��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG7; //���ز��ҽ���
            }
        }
        return; //����
    }
}



void deleteui(BBSTree& T1, BBSTree& T2)
{
    TAG6:int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ��ɾ��\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("��ѡ��ɾ��������߷���:1.Tree1 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰɾ������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫɾ��������:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                DeleteNode(T1, num);
                printf("�ѽ������ݴ�ƽ�������T1��ɾ��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6;  //���ز��ҽ���
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6;  //���ز��ҽ���
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
        printf("��ѡ��ɾ��������߷���:1.Tree1 2.Tree2 3.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n��ǰɾ������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫɾ��������:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                DeleteNode(T1, num);
                printf("�ѽ������ݴ�ƽ�������T1��ɾ��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6;  //����ɾ������
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6;  //����ɾ������
            }
        }
        else if (choose == 2)
        {
            printf("\n��ǰɾ������Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("������Ҫɾ��������:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                DeleteNode(T2, num);
                printf("�ѽ������ݴ�ƽ�������T2��ɾ��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6; //����ɾ������
            }
            else
            {
                printf("\n\033[31m����:��ǰ���ݲ���ƽ�������T2��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG6; //����ɾ������
            }
        }
        return; //����
    }
}


void insertui(BBSTree &T1, BBSTree &T2)
{
    TAG5:int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ������\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("��ѡ����������߷���:1.Tree1 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰ�������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ���������:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("\n\033[31m����:��ǰ������ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5;  //���ز������
            }
            else
            {
                InsertNode(T1, num);
                printf("�ѽ������ݲ���ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5;  //���ز������
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
        printf("��ѡ����������߷���:1.Tree1 2.Tree2 3.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n��ǰ�������Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ���������:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("\n\033[31m����:��ǰ������ƽ�������T1��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5;  //���ز������
            }
            else
            {
                InsertNode(T1, num);
                printf("�ѽ������ݲ���ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5;  //���ز������
            }
        }
        else if (choose == 2)
        {
            printf("\n��ǰ�������Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("������Ҫ���������:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                printf("\n\033[31m����:��ǰ������ƽ�������T2��\033[0m\a\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5; //���ز������
            }
            else
            {
                InsertNode(T2, num);
                printf("�ѽ������ݲ���ƽ�������T2��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG5; //���ز������
            }
        }
        return; //����
    }
}

void searchui(BBSTree T1,BBSTree T2)
{
    TAG4:int num = 0;
    system("cls");
    printf("\033[32m��ǰ����Ϊ������\033[0m\n");
    if (T2 == NULL)
    {
        int choose = 0;
        printf("��ѡ����Ҷ�����߷���:1.Tree1 2.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 2);
        if (choose == 1)
        {
            printf("\n��ǰ���Ҷ���Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ���ҵ�����:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("��ǰ������ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG4;  //���ز��ҽ���
            }
            else
            {
                printf("��ǰ���ݲ���ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
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
        printf("��ѡ����Ҷ�����߷���:1.Tree1 2.Tree2 3.����\n");
        printf("��ѡ��:");
        GeneralCheck(choose, 3);
        if (choose == 1)
        {
            printf("\n��ǰ���Ҷ���Ϊ");
            printf("\033[32mTree1\033[0m\n");
            printf("������Ҫ���ҵ�����:");
            num = numcheck();
            if (SearchAVL(T1, num))
            {
                printf("��ǰ������ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG4;  //���ز��ҽ���
            }
            else
            {
                printf("��ǰ���ݲ���ƽ�������T1��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                goto TAG4;
            }
        }
        else if (choose == 2)
        {
            printf("\n��ǰ���Ҷ���Ϊ");
            printf("\033[32mTree2\033[0m\n");
            printf("������Ҫ���ҵ�����:");
            num = numcheck();
            if (SearchAVL(T2, num))
            {
                printf("��ǰ������ƽ�������T2��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
                system("pause");
                return;
            }
            else
            {
                printf("��ǰ���ݲ���ƽ�������T2��\n");
                printf("\n\033[32m������������ϼ��˵�\033[0m\n");
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
    printf("|           ƽ��������Ĳ�����ʾ         |\n");
    printf("|              21�ƿ�2 �س�              |\n");
    printf("+----------------------------------------+\n");
    if (T1 != NULL && T2 == NULL)
    {
        int leaf = 0;
        printf("|                  Tree1                 |\n");
        printf("------------------------------------------\n");
        printf("���������Ϊ:%d\n", BBSTreeDepth(T1));
        CountLeaf(T1, leaf);
        printf("������Ҷ����Ϊ:%d\n\n", leaf);
        printTree(T1);
        printf("------------------------------------------\n");
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("1.���� 2.���� 3.ɾ�� 4.�޸� 5.���� 6.���� 7.�˳�\n");
        printf("��ѡ��:");
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
        printf("���������Ϊ:%d\n", BBSTreeDepth(T2));
        CountLeaf(T2, leaf);
        printf("������Ҷ����Ϊ:%d\n\n", leaf);
        printTree(T2);
        printf("------------------------------------------\n");
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("1.���� 2.���� 3.ɾ�� 4.�޸� 5.�ϲ� 6.���� 7.�˳�\n");
        printf("��ѡ��:");
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
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("1.�½��� 2.�˳�\n");
        printf("��ѡ��:");
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
        printf("���������Ϊ:%d\n", BBSTreeDepth(T1));
        CountLeaf(T1, leaf1);
        printf("������Ҷ����Ϊ:%d\n\n", leaf1);
        printTree(T1);
        printf("------------------------------------------\n");
        printf("|                  Tree2                 |\n");
        printf("------------------------------------------\n");
        printf("���������Ϊ:%d\n", BBSTreeDepth(T2));
        CountLeaf(T2, leaf2);
        printf("������Ҷ����Ϊ:%d\n\n", leaf2);
        printTree(T2);
        printf("------------------------------------------\n");
        printf("\033[32m��ǰ����ִ�еĲ���:\033[0m");
        printf("��ǰ����ִ�еĲ���:1.���� 2.���� 3.ɾ�� 4.�޸� 5.�ϲ� 6.���� 7.�˳�\n");
        printf("��ѡ��:");
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

