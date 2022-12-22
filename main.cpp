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
	int bf;			//ƽ������
	int height;		//���߶ȣ����ڼ���ƽ������
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

Status getHeight(BBSTree root)		//��õ�ǰ���߶�
{
	if (root == nullptr)
		return 0;
	return root->height;
}

Status getBalanceFactor(BBSTree &root)		//����ƽ������
{
	root->bf = getHeight(root->lchild) - getHeight(root->rchild);
	return root->bf;
}

void updateHeight(BBSTree& root)		//���½��߶�
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
	BBSTree rc = root->rchild;	//rcָ��root�����Һ���
	root->rchild = rc->lchild;	//��rc����������Ϊroot��������
	rc->lchild = root;			//��root(ԭ�ȵĸ��ڵ�)��Ϊrc��������
	updateHeight(root);
	updateHeight(rc);
	root = rc;					//rootָ���µĸ��ڵ�rc
}

void R_Rotate(BBSTree& root)
{
	BBSTree lc = root->rchild;	//lcָ��root��������
	root->rchild = lc->lchild;	//��lc����������Ϊroot��������
	lc->lchild = root;			//��root(ԭ�ȵĸ��ڵ�)��Ϊlc��������
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
	if (value < root->data)		//�����ֵ�Ƚ��ֵС
	{
		InsertAVL(root->lchild, value);
		updateHeight(root);
		L_Check(root);
		return TRUE;
	}
	else						//�����ֵ�Ƚ��ֵ��
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