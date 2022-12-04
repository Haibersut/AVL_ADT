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
	int bf;			//ƽ������
	int height;		//���߶ȣ����ڼ���ƽ������
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

Status getHeight(BBSTree root)		//��õ�ǰ���߶�
{
	if (root == nullptr)
		return 0;
	return root->height;
}

Status getBalanceFactor(BBSTree &root)		//����ƽ������
{
	root->bf = getHeight(root->lchild) - getHeight(root->rchild);
	return TRUE;
}

void updateHeight(BBSTree& root)		//���½��߶�
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
	BBSTree r_temp = root->rchild;	//r_tempָ��root�����Һ���
	root->rchild = r_temp->lchild;	//root����������Ϊr_temp��������
	r_temp->lchild = root;			//��root���(ԭ�ȵĸ��ڵ�)��Ϊr_temp��������
	updateHeight(root);
	updateHeight(r_temp);
	root = r_temp;					//rootָ���µĸ��ڵ�
}

void R_Rotate(BBSTree& root)
{
	BBSTree l_temp = root->rchild;	//l_tempָ��root��������
	root->rchild = l_temp->lchild;	//root����������Ϊl_temp��������
	l_temp->lchild = root;			//��root���(ԭ�ȵĸ��ڵ�)��Ϊl_temp�����Һ���
	updateHeight(root);
	updateHeight(l_temp);
	root = l_temp;					//rootָ���µĸ��ڵ�
}