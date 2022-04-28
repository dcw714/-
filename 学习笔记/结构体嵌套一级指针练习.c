#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h> 

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW
#endif
#endif 

struct game
{
	char *name;
	int price;
};

struct game **allocateSpace()
{
	// �����ڴ�
	struct game **games = (struct game **)malloc(sizeof(struct game*) * 3);
	for (int i = 0; i < 3; i++)
	{
		games[i] = (struct game*)malloc(sizeof(struct game));
		games[i]->name = (char *)malloc(sizeof(char) * 64);
		// ��ֵ
		sprintf(games[i]->name, "�Ǽ�����%d", i + 1);
		games[i]->price = i + 17;
	}
	return games;
}

void printGame(struct game **games, int len)
{
	// ��ӡ
	for (int i = 0; i < len; i++)
	{
		printf("%s�ļ۸���%d$��\n", games[i]->name, games[i]->price);
	}
	return;
}

void freeSpace(struct game **games, int len)
{
	// �ͷ��ڴ�
	if (games == NULL || len <= 0) return;
	for (int i = 0; i < len; i++)// ���ڲ�������ͷţ���Ȼ������ڴ�й¶
	{
		if (games[i]->name != NULL)
		{
			free(games[i]->name);
			games[i]->name = NULL;
		}
		if (games[i] != NULL)
		{
			free(games[i]);
			games[i] = NULL;
		}
	}
	free(games);
	games = NULL;
}

void text_struct()
{
	struct game **games = NULL; // (struct game **)malloc(sizeof(struct game*));
	games = allocateSpace();//ֱ�����÷���ֵ���գ���Ȼ��������Ҫ����ָ�����
	printGame(games, 3);
	/*
	�����
	�Ǽ�����1�ļ۸���17$��
	�Ǽ�����2�ļ۸���18$��
	�Ǽ�����3�ļ۸���19$��
	*/
	freeSpace(games, 3);
	games = NULL; // ָ��Ŀռ��Ѿ����ͷţ���������Ȼָ���ǿ��ڴ�
	return;
}

int main_struct_primary_pointer(void)
// int main(void)
{
	text_struct();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}