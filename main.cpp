#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef int RcdType;
typedef struct BBSTNode {
	RcdType data;
	int bf;			//平衡因子
	int height;		//结点高度，用于计算平衡因子
	struct BBSTNode* lchild, * rchild;
}*BBSTree;

BBSTree newAVLNode(RcdType value)
{
	BBSTree Node = new BBSTNode();
	if (Node == nullptr)
		return nullptr;
	Node->data = value;
	Node->bf = 0;
	Node->height = 1;
	Node->lchild = Node->rchild = nullptr;
	return Node;
}

Status DestroyAVL(BBSTree& root)
{
	return TRUE;
}

Status SizeAVL()
{
	return TRUE;
}

Status max(int value1, int value2)
{
	return value1 > value2 ? value1 : value2;
}

Status getHeight(BBSTree root)		//获得当前结点高度
{
	if (root == nullptr)
		return 0;
	return root->height;
}

Status getBalanceFactor(BBSTree &root)		//计算平衡因子
{
	root->bf = getHeight(root->lchild) - getHeight(root->rchild);
	return root->bf;
}

void updateHeight(BBSTree& root)		//更新结点高度
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

BBSTree SearchAVL(BBSTree root, ElemType target)
{
	if (root == nullptr)
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
	BBSTree lc = root->rchild;	//lc指向root结点的左孩子
	root->rchild = lc->lchild;	//将lc的右子树设为root的左子树
	lc->lchild = root;			//将root(原先的根节点)设为lc的右子树
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
Status InsertAVL(BBSTree& root, RcdType value)
{
	if (root == nullptr)
	{
		root = newAVLNode(value);
		if (root != nullptr)
		{
			return TRUE;
		}
		return FALSE;
	}
	if (value < root->data)		//插入的值比结点值小
	{
		InsertAVL(root->lchild, value);
		updateHeight(root);
		L_Check(root);
		return TRUE;
	}
	else						//插入的值比结点值大
	{
		InsertAVL(root->rchild, value);
		updateHeight(root);
		R_Check(root);
		return TRUE;
	}
}

BBSTree CreateAVL(ElemType* data,int n)
{
	BBSTree root = nullptr;
	for (int i = 0; i < n; i++)
	{
		InsertAVL(root, data[i]);
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
		if (now->lchild != nullptr)
		{
			q.push(now->lchild);
		}
		if (now->rchild != nullptr)
		{
			q.push(now->rchild);
		}
	}
}


int main()
{
	BBSTree test1 = nullptr;
	int num = 8;
	int arr[10] = { 1,2,3,4,5,6,7,8 };
	test1 = CreateAVL(arr, 8);
	LayerOrder(test1);
	return TRUE;
}