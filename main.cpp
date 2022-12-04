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

BBSTree SearchAVL(BBSTree root, ElemType target)
{
	if (root == nullptr)
		return FALSE;
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
	BBSTree r_temp = root->rchild;	//r_temp指向root结点的右孩子
	root->rchild = r_temp->lchild;	//root的右子树置为r_temp的左子树
	r_temp->lchild = root;			//将root结点(原先的根节点)置为r_temp结点的左孩子
	updateHeight(root);
	updateHeight(r_temp);
	root = r_temp;					//root指向新的根节点
}

void R_Rotate(BBSTree& root)
{
	BBSTree l_temp = root->rchild;	//l_temp指向root结点的左孩子
	root->rchild = l_temp->lchild;	//root的左子树置为l_temp的右子树
	l_temp->lchild = root;			//将root结点(原先的根节点)置为l_temp结点的右孩子
	updateHeight(root);
	updateHeight(l_temp);
	root = l_temp;					//root指向新的根节点
}