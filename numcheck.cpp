#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GeneralCheck(int& value, int range)
{
	int judge = 0;
	rewind(stdin);			//刷新缓冲区
	scanf("%d", &value);
	judge = getchar();
	while (judge != 10)
	{
		rewind(stdin);
	TAG:printf("\033[31m数据不合规，请重新输入\033[0m\n");
		printf("请选择:");
		scanf("%d", &value);
		judge = getchar();
	}
	if (value<0 || value>range || value == 0)
	{
		goto TAG;
	}
}

int numcheck(void)			//通用类型错误检查
{
	int judge = 0;
	int value = 0;
	rewind(stdin);			//刷新缓冲区
	scanf("%d", &value);
	judge = getchar();
	while (judge != 10)
	{
		rewind(stdin);
	TAG:printf("\033[31m数据不合规，请重新输入\033[0m\n");
		printf("请选择:");
		scanf("%d", &value);
		judge = getchar();
	}
	if (value == 0)
	{
		goto TAG;
	}
	return value;
}