#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <iostream>
#include "general.h"
#include "queue.h"
#include "balancecheck.h"
using namespace std;


BBSTree newNode(RcdType value)
{
	BBSTree Node = new BBSTNode();
	if (Node == NULL)
		return NULL;
	Node->data = value;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

void DestroyBBSTree(BBSTree& root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		DestroyBBSTree(root->lchild);
		DestroyBBSTree(root->rchild);
		free(root);
	}
}

Status visit(int i)
{
	if (i == 0)
		printf("#");
	else
		printf("%d ", i);
	return OK;
}

Status visit2(int i)
{
	return i;
}

Status PreOrderTraverse(BBSTree T, Status(*visit)(ElemType e))
{		//先序遍历二叉树T, visit是对数据元素操作的应用函数
	if (T == NULL) return OK;
	if (visit(T->data) == ERROR)
		return ERROR;							//(1)访问结点的数据域
	if (PreOrderTraverse(T->lchild, visit) == ERROR)
		return ERROR;							//(2)递归遍历T的左子树
	return PreOrderTraverse(T->rchild, visit);	//(3)递归遍历T的右子树
}

Status InOrderTraverse(BBSTree T, Status(*visit)(ElemType e))
{		//中序遍历二叉树T, visit是对数据元素操作的应用函数
	if (T == NULL) return OK;
	if (InOrderTraverse(T->lchild, visit) == ERROR)
		return ERROR;							//(1)递归遍历T的左子树
	if (visit(T->data) == ERROR)
		return ERROR;							//(2)访问结点的数据域
	return InOrderTraverse(T->rchild, visit);	//(3)递归遍历T的右子树
}

Status PostOrderTraverse(BBSTree T, Status(*visit)(ElemType e))
{		//中序遍历二叉树T, visit是对数据元素操作的应用函数
	if (T == NULL) return OK;
	if (PostOrderTraverse(T->lchild, visit) == ERROR)
		return ERROR;							//(1)递归遍历T的左子树
	if (PostOrderTraverse(T->rchild, visit) == ERROR)
		return ERROR;							//(2)递归遍历T的右子树
	return visit(T->data);	                    //(3)访问结点的数据域
}

Status BBSTreeDepth(BBSTree T)
{
	int depthLeft = 0;
	int depthRight = 0;
	if (T == NULL)
	{
		return 0;	//空二叉树深度为0
	}
	else
	{
		depthLeft = BBSTreeDepth(T->lchild);
		depthRight = BBSTreeDepth(T->rchild);
		return (depthLeft > depthRight ? depthLeft : depthRight) + 1;	//左右子树深度的较大值+1
	}
}

void CountLeaf(BBSTree T, RcdType& count)		//用递归方法计算叶子结点个数
{
	if (T != NULL)
	{
		if ((T->lchild == NULL) && (T->rchild == NULL))
			count++;
		CountLeaf(T->lchild, count);
		CountLeaf(T->rchild, count);
	}
}

BBSTree SearchAVL(BBSTree root, ElemType target)
{
	if (root == NULL)
		return NULL;
	if (target == root->data)
	{
		return root;
	}
	if (target < root->data)
	{
		return SearchAVL(root->lchild, target);
	}
	return SearchAVL(root->rchild, target);
}

Status ChangeNode(BBSTree& root, ElemType value1, ElemType value2)
{
	BBSTree temp = NULL;
	temp = SearchAVL(root, value1);
	if (temp == NULL)
		return FALSE;
	else
	{
		temp->data = value2;
		return TRUE;
	}
}

BBSTree DeleteNode(BBSTree& root, RcdType value)
{
	if (root == NULL)
		return root;
	if (root->data > value)
		DeleteNode(root->lchild, value);
	else if (root->data < value)
		DeleteNode(root->rchild, value);
	else
	{
		if ((root->lchild == NULL) || (root->rchild == NULL))
		{
			BBSTree temp = root->lchild ? root->lchild : root->rchild;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				root = temp;
				temp = NULL;
			}
		}
		else
		{
			BBSTree temp = minValueNode(root->rchild);
			root->data = temp->data;
			DeleteNode(root->rchild, temp->data);
		}
	}
	if (root == NULL)
		return root;
	updateHeight(root);
	L_Check(root);
	R_Check(root);
	return root;
}

Status InsertNode(BBSTree& root, RcdType value)
{
	if (root == NULL)
	{
		root = newNode(value);
		if (root != NULL)
		{
			return TRUE;
		}
		return FALSE;
	}
	if (value < root->data)					//插入的值比结点值小
	{
		InsertNode(root->lchild, value);
		updateHeight(root);
		L_Check(root);
		return TRUE;
	}
	else if(value > root->data)				//插入的值比结点值大
	{
		InsertNode(root->rchild, value);
		updateHeight(root);
		R_Check(root);
		return TRUE;
	}
}

BBSTree CreateAVL(LQueue &Q)
{
	BBSTree root = NULL;
	int data = 0;
	while (!QueueEmpty_LQ(Q))
	{
		DeQueue_LQ(Q, data);
		InsertNode(root, data);
	}
	return root;
}

void LayerOrder(BBSTree root)
{
	queue<BBSTNode*>q;
	q.push(root);
	while (!q.empty())
	{
		BBSTree now = q.front();
		q.pop();
		printf("%d ", now->data);
		if (now->lchild != NULL)
		{
			q.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			q.push(now->rchild);
		}
	}
}


Status CopyBBSTree(BBSTree T, BBSTree& newT)
{
	if (T == NULL)
	{
		newT = NULL;
		return TRUE;
	}
	else
	{
		newT = new BBSTNode();
		newT->data = T->data;
		newT->height = 1;
		newT->lchild = newT->rchild = NULL;
		CopyBBSTree(T->lchild, newT->lchild);
		CopyBBSTree(T->rchild, newT->rchild);
	}
	return TRUE;
}

Status MergeBBSTree(BBSTree& T1, BBSTree& T2)
{
	queue<BBSTree>q;
	q.push(T2);
	while (!q.empty())
	{
		BBSTree temp = q.front();
		q.pop();
		InsertNode(T1, temp->data);
		if (temp->lchild != NULL)
		{
			q.push(temp->lchild);
		}
		if (temp->rchild != NULL)
		{
			q.push(temp->rchild);
		}
	}
	BBSTree temp2 = T2;
	T2 = NULL;
	free(temp2);
	return TRUE;
}

BBSTree SplitBBSTree(BBSTree& T, ElemType value)
{
	BBSTree p = T;
	BBSTree newTree = NULL;
	queue<BBSTNode*>q1;
	queue<RcdType>q2;
	q1.push(p);
	while (!q1.empty())
	{
		BBSTree now = q1.front();
		q1.pop();
		q2.push(now->data);
		if (now->lchild != NULL)
		{
			q1.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			q1.push(now->rchild);
		}
	}
	while (!q2.empty())
	{
		RcdType temp = q2.front();
		q2.pop();
		if (temp <= value)
		{
			InsertNode(newTree, temp);
			DeleteNode(T, temp);
		}
	}
	/*HeightReset_L(T);
	HeightReset_R(T);
	L_Check(T);
	R_Check(T);*/
	return newTree;
}

//BBSTree SplitBBSTree1(BBSTree& T, ElemType value)
//{
//	BBSTree p = SearchAVL(T, value);
//	BBSTree newTree = NULL;
//	CopyBBSTree(p, newTree);
//	queue<BBSTree>q;
//	q.push(newTree);
//	while (!q.empty())
//	{
//		BBSTree now = q.front();
//		q.pop();
//		DeleteNode(T, now->data);
//		if (now->lchild != NULL)
//		{
//			q.push(now->lchild);
//		}
//		if (now->rchild != NULL)
//		{
//			q.push(now->rchild);
//		}
//	}
//	HeightReset_L(T);
//	HeightReset_R(T);
//	L_Check(T);
//	R_Check(T);
//	HeightReset_L(newTree);
//	HeightReset_R(newTree);
//	return newTree;
//}