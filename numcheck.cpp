#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GeneralCheck(int& value, int range)
{
	int judge = 0;
	rewind(stdin);			//ˢ�»�����
	scanf("%d", &value);
	judge = getchar();
	while (judge != 10)
	{
		rewind(stdin);
	TAG:printf("\033[31m���ݲ��Ϲ棬����������\033[0m\n");
		printf("��ѡ��:");
		scanf("%d", &value);
		judge = getchar();
	}
	if (value<0 || value>range || value == 0)
	{
		goto TAG;
	}
}

int numcheck(void)			//ͨ�����ʹ�����
{
	int judge = 0;
	int value = 0;
	rewind(stdin);			//ˢ�»�����
	scanf("%d", &value);
	judge = getchar();
	while (judge != 10)
	{
		rewind(stdin);
	TAG:printf("\033[31m���ݲ��Ϲ棬����������\033[0m\n");
		printf("��ѡ��:");
		scanf("%d", &value);
		judge = getchar();
	}
	if (value == 0)
	{
		goto TAG;
	}
	return value;
}