#include "general.h"
#pragma once

//queueº¯ÊýÉùÃ÷
Status EnQueue_LQ(LQueue& Q, ElemType e);
Status DeQueue_LQ(LQueue& Q, ElemType& e);
Status QueueEmpty_LQ(LQueue Q);
void InitQueue_LQ(LQueue& Q);
