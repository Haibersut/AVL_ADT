#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
#define ElemType int
typedef int Status;
typedef int RcdType;
typedef struct BBSTNode {
	RcdType data;
	int bf;			//平衡因子
	int height;		//结点高度，用于计算平衡因子
	struct BBSTNode* lchild, * rchild;
}*BBSTree;

Status InitAVL(BBSTree &root, RcdType value)
{
	BBSTree Node = new BBSTNode();
	if (Node == nullptr)
		return OVERFLOW;
	Node->data = value;
	Node->bf = 0;
	Node->height = 1;
	Node->lchild = Node->rchild = nullptr;
	return TRUE;
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
	return TRUE;
}

void updateHeight(BBSTree& root)		//更新结点高度
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

BBSTree Searchroot(BBSTree root, ElemType target)
{
	if (root == nullptr)
		return FALSE;
	if (target == root->data)
	{
		return root;
	}
	if (target < root->data)
	{
		return Searchroot(root->lchild, target);
	}
	return Searchroot(root->rchild, target);
}
