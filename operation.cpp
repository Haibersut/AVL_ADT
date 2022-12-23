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

//balancecheck函数声明
Status max(int value1, int value2);
Status getHeight(BBSTree root);
Status getBalanceFactor(BBSTree root);
void updateHeight(BBSTree& root);
void L_Rotate(BBSTree& root);
void R_Rotate(BBSTree& root);
Status L_Check(BBSTree& root);
Status R_Check(BBSTree& root);
void HeightReset_L(BBSTree& T);
void HeightReset_R(BBSTree& T);
BBSTree minValueNode(BBSTree node);

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
	if ((T->rchild == NULL) && (T->rchild == NULL))
	{
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
	if (value < root->data)		//插入的值比结点值小
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

BBSTree CreateAVL(ElemType* data, int n)
{
	BBSTree root = NULL;
	for (int i = 0; i < n; i++)
	{
		if (data[i] != 0)
		{
			InsertNode(root, data[i]);
		}
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
		cout << now->data;
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
	free(T2);
	return TRUE;
}

BBSTree SplitBBSTree(BBSTree& T, ElemType value)
{
	BBSTree p = SearchAVL(T, value);
	BBSTree newTree = NULL;
	CopyBBSTree(p, newTree);
	queue<BBSTree>q;
	q.push(newTree);
	while (!q.empty())
	{
		BBSTree now = q.front();
		q.pop();
		DeleteNode(T, now->data);
		if (now->lchild != NULL)
		{
			q.push(now->lchild);
		}
		if (now->rchild != NULL)
		{
			q.push(now->rchild);
		}
	}
	HeightReset_L(T);
	HeightReset_R(T);
	L_Check(T);
	R_Check(T);
	HeightReset_L(newTree);
	HeightReset_R(newTree);
	return newTree;
}