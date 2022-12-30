#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "general.h"
using namespace std;

Status max(int value1, int value2)
{
	return value1 > value2 ? value1 : value2;
}

Status getHeight(BBSTree root)		//��õ�ǰ���߶�
{
	if (root == NULL)
		return 0;
	return root->height;
}

Status getBalanceFactor(BBSTree root)		//����ƽ������
{
	if (root == NULL)
		return 0;
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(BBSTree& root)		//���½��߶�
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L_Rotate(BBSTree& root)
{
	BBSTree rc = root->rchild;	//rcָ��root�����Һ���
	root->rchild = rc->lchild;	//��rc����������Ϊroot��������
	rc->lchild = root;			//��root(ԭ�ȵĸ��ڵ�)��Ϊrc��������
	updateHeight(root);
	updateHeight(rc);
	root = rc;					//rootָ���µĸ��ڵ�rc
}

void R_Rotate(BBSTree& root)
{
	BBSTree lc = root->lchild;	//lcָ��root��������
	root->lchild = lc->rchild;	//��lc����������Ϊroot��������
	lc->rchild = root;			//��root(ԭ�ȵĸ��ڵ�)��Ϊlc��������
	updateHeight(root);
	updateHeight(lc);
	root = lc;					//rootָ���µĸ��ڵ�lc
}

Status L_Check(BBSTree& root)
{
	if (getBalanceFactor(root) == 2)
	{
		if (getBalanceFactor(root->lchild) == 1)		//LL��
		{
			R_Rotate(root);
		}
		if (getBalanceFactor(root->lchild) == -1)		//LR��
		{
			L_Rotate(root->lchild);
			R_Rotate(root);
		}
	}
	return TRUE;
}

Status R_Check(BBSTree& root)
{
	if (getBalanceFactor(root) == -2)
	{
		if (getBalanceFactor(root->rchild) == -1)		//RR��
		{
			L_Rotate(root);
		}
		if (getBalanceFactor(root->rchild) == 1)		//RL��
		{
			R_Rotate(root->rchild);
			L_Rotate(root);
		}
	}
	return TRUE;
}

void HeightReset_L(BBSTree& T)
{
	if (T == NULL)return;
	T->height = 1;
	HeightReset_L(T->lchild);
	updateHeight(T);
}

void HeightReset_R(BBSTree& T)
{
	if (T == NULL)return;
	T->height = 1;
	HeightReset_R(T->rchild);
	updateHeight(T);
}

BBSTree minValueNode(BBSTree node)
{
	BBSTree min = node;
	while (min->lchild != NULL)
	{
		min = min->lchild;
	}
	return min;
}