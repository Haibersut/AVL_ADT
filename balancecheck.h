#include "general.h"
#pragma once
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