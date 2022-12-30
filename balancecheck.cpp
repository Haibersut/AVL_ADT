#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "general.h"
using namespace std;

Status max(int value1, int value2)
{
	return value1 > value2 ? value1 : value2;
}

Status getHeight(BBSTree root)		//获得当前结点高度
{
	if (root == NULL)
		return 0;
	return root->height;
}

Status getBalanceFactor(BBSTree root)		//计算平衡因子
{
	if (root == NULL)
		return 0;
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(BBSTree& root)		//更新结点高度
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L_Rotate(BBSTree& root)
{
	BBSTree rc = root->rchild;	//rc指向root结点的右孩子
	root->rchild = rc->lchild;	//将rc的左子树设为root的右子树
	rc->lchild = root;			//将root(原先的根节点)设为rc的左子树
	updateHeight(root);
	updateHeight(rc);
	root = rc;					//root指向新的根节点rc
}

void R_Rotate(BBSTree& root)
{
	BBSTree lc = root->lchild;	//lc指向root结点的左孩子
	root->lchild = lc->rchild;	//将lc的右子树设为root的左子树
	lc->rchild = root;			//将root(原先的根节点)设为lc的右子树
	updateHeight(root);
	updateHeight(lc);
	root = lc;					//root指向新的根节点lc
}

Status L_Check(BBSTree& root)
{
	if (getBalanceFactor(root) == 2)
	{
		if (getBalanceFactor(root->lchild) == 1)		//LL型
		{
			R_Rotate(root);
		}
		if (getBalanceFactor(root->lchild) == -1)		//LR型
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
		if (getBalanceFactor(root->rchild) == -1)		//RR型
		{
			L_Rotate(root);
		}
		if (getBalanceFactor(root->rchild) == 1)		//RL型
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