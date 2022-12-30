#include <stdio.h>
#include <stdlib.h>
#include "general.h"

void InitQueue_LQ(LQueue& Q)
{
	Q.front = NULL;
	Q.rear = NULL;
}

Status QueueEmpty_LQ(LQueue Q)
{
	return Q.front == NULL && Q.rear == NULL;
}

Status EnQueue_LQ(LQueue& Q, ElemType e)
{
	LQNode* p = NULL;
	p = (LQNode*)malloc(sizeof(LQNode));
	if (p == NULL)
	{
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	if (Q.front == NULL)
	{
		Q.front = p;
	}
	else
	{
		Q.rear->next = p;
	}
	Q.rear = p;
	return TRUE;
}

Status DeQueue_LQ(LQueue& Q, ElemType &e)
{
	LQNode* p = NULL;
	if (Q.front == NULL)
	{
		return FALSE;
	}
	p = Q.front;
	e = p->data;
	Q.front = p->next;
	if (Q.rear == p)
	{
		Q.rear = NULL;
	}
	free(p);
	return TRUE;
}