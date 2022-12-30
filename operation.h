#include "general.h"
#pragma once
//operationº¯ÊýÉùÃ÷
BBSTree newNode(RcdType value);
void DestroyBBSTree(BBSTree& root);
Status BBSTreeDepth(BBSTree T);
void CountLeaf(BBSTree T, RcdType& count);
BBSTree SearchAVL(BBSTree root, ElemType target);
Status ChangeNode(BBSTree& root, ElemType value1, ElemType value2);
BBSTree DeleteNode(BBSTree& root, RcdType value);
Status InsertNode(BBSTree& root, RcdType value);
BBSTree CreateAVL(LQueue &Q);
void LayerOrder(BBSTree root);
Status CopyBBSTree(BBSTree T, BBSTree& newT);
Status MergeBBSTree(BBSTree& T1, BBSTree& T2);
BBSTree SplitBBSTree(BBSTree& T, ElemType value);
void printTree(BBSTNode* treePtr);
Status PreOrderTraverse(BBSTree T, Status(*visit)(ElemType e));
Status InOrderTraverse(BBSTree T, Status(*visit)(ElemType e));
Status PostOrderTraverse(BBSTree T, Status(*visit)(ElemType e));
Status visit(int i);
void LayerOrder(BBSTree root);
Status BBSTreeDepth(BBSTree T);
void CountLeaf(BBSTree T, RcdType& count);